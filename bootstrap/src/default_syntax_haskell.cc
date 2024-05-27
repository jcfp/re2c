#include "src/parse/conf_parser.h"
const char* DEFAULT_SYNTAX_HASKELL =
    "supported_apis = [\"generic\"];\n"
    "supported_api_styles = [\"free-form\"];\n"
    "supported_code_models = [\"recursive_functions\"];\n"
    "supported_targets = [\"code\", \"dot\"];\n"
    "supported_features = [\"nested_ifs\", \"monadic\"];\n"
    "\n"
    "semicolons = 1;\n"
    "//semicolons = 0;\n"
    "implicit_bool_conversion = 0;\n"
    "backtick_quoted_strings = 0;\n"
    "standalone_single_quotes = 1; // TODO: what about identifiers?\n"
    "indentation_sensitive = 1;\n"
    "wrap_blocks_in_braces = 0;\n"
    "\n"
    "conf:api = custom;\n"
    "conf:api:style = free-form;\n"
    "conf:api:sigil = \"@@\";\n"
    "conf:header = \"\";\n"
    "conf:eof = -1;\n"
    "conf:sentinel = -1;\n"
    "conf:yyfill:enable = 1;\n"
    "conf:yyfill:parameter = 1;\n"
    "conf:yyfill:check = 1;\n"
    "conf:tags = 0;\n"
    "conf:leftmost-captures = 0;\n"
    "conf:posix-captures = 0;\n"
    "conf:tags:prefix = \"yyt\";\n"
    "conf:tags:expression = \"@@\";\n"
    "conf:invert-captures = 0;\n"
    "conf:define:YYBACKUP = \"YYBACKUP\";\n"
    "conf:define:YYBACKUPCTX = \"YYBACKUPCTX\";\n"
    "conf:define:YYCONDTYPE = \"YYCONDTYPE\";\n"
    "conf:define:YYCOPYMTAG = \"YYCOPYMTAG\";\n"
    "conf:define:YYCOPYSTAG = \"YYCOPYSTAG\";\n"
    "conf:define:YYCTYPE = \"yyctype\";\n"
    "conf:define:YYCTXMARKER = \"YYCTXMARKER\";\n"
    "conf:define:YYCURSOR = \"YYCURSOR\";\n"
    "conf:define:YYDEBUG = \"YYDEBUG\";\n"
    "conf:define:YYFILL = \"YYFILL\";\n"
    "conf:define:YYFILL@len = \"@@\";\n"
    "conf:define:YYFILL:naked = 0;\n"
    "conf:define:YYGETACCEPT = \"GETACCEPT\";\n"
    "conf:define:YYGETCOND = \"YYGETCOND\";\n"
    "conf:define:YYGETCOND:naked = 0;\n"
    "conf:define:YYGETSTATE = \"YYGETSTATE\";\n"
    "conf:define:YYGETSTATE:naked = 0;\n"
    "conf:define:YYLESSTHAN = \"YYLESSTHAN\";\n"
    "conf:define:YYLIMIT = \"YYLIMIT\";\n"
    "conf:define:YYMARKER = \"YYMARKER\";\n"
    "conf:define:YYMAXFILL = \"yymaxfill\";\n"
    "conf:define:YYMAXNMATCH = \"yymaxnmatch\";\n"
    "conf:define:YYMTAGN = \"YYMTAGN\";\n"
    "conf:define:YYMTAGP = \"YYMTAGP\";\n"
    "conf:define:YYPEEK = \"YYPEEK\";\n"
    "conf:define:YYRESTORE = \"YYRESTORE\";\n"
    "conf:define:YYRESTORECTX = \"YYRESTORECTX\";\n"
    "conf:define:YYRESTORETAG = \"YYRESTORETAG\";\n"
    "conf:define:YYSETACCEPT = \"SETACCEPT\";\n"
    "conf:define:YYSETCOND = \"YYSETCOND\";\n"
    "conf:define:YYSETCOND@cond = \"@@\";\n"
    "conf:define:YYSETCOND:naked = 0;\n"
    "conf:define:YYSETSTATE = \"YYSETSTATE\";\n"
    "conf:define:YYSETSTATE:naked = 0;\n"
    "conf:define:YYSETSTATE@state = \"@@\";\n"
    "conf:define:YYSHIFT = \"YYSHIFT\";\n"
    "conf:define:YYSHIFTSTAG = \"YYSHIFTSTAG\";\n"
    "conf:define:YYSHIFTMTAG = \"YYSHIFTMTAG\";\n"
    "conf:define:YYSKIP = \"YYSKIP\";\n"
    "conf:define:YYSTAGN = \"YYSTAGN\";\n"
    "conf:define:YYSTAGP = \"YYSTAGP\";\n"
    "conf:define:YYFN = [\"<undefined-function-name>;<undefined-function-type>\"];\n"
    "conf:yyfn:sep = \";\";\n"
    "conf:variable:yyctable = \"yyctable\";\n"
    "conf:variable:yyaccept = \"yyaccept\";\n"
    "conf:variable:yytarget = \"yytarget\";\n"
    "conf:variable:yystate = \"yystate\";\n"
    "conf:variable:yynmatch = \"\"; // no array for `yypmatch` in Haskell => no need for `yynmatch`\n"
    "conf:variable:yypmatch = \"yypmatch\";\n"
    "conf:variable:yych = \"yych\";\n"
    "conf:variable:yych:conversion = 0;\n"
    "conf:variable:yych:literals = hex;\n"
    "conf:variable:yych:emit = (code_model.recursive_functions ? 0 : 1);\n"
    "conf:variable:yybm = \"yybm\";\n"
    "conf:variable:yybm:hex = 0;\n"
    "conf:variable:yyfill = \"yyfill\";\n"
    "conf:variable:yystable = \"\"; // deprecated\n"
    "conf:cond:abort = 1;\n"
    "conf:cond:prefix = \"yyc_\";\n"
    "conf:cond:enumprefix = \"YYC_\";\n"
    "conf:cond:divider = \"(* *********************************** *)\";\n"
    "conf:cond:divider@cond = \"@@\";\n"
    "conf:cond:goto = \"\";\n"
    "conf:cond:goto@cond = \"@@\";\n"
    "conf:state:abort = 1;\n"
    "conf:state:nextlabel = 0;\n"
    "conf:bit-vectors = 0;\n"
    "conf:debug-output = 0;\n"
    "conf:computed-gotos = 0;\n"
    "conf:computed-gotos:threshold = 9;\n"
    "conf:nested-ifs = 0;\n"
    "conf:case-insensitive = 0;\n"
    "conf:case-inverted = 0;\n"
    "conf:case-ranges = 0;\n"
    "conf:unsafe = 0;\n"
    "conf:monadic = 0;\n"
    "conf:encoding:ebcdic = 0;\n"
    "conf:encoding:utf32 = 0;\n"
    "conf:encoding:ucs2 = 0;\n"
    "conf:encoding:utf16 = 0;\n"
    "conf:encoding:utf8 = 0;\n"
    "conf:encoding-policy = ignore;\n"
    "conf:empty-class = match-empty;\n"
    "conf:indent:string = \"    \";\n"
    "conf:indent:top = 0;\n"
    "conf:label:prefix = \"yy\";\n"
    "conf:label:yyfill = \"yyFillLabel\";\n"
    "conf:label:yyloop = \"\";\n"
    "conf:label:yyNext = \"yyNext\";\n"
    "conf:label:start = 0;\n"
    "\n"
    "code:var_local = topindent \"let \" name \" = \" init \" in\" nl;\n"
    "code:var_global = topindent \"let \" name \" = \" init nl;\n"
    "\n"
    "code:const_local = topindent \"let \" name \" = \" init \" in\" nl;\n"
    "code:const_global = topindent name \" = \" init nl;\n"
    "\n"
    "// code:array_local\n"
    "// code:array_global\n"
    "\n"
    "// `code:array_elem` is used to generate operations on POSIX `yypmatch` array.\n"
    "// Override it to generate an identifier instead, as mutable arrays are non-idiomatic in Haskell.\n"
    "code:array_elem = array index;\n"
    "\n"
    "code:type_int = \"int\";\n"
    "code:type_uint = \"uint\";\n"
    "code:type_cond_enum = (storable_state? \"int\" : \"uint\");\n"
    "// code:type_yybm\n"
    "// code:type_yytarget\n"
    "\n"
    "// code:assign\n"
    "\n"
    "code:if_then_else =\n"
    "    [branch{0}: topindent (multival ? \"if \" cond \" then\" : \"when (\" cond \") $\") (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent]\n"
    "    [branch{1:-1}: topindent \"else\" (have_cond? \" if \" cond \" then\") (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent];\n"
    "\n"
    "code:if_then_else_oneline =\n"
    "    [branch{0}: topindent (multival ? \"if \" cond \" then \" : \"when (\" cond \") $ \") [stmt: stmt] nl]\n"
    "    [branch{1:-1}: topindent \"else \" (have_cond? \"if \" cond \" then \") [stmt: stmt] nl];\n"
    "\n"
    "code:switch =\n"
    "    topindent \"case \" expr \" of\" nl\n"
    "        indent [case: case] dedent;\n"
    "\n"
    "code:switch_cases = topindent \"_c | \"\n"
    "    [case{0:-2}: case \" || \"]\n"
    "    [case{-1}:   case \" ->\" (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent\n"
    "    ];\n"
    "\n"
    "code:switch_case_range = (multival\n"
    "    ? [val{0}: val] \" <= _c && _c <= \" [val{-1}: val]\n"
    "    : [val{0}: val] \" == _c\");\n"
    "\n"
    "code:switch_case_default = \"True\";\n"
    "\n"
    "code:enum =\n"
    "    \"data \" name \" = \"\n"
    "        [elem{0:-2}: elem \" | \"]\n"
    "        [elem{-1}: elem] \" deriving (Eq, Show)\"\n"
    "    nl;\n"
    "\n"
    "code:enum_elem = name;\n"
    "\n"
    "code:fndef =\n"
    "    name \" :: \" [arg: argtype \" -> \"] type nl\n"
    "    name [arg: \" \" argname] \" =\" (monadic ? \" do\") nl\n"
    "        indent [stmt: stmt] dedent;\n"
    "\n"
    "code:fncall =\n"
    "    topindent (have_retval ? \"let \" retval \" = \")\n"
    "        name (have_args ? [arg: \" \" arg] : \" ()\") nl;\n"
    "\n"
    "code:tailcall = topindent name (have_args ? [arg: \" \" arg] : \" ()\") nl;\n"
    "\n"
    "code:recursive_functions = [fn: fndef nl];\n"
    "\n"
    "code:fingerprint = \"-- Generated by re2c\" (version? \" \" version) (date? \" on \" date) nl;\n"
    "\n"
    "code:line_info = \"#\" line \" \\\"\" file \"\\\"\" nl;\n"
    "\n"
    "code:abort = topindent \"error \\\"internal lexer error\\\"\" nl;\n"
    "\n"
    "code:yydebug = topindent debug nl;\n"
    "\n"
    "code:yypeek = (monadic\n"
    "    ? topindent char \" <- \" peek nl\n"
    "    : topindent \"let \" char \" = \" peek \" in\" nl);\n"
    "\n"
    "code:yyskip = topindent skip nl;\n"
    "\n"
    "code:yybackup = topindent backup nl;\n"
    "\n"
    "code:yybackupctx = topindent backupctx nl;\n"
    "\n"
    "code:yyrestore = topindent restore nl;\n"
    "\n"
    "code:yyrestorectx = topindent restorectx nl;\n"
    "\n"
    "code:yyrestoretag = topindent restoretag nl;\n"
    "\n"
    "code:yyshift = topindent shift nl;\n"
    "\n"
    "code:yyshiftstag = topindent shiftstag nl;\n"
    "\n"
    "code:yyshiftmtag = topindent shiftmtag nl;\n"
    "\n"
    "code:yystagp = topindent stagp nl;\n"
    "\n"
    "code:yymtagp = topindent mtagp nl;\n"
    "\n"
    "code:yystagn = topindent stagn nl;\n"
    "\n"
    "code:yymtagn = topindent mtagn nl;\n"
    "\n"
    "code:yycopystag = topindent copystag nl;\n"
    "\n"
    "code:yycopymtag = topindent copymtag nl;\n"
    "\n"
    "code:yygetaccept = getaccept;\n"
    "\n"
    "code:yysetaccept = topindent setaccept nl;\n"
    ;
