//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

// Custom logger levels
#define LOG_DEBUG  6
#define LOG_INFO   7
#define LOG_NOTICE 8
#define LOG_WARNING  9
#define LOG_ERR    10
#define LOG_CRIT   11
#define LOG_ALERT  12
#define LOG_EMERG  13

// Custom logger facility names
#define FAC_APP 128
#define FAC_DB  129
#define FAC_NET 130

// Open the syslog daemon
int openlog_wrapper(const char *ident, int logopt, int facility)
{
    openlog(ident, logopt, facility);
    return 0;
}

// Close the syslog daemon
int closelog_wrapper()
{
    closelog();
    return 0;
}

// Log a message at the specified level
int log_wrapper(int level, const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    vsyslog(level, format, ap);
    va_end(ap);
    return 0;
}

// Get the current time in a string
char *get_time_string()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *time_string = asctime(tm);
    time_string[strlen(time_string) - 1] = '\0'; // Remove newline character
    return time_string;
}

// Log a custom message
int log_custom_message(const char *level_name, const char *facility_name, const char *message)
{
    char *time_string = get_time_string();
    openlog_wrapper("custom_logger", LOG_PID | LOG_CONS, FAC_APP);
    log_wrapper(LOG_INFO, "%s %s %s: %s", time_string, level_name, facility_name, message);
    closelog_wrapper();
    return 0;
}

int main()
{
    // Log a message at each level
    log_custom_message("DEBUG", "APP", "This is a debug message.");
    log_custom_message("INFO", "APP", "This is an info message.");
    log_custom_message("NOTICE", "APP", "This is a notice message.");
    log_custom_message("WARNING", "APP", "This is a warning message.");
    log_custom_message("ERR", "APP", "This is an error message.");
    log_custom_message("CRIT", "APP", "This is a critical message.");
    log_custom_message("ALERT", "APP", "This is an alert message.");
    log_custom_message("EMERG", "APP", "This is an emergency message.");

    return 0;
}