//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LINE_LENGTH 256
#define LOG_FILE "application.log"

typedef struct {
    time_t timestamp;
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

LogEntry logEntries[MAX_LOG_ENTRIES];
int logEntryCount = 0;

void loadLogs(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open log file");
        return;
    }

    while (fgets(logEntries[logEntryCount].message, MAX_LINE_LENGTH, file) != NULL) {
        char *token = strtok(logEntries[logEntryCount].message, " ");
        strcpy(logEntries[logEntryCount].level, token);
        
        token = strtok(NULL, " ");
        logEntries[logEntryCount].timestamp = atoi(token);  // assuming timestamp is in seconds since epoch

        token = strtok(NULL, "\n");
        if (token != NULL) {
            strcpy(logEntries[logEntryCount].message, token);
        }

        logEntryCount++;
        if (logEntryCount >= MAX_LOG_ENTRIES) {
            break;
        }
    }

    fclose(file);
}

void filterLogsByLevel(const char *level) {
    printf("\nLogs with level '%s':\n", level);
    for (int i = 0; i < logEntryCount; i++) {
        if (strcmp(logEntries[i].level, level) == 0) {
            printf("%ld %s %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
        }
    }
}

void filterLogsByTimeRange(time_t startTime, time_t endTime) {
    printf("\nLogs between %ld and %ld:\n", startTime, endTime);
    for (int i = 0; i < logEntryCount; i++) {
        if (logEntries[i].timestamp >= startTime && logEntries[i].timestamp <= endTime) {
            printf("%ld %s %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
        }
    }
}

void printAllLogs() {
    printf("\nAll Logs:\n");
    for (int i = 0; i < logEntryCount; i++) {
        printf("%ld %s %s\n", logEntries[i].timestamp, logEntries[i].level, logEntries[i].message);
    }
}

void logStats() {
    int infoCount = 0, warningCount = 0, errorCount = 0;
    for (int i = 0; i < logEntryCount; i++) {
        if (strcmp(logEntries[i].level, "INFO") == 0) {
            infoCount++;
        } else if (strcmp(logEntries[i].level, "WARNING") == 0) {
            warningCount++;
        } else if (strcmp(logEntries[i].level, "ERROR") == 0) {
            errorCount++;
        }
    }
    printf("\nLog Statistics:\nINFO: %d\nWARNING: %d\nERROR: %d\n", infoCount, warningCount, errorCount);
}

int main() {
    loadLogs(LOG_FILE);

    printAllLogs();
    
    filterLogsByLevel("ERROR");

    time_t startTime = 1672588800; // Example start time
    time_t endTime = 1672675200;   // Example end time
    filterLogsByTimeRange(startTime, endTime);

    logStats();

    return 0;
}