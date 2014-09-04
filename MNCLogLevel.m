#import "MNCLogLevel.h"


// In Debug-Mode we default to the log level Info, else we only log warnings and errors
#if DEBUG
static MNCLogLevel kMNCLogLevel = MNCLogLevelInfo;
#else
static MNCLogLevel kMNCLogLevel = MNCLogLevelWarning;
#endif


MNCLogLevel MNCGetLogLevel(void) {
    return kMNCLogLevel;
}

void MNCSetLogLevel(MNCLogLevel logLevel) {
    kMNCLogLevel = logLevel;
}
