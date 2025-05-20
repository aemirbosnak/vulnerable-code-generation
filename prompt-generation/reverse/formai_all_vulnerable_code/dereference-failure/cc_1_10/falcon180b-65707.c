//Falcon-180B DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event.log"
#define MAX_LOG_SIZE 100000
#define MAX_EVENT_SIZE 1024

typedef struct {
    char event[MAX_EVENT_SIZE];
    time_t timestamp;
} LogEntry;

FILE *logFile;
char *logBuffer;
size_t logBufferSize;
size_t logEntries;

void initLog(void) {
    logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", LOG_FILE);
        exit(1);
    }
    logBuffer = malloc(MAX_LOG_SIZE);
    logBufferSize = 0;
    logEntries = 0;
}

void closeLog(void) {
    fclose(logFile);
    free(logBuffer);
}

void logEvent(const char *event) {
    if (logBufferSize + strlen(event) + 1 >= MAX_LOG_SIZE) {
        fprintf(stderr, "Log buffer full, oldest event dropped.\n");
        logBufferSize -= strlen(logBuffer) + 1;
        memmove(logBuffer, logBuffer + strlen(logBuffer), logBufferSize);
    }
    strcat(logBuffer, event);
    logBufferSize += strlen(event) + 1;
    logEntries++;
}

void flushLog(void) {
    if (logBufferSize > 0) {
        fprintf(logFile, "%s", logBuffer);
        logBufferSize = 0;
    }
}

int main(void) {
    initLog();

    for (int i = 0; i < 10; i++) {
        char event[MAX_EVENT_SIZE];
        sprintf(event, "Event %d\n", i);
        logEvent(event);
        sleep(1);
    }

    flushLog();
    closeLog();

    return 0;
}