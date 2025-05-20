//FormAI DATASET v1.0 Category: System event logger ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Custom event codes */
#define EVENT_STARTUP 0
#define EVENT_SHUTDOWN 1
#define EVENT_WARNING 2
#define EVENT_ERROR 3

/* Custom event descriptions */
const char *event_desc[] = {
    "Startup",
    "Shutdown",
    "Warning",
    "Error",
    NULL
};

/* Custom event logging function */
void log_event(int event_code, const char *event_msg) {

    /* Get current time */
    time_t now = time(NULL);
    struct tm *time_info = localtime(&now);

    /* Open log file in append mode */
    FILE *log_file = fopen("event_log.txt", "a");

    /* Write event details to file */
    fprintf(log_file, "[%04d-%02d-%02d %02d:%02d:%02d] %s: %s\n",
            time_info->tm_year + 1900, time_info->tm_mon + 1, time_info->tm_mday,
            time_info->tm_hour, time_info->tm_min, time_info->tm_sec,
            event_desc[event_code], event_msg);

    /* Close log file */
    fclose(log_file);
}

/* Example usage of event logger */
int main() {

    int num_warnings = 0;
    int num_errors = 0;

    /* Log startup event */
    log_event(EVENT_STARTUP, "Program started successfully.");

    /* Some warnings */
    log_event(EVENT_WARNING, "Disk space low.");
    num_warnings++;
    log_event(EVENT_WARNING, "Memory usage high.");
    num_warnings++;

    /* An error occurs */
    log_event(EVENT_ERROR, "Unable to open file.");
    num_errors++;

    /* Program finishes */
    log_event(EVENT_SHUTDOWN, "Program finished.");

    /* Print summary of events */
    printf("Event summary:\n");
    printf("Number of warnings: %d\n", num_warnings);
    printf("Number of errors: %d\n", num_errors);

    return 0;
}