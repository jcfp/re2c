/* $Id$ */
#include <string.h>
#include <stdlib.h>

#include "src/globals.h"
#include "src/util/substr.h"

#ifndef HAVE_STRNDUP

char *strndup(const char *str, size_t len)
{
	char * ret = (char*)malloc(len + 1);
	
	memcpy(ret, str, len);
	ret[len] = '\0';
	return ret;
}

#endif

namespace re2c
{

void SubStr::out(std::ostream& o) const
{
	o.write(str, len);
}

bool operator==(const SubStr &s1, const SubStr &s2)
{
	return (bool) (s1.len == s2.len && memcmp(s1.str, s2.str, s1.len) == 0);
}

} // end namespace re2c
