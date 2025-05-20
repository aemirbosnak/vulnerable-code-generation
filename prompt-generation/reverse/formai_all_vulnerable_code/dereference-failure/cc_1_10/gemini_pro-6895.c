//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Custom data structures and functions

typedef struct LogEntry {
    char *timestamp;
    char *message;
} LogEntry;

LogEntry *parseLogEntry(char *line) {
    LogEntry *entry = malloc(sizeof(LogEntry));
    char *timestamp = strtok(line, " ");
    char *message = strtok(NULL, "\n");
    entry->timestamp = strdup(timestamp);
    entry->message = strdup(message);
    return entry;
}

void freeLogEntry(LogEntry *entry) {
    free(entry->timestamp);
    free(entry->message);
    free(entry);
}

// Main program

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    FILE *logFile = fopen(argv[1], "r");
    if (logFile == NULL) {
        perror("Error opening log file");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), logFile) != NULL) {
        LogEntry *entry = parseLogEntry(line);
        printf("%s: %s\n", entry->timestamp, entry->message);
        freeLogEntry(entry);
    }

    fclose(logFile);
    return 0;
}