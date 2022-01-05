/* Generated by re2c */
// re2rust $INPUT -o $OUTPUT --header src/lexer/lexer.rs

mod src;
use src::lexer::lexer; // generated by re2c



fn lex(st: &mut lexer::State) -> bool {
    
{
	#[allow(unused_assignments)]
	let mut yych : u8 = 0;
	let mut yystate : usize = 0;
	'yyl: loop {
		match yystate {
			0 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				st.cur += 1;
				match yych {
					0x78 => {
						yystate = 3;
						continue 'yyl;
					}
					_ => {
						yystate = 1;
						continue 'yyl;
					}
				}
			}
			1 => {
				yystate = 2;
				continue 'yyl;
			}
			2 => { return true; }
			3 => {
				st.mar = st.cur;
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.yyt1 = st.cur;
						st.cur += 1;
						yystate = 4;
						continue 'yyl;
					}
					_ => {
						yystate = 2;
						continue 'yyl;
					}
				}
			}
			4 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.yyt2 = st.cur;
						st.cur += 1;
						yystate = 6;
						continue 'yyl;
					}
					_ => {
						yystate = 5;
						continue 'yyl;
					}
				}
			}
			5 => {
				st.cur = st.mar;
				yystate = 2;
				continue 'yyl;
			}
			6 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.yyt3 = st.cur;
						st.cur += 1;
						yystate = 7;
						continue 'yyl;
					}
					_ => {
						yystate = 5;
						continue 'yyl;
					}
				}
			}
			7 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.yyt1 = st.cur;
						st.cur += 1;
						yystate = 9;
						continue 'yyl;
					}
					_ => {
						yystate = 8;
						continue 'yyl;
					}
				}
			}
			8 => {
				st.cur = st.yyt1;
				{ return false; }
			}
			9 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.cur += 1;
						yystate = 10;
						continue 'yyl;
					}
					_ => {
						st.yyt1 = st.yyt2;
						yystate = 8;
						continue 'yyl;
					}
				}
			}
			10 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.cur += 1;
						yystate = 11;
						continue 'yyl;
					}
					_ => {
						st.yyt1 = st.yyt3;
						yystate = 8;
						continue 'yyl;
					}
				}
			}
			11 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.cur += 1;
						yystate = 12;
						continue 'yyl;
					}
					_ => {
						yystate = 8;
						continue 'yyl;
					}
				}
			}
			12 => {
				yych = unsafe {*st.str.get_unchecked(st.cur)};
				match yych {
					0x78 => {
						st.cur += 1;
						yystate = 13;
						continue 'yyl;
					}
					_ => {
						yystate = 8;
						continue 'yyl;
					}
				}
			}
			13 => {
				yystate = 8;
				continue 'yyl;
			}
			_ => {
				panic!("internal lexer error")
			}
		}
	}
}

}

fn main() {
    let mut st = lexer::State {
        str: b"xxxxxxxx\0",
        cur: 0,
        mar: 0,
        
yyt1: 0, yyt2: 0, yyt3: 0, 

    };
    assert_eq!(lex(&mut st), false);
    assert_eq!(st.cur, 4);
}
/* Generated by re2c */

pub struct State<'a> {
    pub str: &'a [u8],
    pub cur: usize,
    pub mar: usize,
    
pub yyt1: usize, pub yyt2: usize, pub yyt3: usize, 

}
rust/headers/header.re:29:28: warning: trailing context has 4th degree of nondeterminism [-Wnondeterministic-tags]