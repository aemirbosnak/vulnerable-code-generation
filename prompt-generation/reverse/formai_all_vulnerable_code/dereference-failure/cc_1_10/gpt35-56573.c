//FormAI DATASET v1.0 Category: System event logger ; Style: genious
/* 
   This is a C System event logger that logs all the important system events 
   that occur on a system. The events are logged into a text file for future 
   analysis and debugging purposes. This program uses the system call 
   "syslog" to write log messages to the system log file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <time.h>

#define LOG_FILE "/var/log/events.log"

/* Enum of System events */
enum EventType {
    ERROR = LOG_ERR,
    WARNING = LOG_WARNING,
    INFO = LOG_INFO
};

/* Function to log system events */
void logEvent(enum EventType eventType, const char* message) {
    /* Open the log file */
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        syslog(LOG_ERR, "Failed to open log file: %s", LOG_FILE);
        return;
    }

    /* Get the current time */
    time_t currentTime = time(NULL);
    char* timeStr = ctime(&currentTime);
    if (timeStr == NULL) {
        syslog(LOG_ERR, "Failed to get current time.");
        fclose(file);
        return;
    }

    /* Remove newline character from time string */
    timeStr[strlen(timeStr) - 1] = '\0';

    /* Write log message to file and system log */
    fprintf(file, "%s - %s\n", timeStr, message);
    syslog(eventType, "%s", message);

    /* Close the log file */
    fclose(file);
}

/* Main function */
int main(void) {
    /* Open the system log */
    openlog("MyEventLogger", LOG_CONS | LOG_PID | LOG_NDELAY, LOG_LOCAL1);

    /* Log some events */
    logEvent(ERROR, "Failed to connect to database.");
    logEvent(WARNING, "Low disk space on /dev/sda1.");
    logEvent(INFO, "User logged in successfully.");

    /* Close the system log */
    closelog();

    return 0;
}