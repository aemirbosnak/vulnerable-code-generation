//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

#define LOG_USER "my_app"

void my_logger(int level, const char *format, ...)
{
    va_list args;
    char message[1024];

    va_start(args, format);
    vsnprintf(message, sizeof(message), format, args);
    va_end(args);

    openlog(LOG_USER, LOG_PID | LOG_CONS, LOG_USER);

    switch (level)
    {
        case LOG_EMERG:
            syslog(LOG_EMERG, "%s", message);
            break;
        case LOG_ALERT:
            syslog(LOG_ALERT, "%s", message);
            break;
        case LOG_CRIT:
            syslog(LOG_CRIT, "%s", message);
            break;
        case LOG_ERR:
            syslog(LOG_ERR, "%s", message);
            break;
        case LOG_WARNING:
            syslog(LOG_WARNING, "%s", message);
            break;
        case LOG_NOTICE:
            syslog(LOG_NOTICE, "%s", message);
            break;
        case LOG_INFO:
            syslog(LOG_INFO, "%s", message);
            break;
        case LOG_DEBUG:
            syslog(LOG_DEBUG, "%s", message);
            break;
        default:
            syslog(LOG_INFO, "Unknown log level: %d", level);
            break;
    }

    closelog();
}

int main(void)
{
    my_logger(LOG_INFO, "Application started");
    my_logger(LOG_WARNING, "An error occurred: %s", strerror(errno));
    my_logger(LOG_DEBUG, "Application exiting");

    return 0;
}