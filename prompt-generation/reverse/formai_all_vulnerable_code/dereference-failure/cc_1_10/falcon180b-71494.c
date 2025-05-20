//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 500

typedef struct {
    char *ip;
    char *date;
    char *time;
    char *request;
    char *status;
} LogEntry;

int main() {
    FILE *logFile;
    char line[MAX_LOG_ENTRY_LENGTH];
    char *delimiter = " ";
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int numEntries = 0;

    logFile = fopen("logfile.txt", "r");
    if (logFile == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    while (fgets(line, MAX_LOG_ENTRY_LENGTH, logFile)!= NULL) {
        char *token = strtok(line, delimiter);
        if (token == NULL) {
            continue;
        }

        LogEntry entry;
        strcpy(entry.ip, token);
        token = strtok(NULL, delimiter);
        strcpy(entry.date, token);
        token = strtok(NULL, delimiter);
        strcpy(entry.time, token);
        token = strtok(NULL, delimiter);
        strcpy(entry.request, token);
        token = strtok(NULL, delimiter);
        strcpy(entry.status, token);

        logEntries[numEntries] = entry;
        numEntries++;
    }

    fclose(logFile);

    printf("Number of log entries: %d\n", numEntries);
    printf("Log entries:\n");

    for (int i = 0; i < numEntries; i++) {
        printf("IP: %s\n", logEntries[i].ip);
        printf("Date: %s\n", logEntries[i].date);
        printf("Time: %s\n", logEntries[i].time);
        printf("Request: %s\n", logEntries[i].request);
        printf("Status: %s\n\n", logEntries[i].status);
    }

    return 0;
}