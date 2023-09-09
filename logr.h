#ifndef LOGR_H
#define LOGR_H

#include <stdarg.h>

typedef enum {
    LOGR_INFO,
    LOGR_DEBUG,
    LOGR_WARN,
    LOGR_ERROR
} LogLevel;

void logr(LogLevel level, const char *msgTemplate, ...);

#endif /* LOGR_H */
