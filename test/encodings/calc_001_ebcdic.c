/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -dei
/* re2c lesson 001_upn_calculator, calc_001, (c) M. Boerger 2006 - 2007 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scan(char *s, int l)
{
	char *p = s;
	char *q = 0;
#define YYCTYPE         char
#define YYCURSOR        p
#define YYLIMIT         (s+l)
#define YYMARKER        q
#define YYFILL(n)
	
	for(;;)
	{

		{
			YYCTYPE yych;
			if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
			yych = *YYCURSOR;
			YYDEBUG(0, yych);
			switch (yych) {
				case 0x00: goto yy1;
				case 0x4E: goto yy3;
				case 0x60: goto yy4;
				case 0xF0: goto yy5;
				case 0xF1:
				case 0xF2:
				case 0xF3:
				case 0xF4:
				case 0xF5:
				case 0xF6:
				case 0xF7:
				case 0xF8:
				case 0xF9: goto yy7;
				default: goto yy2;
			}
yy1:
			YYDEBUG(1, yych);
			++YYCURSOR;
			{ printf("EOF\n");	return 0; }
yy2:
			YYDEBUG(2, yych);
			++YYCURSOR;
			{ printf("ERR\n");	return 1; }
yy3:
			YYDEBUG(3, yych);
			++YYCURSOR;
			{ printf("+\n");	continue; }
yy4:
			YYDEBUG(4, yych);
			++YYCURSOR;
			{ printf("-\n");	continue; }
yy5:
			YYDEBUG(5, yych);
			yych = *++YYCURSOR;
			switch (yych) {
				case 0xF0:
				case 0xF1:
				case 0xF2:
				case 0xF3:
				case 0xF4:
				case 0xF5:
				case 0xF6:
				case 0xF7:
				case 0xF8:
				case 0xF9: goto yy9;
				default: goto yy6;
			}
yy6:
			YYDEBUG(6, yych);
			{ printf("Num\n");	continue; }
yy7:
			YYDEBUG(7, yych);
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			switch (yych) {
				case 0xF0:
				case 0xF1:
				case 0xF2:
				case 0xF3:
				case 0xF4:
				case 0xF5:
				case 0xF6:
				case 0xF7:
				case 0xF8:
				case 0xF9: goto yy7;
				default: goto yy8;
			}
yy8:
			YYDEBUG(8, yych);
			{ printf("Num\n");	continue; }
yy9:
			YYDEBUG(9, yych);
			++YYCURSOR;
			if (YYLIMIT <= YYCURSOR) YYFILL(1);
			yych = *YYCURSOR;
			switch (yych) {
				case 0xF0:
				case 0xF1:
				case 0xF2:
				case 0xF3:
				case 0xF4:
				case 0xF5:
				case 0xF6:
				case 0xF7:
				case 0xF8:
				case 0xF9: goto yy9;
				default: goto yy10;
			}
yy10:
			YYDEBUG(10, yych);
			{ printf("Oct\n");	continue; }
		}

	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		return scan(argv[1], strlen(argv[1]));
	}
	else
	{
		fprintf(stderr, "%s <expr>\n", argv[0]);
		return 1;
	}
}
