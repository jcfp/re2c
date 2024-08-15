// Generated by re2js
// re2js $INPUT -o $OUTPUT

const assert = require('assert');

function parse(yyinput) {
    let yycursor = 0

    // Final tag variables available in semantic action.
    let t1
let t2
let t3
let t4
let t5


    // Intermediate tag variables used by the lexer (must be autogenerated).
    let yyt1
let yyt2
let yyt3
let yyt4


    
{
    let yych = 0
    let yystate = 0
    yyl: while (true) {
        switch (yystate) {
            case 0:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yyt1 = yycursor;
                        yycursor += 1;
                        yystate = 3
                        continue yyl
                    default:
                        yycursor += 1;
                        yystate = 1
                        continue yyl
                }
            case 1:
                yystate = 2
                continue yyl
            case 2:
                { return null }
            case 3:
                yymarker = yycursor;
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x2E:
                        yycursor += 1;
                        yystate = 4
                        continue yyl
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yycursor += 1;
                        yystate = 6
                        continue yyl
                    default:
                        yystate = 2
                        continue yyl
                }
            case 4:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yyt2 = yycursor;
                        yycursor += 1;
                        yystate = 7
                        continue yyl
                    default:
                        yystate = 5
                        continue yyl
                }
            case 5:
                yycursor = yymarker;
                yystate = 2
                continue yyl
            case 6:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x2E:
                        yycursor += 1;
                        yystate = 4
                        continue yyl
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yycursor += 1;
                        yystate = 6
                        continue yyl
                    default:
                        yystate = 5
                        continue yyl
                }
            case 7:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x00:
                        yyt3 = yycursor;
                        yyt4 = -1;
                        yycursor += 1;
                        yystate = 8
                        continue yyl
                    case 0x2E:
                        yyt3 = yycursor;
                        yycursor += 1;
                        yystate = 9
                        continue yyl
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yycursor += 1;
                        yystate = 7
                        continue yyl
                    default:
                        yystate = 5
                        continue yyl
                }
            case 8:
                t1 = yyt1;
                t3 = yyt2;
                t4 = yyt3;
                t5 = yyt4;
                t2 = yyt2;
                t2 -= 1;
                {
            return {
                major: Number(yyinput.substring(t1, t2)),
                minor: Number(yyinput.substring(t3, t4)),
                patch: t5 == -1 ? 0 : Number(yyinput.substring(t5, yycursor - 1))
            }
        }
            case 9:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yyt4 = yycursor;
                        yycursor += 1;
                        yystate = 10
                        continue yyl
                    default:
                        yystate = 5
                        continue yyl
                }
            case 10:
                yych = yyinput.charCodeAt(yycursor)
                switch (yych) {
                    case 0x00:
                        yycursor += 1;
                        yystate = 8
                        continue yyl
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                        yycursor += 1;
                        yystate = 10
                        continue yyl
                    default:
                        yystate = 5
                        continue yyl
                }
            default:
                throw "internal lexer error"
        }
    }
}

}

assert.deepEqual(parse("23.34\0"), {major: 23, minor: 34, patch: 0})
assert.deepEqual(parse("1.2.99999\0"), {major: 1, minor: 2, patch: 99999})
assert.deepEqual(parse("1.a\0"), null)
