(* re2ocaml $INPUT -o $OUTPUT *)

open String

type state = {
    yyinput: string;
    mutable yycursor: int;
    mutable yymarker: int;
    %{stags format = "\n\tmutable @@{tag}: int;"; %}
    mutable t1: int;
    mutable t2: int;
    %{mtags format = "\n\tmutable @@{tag}: int list;"; %}
    mutable t3: int list;
    mutable t4: int list;
}

let s2n (str: string) (i1: int) (i2: int) : int =
    let rec f s i j n =
        if i >= j then n else f s (i + 1) j (n * 10 + Char.code s.[i] - 48)
    in f str i1 i2 0

%{local
    re2c:define:YYFN = ["parse;(int list) option", "st;state"];
    re2c:define:YYMTAGP = "@@ <- st.yycursor :: @@;";
    re2c:define:YYMTAGN = ""; // alternatively could add `-1` to the list
    re2c:variable:yyrecord = "st";
    re2c:tags = 1;
    re2c:yyfill:enable = 0;

    num = [0-9]+;

    @t1 num @t2 ("." #t3 num #t4)* [\x00] {
        let x = s2n st.yyinput st.t1 st.t2 in
        let xs = List.rev (List.map2 (fun x y -> s2n st.yyinput x y) st.t3 st.t4) in
        Some (x :: xs)
    }
    * { None }
%}

let test (str: string) (result: (int list) option) =
    let st = {
        yyinput = str;
        yycursor = 0;
        yymarker = 0;
        %{stags format = "\n\t\t@@{tag} = -1;"; %}
        t1 = -1;
        t2 = -1;
        %{mtags format = "\n\t\t@@{tag} = [];"; %}
        t3 = [];
        t4 = [];
    }
    in if not (parse st = result) then raise (Failure "error")

let main () =
    test "1\x00" (Some [1]);
    test "1.2.3.4.5.6.7\x00" (Some [1; 2; 3; 4; 5; 6; 7;]);
    test "1.2.\x00" None

let _ = main ()
