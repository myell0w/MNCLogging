//
//  MNCLogging.h
//  MNCLogging
//
//  Created by Matthias Tretter on 4.09.14.
//  Copyright 2014 @myell0w. All rights reserved.
//
//
// Extracted from https://github.com/foundationkit/FoundationKit , original implementation by Martin Schürrer (@Msch)
// See http://stackoverflow.com/questions/2632300/looping-through-macro-varargs-values
// Derived from https://github.com/VTPG/CommonCode/blob/master/VTPG_Common.m by Vincent Gable
// Derived from http://www.dribin.org/dave/blog/archives/2008/09/22/convert_to_nsstring/
//
//
//  The MIT License (MIT)
//
//  Copyright (c) 2014 Matthias Tretter
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to
//  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//  the Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


extern const NSString * const kMNCLogInternalDontOutputMe;

/**
 Macro to output debug-information to the console.

 Example:
 MNCLog(aString) results in [Filename.m:Linenumber] aString = value of string
 */
#define MNCLog(...) NSLog(@"%@", MNCLogToString(__VA_ARGS__));

/**
 Macro to save debug-information into a NSString.

 Example:
 MNCLogString(aString, aInt) results in [Filename.m:Linenumber] aString = value of string aInt = 13
 */
#define MNCLogToString(...) _MNCLogToString_(__VA_ARGS__,_MNCLogToString_RightSequence())



#define _MNCLogToString_(...) _MNCLogToString__(__VA_ARGS__)
#define _MNCLogToString__(_1, _2, _3, _4, _5, _6, _7, _8, _9,_10,...) ^{\
__typeof__(_1) _T1 = (_1); \
__typeof__(_2) _T2 = (_2); \
__typeof__(_3) _T3 = (_3); \
__typeof__(_4) _T4 = (_4); \
__typeof__(_5) _T5 = (_5); \
__typeof__(_6) _T6 = (_6); \
__typeof__(_7) _T7 = (_7); \
__typeof__(_8) _T8 = (_8); \
__typeof__(_9) _T9 = (_9); \
__typeof__(_10) _T10 = (_10); \
return _MNCLogToString(\
[[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__,\
@encode(__typeof__(_1)), "" # _1, &_T1, \
@encode(__typeof__(_2)), "" # _2, &_T2, \
@encode(__typeof__(_3)), "" # _3, &_T3, \
@encode(__typeof__(_4)), "" # _4, &_T4, \
@encode(__typeof__(_5)), "" # _5, &_T5, \
@encode(__typeof__(_6)), "" # _6, &_T6, \
@encode(__typeof__(_7)), "" # _7, &_T7, \
@encode(__typeof__(_8)), "" # _8, &_T8, \
@encode(__typeof__(_9)), "" # _9, &_T9, \
@encode(__typeof__(_10)), "" # _10, &_T10); \
}()


#define _MNCLogToString_RightSequence() kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe, kMNCLogInternalDontOutputMe

NSString *_MNCLogToString (NSString *file, unsigned int line, ...);
