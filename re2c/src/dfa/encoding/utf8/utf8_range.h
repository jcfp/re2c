#ifndef _utf8_range_h
#define _utf8_range_h

#include "src/dfa/encoding/range_suffix.h"
#include "src/dfa/encoding/utf8/utf8.h"

namespace re2c {

void UTF8addContinuous(RangeSuffix * & p, utf8::rune l, utf8::rune h, uint32_t n);
void UTF8splitByContinuity(RangeSuffix * & p, utf8::rune l, utf8::rune h, uint32_t n);
void UTF8splitByRuneLength(RangeSuffix * & p, utf8::rune l, utf8::rune h);

} // namespace re2c

#endif // _utf8_range_h