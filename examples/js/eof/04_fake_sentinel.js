// Generated by re2js
// re2js $INPUT -o $OUTPUT

// expects a string without terminating null
function lex(str) {
    let cur = 0;
    let lim = str.length
    let count = 0

    loop: while (true) {
    
{
    let yych = 0
    let yystate = 0
    yyl: while (true) {
        switch (yystate) {
            case 0:
                yych = cur < lim ? str.charCodeAt(cur) : 0
                cur += 1
                switch (yych) {
                    case 0x00:
                        yystate = 1
                        continue yyl
                    case 0x20:
                        yystate = 3
                        continue yyl
                    case 0x61:
                    case 0x62:
                    case 0x63:
                    case 0x64:
                    case 0x65:
                    case 0x66:
                    case 0x67:
                    case 0x68:
                    case 0x69:
                    case 0x6A:
                    case 0x6B:
                    case 0x6C:
                    case 0x6D:
                    case 0x6E:
                    case 0x6F:
                    case 0x70:
                    case 0x71:
                    case 0x72:
                    case 0x73:
                    case 0x74:
                    case 0x75:
                    case 0x76:
                    case 0x77:
                    case 0x78:
                    case 0x79:
                    case 0x7A:
                        yystate = 5
                        continue yyl
                    default:
                        yystate = 2
                        continue yyl
                }
            case 1:
                { return count }
            case 2:
                { return -1 }
            case 3:
                yych = cur < lim ? str.charCodeAt(cur) : 0
                switch (yych) {
                    case 0x20:
                        cur += 1
                        yystate = 3
                        continue yyl
                    default:
                        yystate = 4
                        continue yyl
                }
            case 4:
                { continue loop }
            case 5:
                yych = cur < lim ? str.charCodeAt(cur) : 0
                switch (yych) {
                    case 0x61:
                    case 0x62:
                    case 0x63:
                    case 0x64:
                    case 0x65:
                    case 0x66:
                    case 0x67:
                    case 0x68:
                    case 0x69:
                    case 0x6A:
                    case 0x6B:
                    case 0x6C:
                    case 0x6D:
                    case 0x6E:
                    case 0x6F:
                    case 0x70:
                    case 0x71:
                    case 0x72:
                    case 0x73:
                    case 0x74:
                    case 0x75:
                    case 0x76:
                    case 0x77:
                    case 0x78:
                    case 0x79:
                    case 0x7A:
                        cur += 1
                        yystate = 5
                        continue yyl
                    default:
                        yystate = 6
                        continue yyl
                }
            case 6:
                { count += 1; continue loop }
            default:
                throw "internal lexer error"
        }
    }
}

    }
}

function test(s, n) { if (lex(s) != n) throw "error!"; }
test("", 0)
test("one two three", 3)
test("f0ur", -1)
