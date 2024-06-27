(* Generated by re2c *)
#1 "ocaml/submatch/01_stags_fill.re"
(* re2ocaml $INPUT -o $OUTPUT *)

open Bytes

let bufsize = 4096

type state = {
    file: in_channel;
    yyinput: bytes;
    mutable yycursor: int;
    mutable yymarker: int;
    mutable yylimit: int;
    mutable token: int;
    mutable eof: bool;
    mutable t1: int;
    mutable t2: int;
    mutable t3: int;
    mutable t4: int;
    mutable t5: int;
    
#24 "ocaml/submatch/01_stags_fill.ml"

	mutable yyt1: int;
	mutable yyt2: int;
	mutable yyt3: int;
	mutable yyt4: int;
#20 "ocaml/submatch/01_stags_fill.re"

}

type status = Ok | Eof | LongLexeme

type semver = {
    major: int;
    minor: int;
    patch: int;
}

let s2n (str: bytes) (i1: int) (i2: int) : int =
    let rec f s i j n =
        if i >= j then n else f s (i + 1) j (n * 10 + Char.code (get s i) - 48)
    in f str i1 i2 0

let fill(st: state) : status =
    if st.eof then Eof else

    (* Error: lexeme too long. In real life could reallocate a larger buffer. *)
    if st.token < 1 then LongLexeme else (

    (* Shift buffer contents (discard everything up to the current token). *)
    blit st.yyinput st.token st.yyinput 0 (st.yylimit - st.token);
    st.yycursor <- st.yycursor - st.token;
    st.yymarker <- st.yymarker - st.token;
    st.yylimit <- st.yylimit - st.token;
    
#59 "ocaml/submatch/01_stags_fill.ml"

	st.yyt1 <- if st.yyt1 = -1 then -1 else st.yyt1 - st.token;
	st.yyt2 <- if st.yyt2 = -1 then -1 else st.yyt2 - st.token;
	st.yyt3 <- if st.yyt3 = -1 then -1 else st.yyt3 - st.token;
	st.yyt4 <- if st.yyt4 = -1 then -1 else st.yyt4 - st.token;
#47 "ocaml/submatch/01_stags_fill.re"

    st.token <- 0;

    (* Fill free space at the end of buffer with new data from file. *)
    let n = input st.file st.yyinput st.yylimit (bufsize - st.yylimit - 1) in (* -1 for sentinel *)
    st.yylimit <- st.yylimit + n;
    if n = 0 then
        st.eof <- true; (* end of file *)
        set st.yyinput st.yylimit '\x00'; (* append sentinel *)

    Ok)


#79 "ocaml/submatch/01_stags_fill.ml"
let rec yy0 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '0'..'9' ->
			st.yyt1 <- st.yycursor;
			st.yycursor <- st.yycursor + 1;
			(yy3 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy0 [@tailcall]) st vers
				else (yy11 [@tailcall]) st vers
			) else (
				st.yycursor <- st.yycursor + 1;
				(yy1 [@tailcall]) st vers
			)

and yy1 (st : state) (vers : semver list) : (semver list) option =
	(yy2 [@tailcall]) st vers

and yy2 (st : state) (vers : semver list) : (semver list) option =
#76 "ocaml/submatch/01_stags_fill.re"
	None
#102 "ocaml/submatch/01_stags_fill.ml"

and yy3 (st : state) (vers : semver list) : (semver list) option =
	st.yymarker <- st.yycursor;
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '.' ->
			st.yycursor <- st.yycursor + 1;
			(yy4 [@tailcall]) st vers
		| '0'..'9' ->
			st.yycursor <- st.yycursor + 1;
			(yy6 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy3 [@tailcall]) st vers
				else (yy2 [@tailcall]) st vers
			) else (
				(yy2 [@tailcall]) st vers
			)

and yy4 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '0'..'9' ->
			st.yyt2 <- st.yycursor;
			st.yycursor <- st.yycursor + 1;
			(yy7 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy4 [@tailcall]) st vers
				else (yy5 [@tailcall]) st vers
			) else (
				(yy5 [@tailcall]) st vers
			)

and yy5 (st : state) (vers : semver list) : (semver list) option =
	st.yycursor <- st.yymarker;
	(yy2 [@tailcall]) st vers

and yy6 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '.' ->
			st.yycursor <- st.yycursor + 1;
			(yy4 [@tailcall]) st vers
		| '0'..'9' ->
			st.yycursor <- st.yycursor + 1;
			(yy6 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy6 [@tailcall]) st vers
				else (yy5 [@tailcall]) st vers
			) else (
				(yy5 [@tailcall]) st vers
			)

and yy7 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '\n' ->
			st.yyt3 <- st.yycursor;
			st.yyt4 <- -1;
			st.yycursor <- st.yycursor + 1;
			(yy8 [@tailcall]) st vers
		| '.' ->
			st.yyt3 <- st.yycursor;
			st.yycursor <- st.yycursor + 1;
			(yy9 [@tailcall]) st vers
		| '0'..'9' ->
			st.yycursor <- st.yycursor + 1;
			(yy7 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy7 [@tailcall]) st vers
				else (yy5 [@tailcall]) st vers
			) else (
				(yy5 [@tailcall]) st vers
			)

and yy8 (st : state) (vers : semver list) : (semver list) option =
	st.t1 <- st.yyt1;
	st.t3 <- st.yyt2;
	st.t4 <- st.yyt3;
	st.t5 <- st.yyt4;
	st.t2 <- st.yyt2;
	st.t2 <- st.t2 - 1;
#68 "ocaml/submatch/01_stags_fill.re"
	
        let ver = {
            major = s2n st.yyinput st.t1 st.t2;
            minor = s2n st.yyinput st.t3 st.t4;
            patch = if st.t5 = -1 then 0 else s2n st.yyinput st.t5 (st.yycursor - 1)
        } in lex_loop st (ver :: vers)

#196 "ocaml/submatch/01_stags_fill.ml"

and yy9 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '0'..'9' ->
			st.yyt4 <- st.yycursor;
			st.yycursor <- st.yycursor + 1;
			(yy10 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy9 [@tailcall]) st vers
				else (yy5 [@tailcall]) st vers
			) else (
				(yy5 [@tailcall]) st vers
			)

and yy10 (st : state) (vers : semver list) : (semver list) option =
	let yych = get st.yyinput st.yycursor in
	match yych with
		| '\n' ->
			st.yycursor <- st.yycursor + 1;
			(yy8 [@tailcall]) st vers
		| '0'..'9' ->
			st.yycursor <- st.yycursor + 1;
			(yy10 [@tailcall]) st vers
		| _ ->
			if (st.yylimit <= st.yycursor) then (
				if (fill st = Ok) then (yy10 [@tailcall]) st vers
				else (yy5 [@tailcall]) st vers
			) else (
				(yy5 [@tailcall]) st vers
			)

and yy11 (st : state) (vers : semver list) : (semver list) option =
#75 "ocaml/submatch/01_stags_fill.re"
	Some (List.rev vers)
#233 "ocaml/submatch/01_stags_fill.ml"

and lex (st : state) (vers : semver list) : (semver list) option =
	(yy0 [@tailcall]) st vers

#77 "ocaml/submatch/01_stags_fill.re"


and lex_loop st vers =
    st.token <- st.yycursor;
    lex st vers

let main () =
    let fname = "input" in

    (* Prepare input file. *)
    Out_channel.with_open_bin fname
        (fun oc -> for i = 1 to bufsize do
            output_string oc "1.22.333\n"
        done);

    (* Construct the expected result to compare against. *)
    let expect = Some (List.init bufsize
            (fun _ -> {major = 1; minor = 22; patch = 333;})) in

    (* Run lexer on the prepared file. *)
    In_channel.with_open_bin fname
        (fun ic ->
            let yylimit = bufsize - 1 in
            let st = {
                file = ic;
                yyinput = create bufsize;
                yycursor = yylimit;
                yymarker = yylimit;
                yylimit = yylimit;
                token = yylimit;
                eof = false;
                t1 = -1;
                t2 = -1;
                t3 = -1;
                t4 = -1;
                t5 = -1;
                
#276 "ocaml/submatch/01_stags_fill.ml"

		yyt1 = -1;
		yyt2 = -1;
		yyt3 = -1;
		yyt4 = -1;
#113 "ocaml/submatch/01_stags_fill.re"

            } in if (lex_loop st [] <> expect) then
                raise (Failure "error"));

    (* Cleanup. *)
    Sys.remove fname

let _ = main ()