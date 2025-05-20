//FormAI DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

typedef struct LogEntry {
    char timestamp[MAXLEN];
    char message[MAXLEN];
} LogEntry;

LogEntry createLogEntry(char* timestamp, char* message) {
    LogEntry entry;
    strcpy(entry.timestamp, timestamp);
    strcpy(entry.message, message);
    return entry;
}

void printLogEntry(LogEntry entry) {
    printf("[%s] %s\n", entry.timestamp, entry.message);
}

int main() {
    LogEntry log[MAXLEN];
    int logSize = 0;

    FILE* file = fopen("example.log", "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(1);
    }

    char line[MAXLEN];
    while (fgets(line, MAXLEN, file)) {
        char* timestamp = strtok(line, " ");
        char* message = strtok(NULL, "\n");

        log[logSize++] = createLogEntry(timestamp, message);
    }
    
    fclose(file);

    printf("Log file parsed successfully!\n");
    printf("Here are the log entries:\n");
    for (int i = 0; i < logSize; i++) {
        printLogEntry(log[i]);
    }

    return 0;
}