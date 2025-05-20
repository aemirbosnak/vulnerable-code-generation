//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct logEntry {
    char timestamp[25];
    char source[100];
    char message[500];
};

void parseLogEntry(char logLine[], struct logEntry *entry) {
    char *token;
    token = strtok(logLine, "|");
    strcpy(entry->timestamp, token);
    token = strtok(NULL, "|");
    strcpy(entry->source, token);
    token = strtok(NULL, "|");
    strcpy(entry->message, token);
}

int main() {
    FILE *logFile;
    char logLine[600];
    struct logEntry entry;
    int numEntries = 0;
    int numErrors = 0;
    int numWarnings = 0;

    logFile = fopen("example.log", "r");
    if (logFile == NULL) {
        printf("Error opening log file!\n");
        exit(1);
    }

    printf("\n==================== LOG ANALYSIS REPORT ====================\n\n");
    printf("Timestamp\t\tSource\t\t\t\tMessage\n");

    while (fgets(logLine, sizeof(logLine), logFile)) {
        // Parse log line into a logEntry struct
        parseLogEntry(logLine, &entry);
        numEntries++;

        // Determine log level and increment appropriate counter
        if (strstr(entry.message, "ERROR")) {
            numErrors++;
            printf("%s\t%s\t\t%s", entry.timestamp, entry.source, entry.message);
        } else if (strstr(entry.message, "WARNING")) {
            numWarnings++;
            printf("%s\t%s\t\t%s", entry.timestamp, entry.source, entry.message);
        } else {
            printf("%s\t%s\t\t%s", entry.timestamp, entry.source, entry.message);
        }
    }

    printf("\n\n==================== SUMMARY ====================\n");
    printf("Total entries: %d\n", numEntries);
    printf("Errors: %d\n", numErrors);
    printf("Warnings: %d\n", numWarnings);

    fclose(logFile);
    return 0;
}