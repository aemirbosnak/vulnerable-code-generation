//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_LINE 256
#define MAX_LOG_FILE 10

typedef struct {
    int level;
    char timestamp[20];
    char message[MAX_LOG_LINE];
} LogEntry;

void displayUsage() {
    printf("Usage: log_analyzer <log_file> <filter_level>\n");
    printf("filter_level: 0 - DEBUG, 1 - INFO, 2 - WARNING, 3 - ERROR\n");
}

void parseLogEntry(const char *line, LogEntry *entry) {
    char *levelStr = strtok((char *)line, "|");
    entry->timestamp[0] = '\0';
    entry->message[0] = '\0';

    if (strcmp(levelStr, "DEBUG") == 0) {
        entry->level = 0;
    } else if (strcmp(levelStr, "INFO") == 0) {
        entry->level = 1;
    } else if (strcmp(levelStr, "WARNING") == 0) {
        entry->level = 2;
    } else if (strcmp(levelStr, "ERROR") == 0) {
        entry->level = 3;
    }

    char *timeStr = strtok(NULL, "|");
    if (timeStr != NULL) {
        strcpy(entry->timestamp, timeStr);
    }

    char *msgStr = strtok(NULL, "|");
    if (msgStr != NULL) {
        strcpy(entry->message, msgStr);
    }
}

void displayLogEntry(const LogEntry *entry) {
    const char *levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    printf("[%s] %s: %s\n", entry->timestamp, levels[entry->level], entry->message);
}

void analyzeLogFile(const char *fileName, int filterLevel) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }

    char line[MAX_LOG_LINE];
    LogEntry entry;

    while (fgets(line, sizeof(line), file)) {
        parseLogEntry(line, &entry);
        if (entry.level >= filterLevel) {
            displayLogEntry(&entry);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        displayUsage();
        return EXIT_FAILURE;
    }

    const char *logFileName = argv[1];
    int filterLevel = atoi(argv[2]);

    if (filterLevel < 0 || filterLevel > 3) {
        printf("Invalid filter level provided. Please use a value between 0 and 3.\n");
        displayUsage();
        return EXIT_FAILURE;
    }

    analyzeLogFile(logFileName, filterLevel);
    return EXIT_SUCCESS;
}