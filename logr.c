#include "logr.h"
#include <stdio.h>

void logr(LogLevel level, const char *msgTemplate, ...) {
    va_list args;
    va_start(args, msgTemplate);

    switch (level) {
        case LOGR_INFO:
            printf("INFO: ");
            break;
        case LOGR_DEBUG:
            printf("DEBUG: ");
            break;
        case LOGR_WARN:
            printf("WARN: ");
            break;
        case LOGR_ERROR:
            printf("ERROR: ");
            break;
    }

    vprintf(msgTemplate, args);

    printf("\n");
    va_end(args);
}
