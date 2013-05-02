// Copyright Siemens Corporate Research Inc. 2007
// Author Sylvain Jaume <sylvain.jaume@siemens.com>

#ifndef _XIP_OSX_STANDARD_H_
#define _XIP_OSX_STANDARD_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <Strings.h>
#include <X11/Xmd.h> // define 'typedef CARD8 BOOL'

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

#ifdef __cplusplus
#include <string>
#include <algorithm>
#endif // __cplusplus

// typedef int64_t __int64;

//redefine windows specific functions, types etc.
#ifndef _strtoi64
//used in SoInt64 / SoMFInt64 ...
#define _strtoi64 strtoll
#endif //_strtoi64

//#ifndef _i64toa
//used in SoInt64 / SoMFInt64 ...
//#define _i64toa lltoa //itoa //ultoa //
//#endif //_i64toa

//TODO properly...
#ifndef _i64toa(val, buf, base)
//used in SoInt64 / SoMFInt64 ...
#define _i64toa(val, buf, base) sprintf(buf, "%ll", val)
#endif //_i64toa(val, buf, base)

#ifndef _vsnwprintf
//used in XipException && XipLog
//looks like we need to fall back to a less secure version?
//#define _vsnwprintf vsnwprintf
#define _vsnwprintf vswprintf
#endif //_vsnwprintf

#ifndef MAX_PATH
//used in XipLog // REALLY this should NOT be used, since it may not be consistent
#define MAX_PATH PATH_MAX
#endif //MAX_PATH

#ifndef wcsnlen(wchar, maxlength)
//used in XipLog
//unfortunately wcsnlen is only a GNU extension for linux & doesn't exist on the mac 
#define wcsnlen(wchar, maxlength) wcslen(wchar)
#endif //wcsnlen(wchar, maxlength)

//TYPES
//#ifndef __int64
//#define __int64 int64_t
//#endif //__int64
typedef int64_t __int64;

//#ifndef __uint64
//#define __uint64 uint64_t
//#endif //__uint64
typedef uint64_t __uint64;

#ifndef _libiconv_open
#define _libiconv_open libiconv_open
#endif //_libiconv_open

#ifndef _jpeg_destroy_decompress
#define _jpeg_destroy_decompress jpeg_destroy_decompress
#endif //_jpeg_destroy_decompress

#endif // _XIP_OSX_STANDARD_H_
