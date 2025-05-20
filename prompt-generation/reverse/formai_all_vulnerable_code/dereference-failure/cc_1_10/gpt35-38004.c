//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

typedef struct {
    char* timestamp;
    char* message;
} LogEntry;

int read_log_entries(LogEntry* logEntries) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int numLogEntries = 0;

    fp = fopen("logfile.txt", "r");
    if (fp == NULL) {
        printf("Failed to open logfile\n");
        return -1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char* timestamp = strtok(line, ",");
        char* message = strtok(NULL, "\n");
        logEntries[numLogEntries].timestamp = (char*)malloc(strlen(timestamp) * sizeof(char));
        logEntries[numLogEntries].message = (char*)malloc(strlen(message) * sizeof(char));
        strcpy(logEntries[numLogEntries].timestamp, timestamp);
        strcpy(logEntries[numLogEntries].message, message);
        numLogEntries++;
    }

    fclose(fp);

    if (line) {
        free(line);
    }

    return numLogEntries;
}

void print_log_entries(LogEntry* logEntries, int numLogEntries) {
    for (int i = 0; i < numLogEntries; i++) {
        printf("%s - %s\n", logEntries[i].timestamp, logEntries[i].message);
    }
}

int main() {
    LogEntry logEntries[MAX_LOG_ENTRIES];

    int numLogEntries = read_log_entries(logEntries);

    if (numLogEntries < 0) {
        printf("Failed to read log entries\n");
        return -1;
    }

    printf("Log Entries:\n");
    print_log_entries(logEntries, numLogEntries);

    return 0;
}