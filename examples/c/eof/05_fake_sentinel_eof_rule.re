// re2c $INPUT -o $OUTPUT
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int lex(const char *str, unsigned int len) {
    // For the sake of example create a string without terminating null.
    char *buf = (char*) malloc(len);
    memcpy(buf, str, len);

    const char *cur = buf, *lim = buf + len, *mar;
    int count = 0;

    for (;;) {
    /*!re2c
        re2c:yyfill:enable = 0;
        re2c:eof = 0;
        re2c:api = generic;
        re2c:api:style = free-form;
        re2c:YYCTYPE = char;
        re2c:YYLESSTHAN = "cur >= lim";
        re2c:YYPEEK = "cur < lim ? *cur : 0";  // fake null
        re2c:YYSKIP = "++cur;";
        re2c:YYBACKUP = "mar = cur;";
        re2c:YYRESTORE = "cur = mar;";

        str = ['] ([^'\\] | [\\][^])* ['];

        *    { count = -1; break; }
        $    { break;; }
        str  { ++count; continue; }
        [ ]+ { continue; }
    */
    }

    free(buf);
    return count;
}

#define TEST(s, r) assert(lex(s, sizeof(s) - 1) == r)
int main() {
    TEST("", 0);
    TEST("'qu\0tes' 'are' 'fine: \\'' ", 3);
    TEST("'unterminated\\'", -1);
    return 0;
}
