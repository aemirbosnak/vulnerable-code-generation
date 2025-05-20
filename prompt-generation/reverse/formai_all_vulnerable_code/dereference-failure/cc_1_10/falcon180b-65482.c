//Falcon-180B DATASET v1.0 Category: System event logger ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define LOG_FILE "event_log.txt"

typedef struct {
    char event[100];
    char description[200];
    time_t timestamp;
} LogEntry;

FILE *logFile = NULL;
int logCount = 0;

void initLog() {
    logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        printf("Error opening log file\n");
        exit(1);
    }
}

void logEvent(char *event, char *description) {
    if (logCount >= MAX_LOG_SIZE) {
        printf("Log is full. Cannot log event.\n");
        return;
    }

    LogEntry entry;
    strcpy(entry.event, event);
    strcpy(entry.description, description);
    entry.timestamp = time(NULL);

    fprintf(logFile, "Event: %s\nDescription: %s\nTimestamp: %s", entry.event, entry.description, ctime(&entry.timestamp));
    fflush(logFile);

    logCount++;
}

void closeLog() {
    fclose(logFile);
}

int main() {
    initLog();

    logEvent("System started", "The system has started successfully");

    // Simulate some events
    for (int i = 0; i < 10; i++) {
        char event[20];
        sprintf(event, "Event %d", i+1);
        char description[50];
        sprintf(description, "This is event %d", i+1);
        logEvent(event, description);
        sleep(1);
    }

    closeLog();

    return 0;
}