/* Generated by re2c */

{
	YYCTYPE yych;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy3;
	default:
		yyt1 = NULL;
		goto yy2;
	}
yy2:
	t = yyt1;
	{}
yy3:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	yyt1 = YYCURSOR - 1;
	switch (yych) {
	case 'a':	goto yy3;
	default:	goto yy2;
	}
}

stadfa/stadfa_02.i--tags--stadfa.re:2:10: warning: rule matches empty string [-Wmatch-empty-string]
stadfa/stadfa_02.i--tags--stadfa.re:3:3: warning: rule matches empty string [-Wmatch-empty-string]
stadfa/stadfa_02.i--tags--stadfa.re:3:3: warning: unreachable rule (shadowed by rule at line 2) [-Wunreachable-rules]
