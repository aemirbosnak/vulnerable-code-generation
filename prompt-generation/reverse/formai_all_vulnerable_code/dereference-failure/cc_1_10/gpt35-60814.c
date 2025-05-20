//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVENT_TYPE_ERROR 0
#define EVENT_TYPE_WARNING 1
#define EVENT_TYPE_INFO 2

void logEvent(int eventType, char *message);

int main() {
    //Simulating program events
    logEvent(EVENT_TYPE_INFO, "Program started.");
    logEvent(EVENT_TYPE_WARNING, "Memory usage high.");
    logEvent(EVENT_TYPE_INFO, "User logged in.");
    logEvent(EVENT_TYPE_ERROR, "Fatal error occurred.");
    logEvent(EVENT_TYPE_WARNING, "Disk space low.");
    logEvent(EVENT_TYPE_INFO, "User logged out.");
    logEvent(EVENT_TYPE_INFO, "Program ended.");
    return 0;
}

void logEvent(int eventType, char *message) {
    //Get current time
    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    //Formatting log message with current time
    char *dateAndTime = asctime(timeinfo);
    int len = strlen(dateAndTime);
    dateAndTime[len - 1] = '\0'; //Removing new line character at the end
    char *logMessage = (char *) malloc((29 + strlen(message) + 1) * sizeof(char));
    switch (eventType) {
        case EVENT_TYPE_ERROR:
            sprintf(logMessage, "[%s] [ERROR] %s", dateAndTime, message);
            break;

        case EVENT_TYPE_WARNING:
            sprintf(logMessage, "[%s] [WARNING] %s", dateAndTime, message);
            break;

        case EVENT_TYPE_INFO:
            sprintf(logMessage, "[%s] [INFO] %s", dateAndTime, message);
            break;

        default:
            sprintf(logMessage, "[%s] [UNKNOWN] %s", dateAndTime, message);
    }

    //Writing log message to file
    FILE *fp = fopen("system_events.log", "a");
    if (fp == NULL) {
        printf("Error opening log file.\n");
        return;
    }
    fprintf(fp, "%s\n", logMessage);
    fclose(fp);

    //Printing log message to console
    printf("%s\n", logMessage);

    //Deallocating memory
    free(logMessage);
}