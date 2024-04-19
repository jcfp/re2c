(* Generated by re2c *)
(* re2ocaml $INPUT -o $OUTPUT -fi *)

(* Use a small buffer to cover the case when a lexeme doesn't fit.
   In real world use a larger buffer. *)
let bufsize = 10

let debug = false
let log format = (if debug then Printf.eprintf else Printf.ifprintf stderr) format

type state = {
    file: in_channel;
    buf: bytes;
    mutable cur: int;
    mutable mar: int;
    mutable tok: int;
    mutable lim: int;
    mutable state: int;
    mutable recv: int;
}

type status = End | Ready | Waiting | BadPacket | BigPacket

let fill(st: state) : status =
    (* Error: lexeme too long. In real life could reallocate a larger buffer. *)
    if st.tok < 1 then BigPacket else (

    (* Shift buffer contents (discard everything up to the current token). *)
    Bytes.blit st.buf st.tok st.buf 0 (st.lim - st.tok);
    st.cur <- st.cur - st.tok;
    st.mar <- st.mar - st.tok;
    st.lim <- st.lim - st.tok;
    st.tok <- 0;

    (* Fill free space at the end of buffer with new data from file. *)
    let n = In_channel.input st.file st.buf st.lim (bufsize - st.lim - 1) in (* -1 for sentinel *)
    st.lim <- st.lim + n;
    Bytes.set st.buf st.lim '\x00'; (* append sentinel *)

    Ready)


let rec yy0 (st : state) : status =
	let yych = Bytes.get st.buf st.cur in
	match yych with
		| 'a'..'z' ->
			st.cur <- st.cur + 1;
			(yy3 [@tailcall]) st
		| _ ->
			if (st.cur >= st.lim) then (
				st.state <- 0;
				Waiting
			) else (
				st.cur <- st.cur + 1;
				(yy1 [@tailcall]) st
			)

and yy1 (st : state) : status =
	(yy2 [@tailcall]) st

and yy2 (st : state) : status =
	st.state <- -1;
	BadPacket

and yy3 (st : state) : status =
	st.mar <- st.cur;
	let yych = Bytes.get st.buf st.cur in
	match yych with
		| ';' ->
			st.cur <- st.cur + 1;
			(yy4 [@tailcall]) st
		| 'a'..'z' ->
			st.cur <- st.cur + 1;
			(yy5 [@tailcall]) st
		| _ ->
			if (st.cur >= st.lim) then (
				st.state <- 1;
				Waiting
			) else (
				(yy2 [@tailcall]) st
			)

and yy4 (st : state) : status =
	st.state <- -1;
	st.recv <- st.recv + 1; lex_loop st

and yy5 (st : state) : status =
	let yych = Bytes.get st.buf st.cur in
	match yych with
		| ';' ->
			st.cur <- st.cur + 1;
			(yy4 [@tailcall]) st
		| 'a'..'z' ->
			st.cur <- st.cur + 1;
			(yy5 [@tailcall]) st
		| _ ->
			if (st.cur >= st.lim) then (
				st.state <- 2;
				Waiting
			) else (
				(yy6 [@tailcall]) st
			)

and yy6 (st : state) : status =
	st.cur <- st.mar;
	(yy2 [@tailcall]) st

and yy7 (st : state) : status =
	st.state <- -1;
	End

and lex (st : state) : status =
	match st.state with
		| -1 -> (yy0 [@tailcall]) st
		| 0 ->
			if (st.cur >= st.lim) then (yy7 [@tailcall]) st
			else (yy0 [@tailcall]) st
		| 1 ->
			if (st.cur >= st.lim) then (yy2 [@tailcall]) st
			else (yy3 [@tailcall]) st
		| 2 ->
			if (st.cur >= st.lim) then (yy6 [@tailcall]) st
			else (yy5 [@tailcall]) st
		| _ -> raise (Failure "internal lexer error")



and lex_loop st =
    st.tok <- st.cur;
    lex st

let test (packets: string list) (sts: status) =
    let fname = "pipe" in

    let oc = Out_channel.open_bin fname in
    let ic = In_channel.open_bin fname in

    let lim = bufsize - 1 in
    let st = {
        file = ic;
        (* Sentinel (at `lim` offset) is set to null, which triggers YYFILL. *)
        buf = Bytes.create bufsize;
        cur = lim;
        mar = lim;
        tok = lim;
        lim = lim;
        state = -1;
        recv = 0;
    } in

    let rec loop packets = match lex_loop st with
        | End ->
            log "done: got %d packets\n" st.recv;
            End
        | Waiting ->
            log "waiting...\n";
            let packets' = match packets with
                | [] -> []
                | p :: ps ->
                    log "sent packet '%s'\n" p;
                    Out_channel.output_string oc p;
                    Out_channel.flush oc; (* without `flush` write happens too late *)
                    ps
            in (match fill st with
                | BigPacket ->
                    log "error: packet too big\n";
                    BigPacket
                | Ready -> loop packets'
                | _ -> raise (Failure "unexpected status after fill"))
        | BadPacket ->
            log "error: ill-formed packet\n";
            BadPacket
        | _ -> raise (Failure "unexpected status")

    in if not (loop packets = sts) then
        raise (Failure "error");

    In_channel.close ic;
    Out_channel.close oc;
    Sys.remove fname

let main () =
    test [] End;
    test ["zero;"; "one;"; "two;"; "three;"; "four;"] End;
    test ["zer0;"] BadPacket;
    test ["goooooooooogle;"] BigPacket

let _ = main ()