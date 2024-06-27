/* Generated by re2c */
// re2d $INPUT -o $OUTPUT -i
module main;



private long lex_tags(const(char)* str) {
    const(char)* yycursor = str, yymarker, x, y;
    const(char)* yyt1;

    
{
	char yych;
	yych = *(yymarker = yycursor);
	switch (yych) {
		case 'b': goto yy2;
		default:
			yyt1 = null;
			goto yy1;
	}
yy1:
	y = yyt1;
	x = yyt1;
	if (x != null) x -= 1;
	{ return x == null ? -1 : (y - x); }
yy2:
	yych = *++yycursor;
	switch (yych) {
		case 'a': goto yy4;
		default: goto yy3;
	}
yy3:
	yycursor = yymarker;
	yyt1 = null;
	goto yy1;
yy4:
	++yycursor;
	yyt1 = yycursor;
	goto yy1;
}

}

enum YYMaxNMatch = 3;


private long lex_captures(const(char)* str) {
    const(char)* yycursor = str;
    uint yynmatch;
    const(char)*[2*YYMaxNMatch] yypmatch; 
    const(char)* yyt1;
const(char)* yyt2;

    
{
	char yych;
	yych = *yycursor;
	switch (yych) {
		case 'a':
			yyt1 = yycursor;
			goto yy7;
		default:
			yyt1 = yycursor;
			yyt2 = null;
			goto yy6;
	}
yy6:
	yynmatch = 3;
	yypmatch[0] = yyt1;
	yypmatch[3] = yyt2;
	yypmatch[5] = yyt2;
	yypmatch[1] = yycursor;
	yypmatch[2] = yyt2;
	if (yypmatch[2] != null) yypmatch[2] -= 1;
	yypmatch[4] = yypmatch[2];
	{ return yypmatch[4] == null ? -1 : yypmatch[4] - str; }
yy7:
	++yycursor;
	yyt2 = yycursor;
	goto yy6;
}

}

void main() {
    assert(lex_tags("") == -1);
    assert(lex_tags("ba") == 1);
    assert(lex_captures("") == -1);
    assert(lex_captures("a") == 0);
}
codegen/d/nested_fixed_tags.re:14:25: warning: rule matches empty string [-Wmatch-empty-string]
codegen/d/nested_fixed_tags.re:27:17: warning: rule matches empty string [-Wmatch-empty-string]