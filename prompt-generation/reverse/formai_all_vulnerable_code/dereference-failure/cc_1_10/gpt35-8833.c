//FormAI DATASET v1.0 Category: Log analysis ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_ENTRY_LENGTH 200

/* Example log entry struct */
typedef struct {
    char timestamp[20];
    char message[MAX_LOG_ENTRY_LENGTH];
} LogEntry;

/* Global array to hold log entries */
LogEntry logEntries[MAX_LOG_ENTRIES];

/**
 * Parses a log file and stores entries in global logEntries array
 */
void parseLog(char *filename) {
    FILE *logFile = fopen(filename, "r");
    char line[MAX_LOG_ENTRY_LENGTH];
    int entryCount = 0;

    while (fgets(line, sizeof(line), logFile)) {
        // Get timestamp
        char *timestamp = strtok(line, " ");

        // Get message
        char *message = strtok(NULL, "\n");

        // Store entry in logEntries array
        LogEntry entry;
        strcpy(entry.timestamp, timestamp);
        strcpy(entry.message, message);
        logEntries[entryCount++] = entry;
    }

    fclose(logFile);
}

/**
 * Finds all log entries containing a given search term
 */
void searchLogs(char *searchTerm) {
    bool foundMatch = false;

    for (int i = 0; i < MAX_LOG_ENTRIES; i++) {
        if (strstr(logEntries[i].message, searchTerm)) {
            printf("%s  %s\n", logEntries[i].timestamp, logEntries[i].message);
            foundMatch = true;
        }
    }

    if (!foundMatch) {
        printf("No matches found for '%s'\n", searchTerm);
    }
}

/**
 * Main function - entry point for program
 */
int main(int argc, char **argv) {
    char *filename = argv[1];
    char *searchTerm = argv[2];

    parseLog(filename);
    searchLogs(searchTerm);

    return 0;
}