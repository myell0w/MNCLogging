//
//  MNCLogLevel.h
//  MNCLogging
//
//  Created by Matthias Tretter on 4.09.14.
//  Copyright 2014 @myell0w. All rights reserved.
//
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


#import "MNCLogging.h"


typedef NS_ENUM(NSUInteger, MNCLogLevel) {
    MNCLogLevelVerbose = 0,
    MNCLogLevelInfo,
    MNCLogLevelWarning,
    MNCLogLevelError,
    MNCLogLevelNone
};


MNCLogLevel MNCGetLogLevel(void);
void MNCSetLogLevel(MNCLogLevel logLevel);


NS_INLINE NSString* MNCLogLevelDescription(MNCLogLevel logLevel) {
    switch (logLevel) {
        case MNCLogLevelVerbose:
            return @"<V>";

        case MNCLogLevelInfo:
            return @"<I>";

        case MNCLogLevelWarning:
            return @"<W>";

        case MNCLogLevelError:
            return @"!E!";

        case MNCLogLevelNone:
        default:
            return @"";
    }
}


// Shortcuts for logging with the given log levels
#define MNCLogVerbose(...)       ({if (MNCLogLevelVerbose >= MNCGetLogLevel()) { CLS_LOG(@"%@ %@", [NSString stringWithFormat:__VA_ARGS__], MNCLogLevelDescription(MNCLogLevelVerbose));  }})
#define MNCLogInfo(...)          ({if (MNCLogLevelInfo >= MNCGetLogLevel()) { CLS_LOG(@"%@ %@", [NSString stringWithFormat:__VA_ARGS__], MNCLogLevelDescription(MNCLogLevelInfo));  }})
#define MNCLogWarning(...)       ({if (MNCLogLevelWarning >= MNCGetLogLevel()) { CLS_LOG(@"%@ %@", [NSString stringWithFormat:__VA_ARGS__], MNCLogLevelDescription(MNCLogLevelWarning));  }})
#define MNCLogError(...)         ({if (MNCLogLevelError >= MNCGetLogLevel()) { CLS_LOG(@"%@ %@", [NSString stringWithFormat:__VA_ARGS__], MNCLogLevelDescription(MNCLogLevelError));  }})

// Logs variables with log level Info
#define MNCLogVariables(...)          do { if (MNCLogLevelInfo >= MNCGetLogLevel()) { MNCLog(__VA_ARGS__)} } while(0)
// Logs variables with log level error
#define MNCLogErrorVariables(...)     do { if (MNCLogLevelError >= MNCGetLogLevel()) { MNCLog(__VA_ARGS__)} } while(0)

// Logs the function/method that got entered
#define MNCLogEntry()            do { NSString *enteredFunction = [NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding]; MNCLog(enteredFunction); } while(0)
// Logs that this method is not implemented and aborts
#define MNCLogNotImplemented()   do { NSString *enteredFunction = [NSString stringWithCString:__PRETTY_FUNCTION__ encoding:NSUTF8StringEncoding]; MNCLogError(@"Not implemented yet: %@", enteredFunction); [self doesNotRecognizeSelector:_cmd];} while(0)
