/* Generated by re2c */

{
	YYCTYPE yych;
	if ((YYLIMIT - YYCURSOR) < 3) YYFILL(3);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
yy2:
	{}
yy3:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':	goto yy5;
	default:
		yyt1 = YYCURSOR;
		goto yy4;
	}
yy4:
	t = yyt1;
	{}
yy5:
	yych = *++YYCURSOR;
	yyt1 = YYCURSOR - 1;
	switch (yych) {
	case 'b':	goto yy6;
	default:	goto yy4;
	}
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy6;
	default:	goto yy4;
	}
}

stadfa/stadfa_01.i--tags--stadfa.re:3:3: warning: rule matches empty string [-Wmatch-empty-string]
