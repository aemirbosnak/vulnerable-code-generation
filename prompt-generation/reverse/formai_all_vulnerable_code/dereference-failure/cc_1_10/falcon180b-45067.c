//Falcon-180B DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 1024

typedef struct {
    time_t timestamp;
    char message[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

FILE *logFile = NULL;
int numEntries = 0;

void initLogger() {
    logFile = fopen("event.log", "w");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }
}

void logEvent(const char *message) {
    if (numEntries >= MAX_LOG_ENTRIES) {
        printf("Log is full\n");
        return;
    }

    struct tm tm;
    time_t now = time(NULL);
    localtime_r(&now, &tm);

    char timestamp[32];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm);

    LogEntry entry = {
       .timestamp = now,
       .message = strdup(message)
    };

    fprintf(logFile, "%s - %s\n", timestamp, entry.message);
    fflush(logFile);

    numEntries++;
}

void closeLogger() {
    fclose(logFile);
}

int main() {
    initLogger();

    logEvent("Program started");

    sleep(2);

    logEvent("Event 1 occurred");

    sleep(3);

    logEvent("Event 2 occurred");

    closeLogger();

    return 0;
}