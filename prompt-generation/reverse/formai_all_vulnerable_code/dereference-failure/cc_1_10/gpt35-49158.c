//FormAI DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_LOG_LENGTH 100

int main() {
    char logEntry[MAX_LOG_LENGTH];
    char* logEntries[MAX_LOG_ENTRIES];
    int entryCount = 0;

    FILE* file = fopen("logfile.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(logEntry, MAX_LOG_LENGTH, file) != NULL) {
        logEntries[entryCount] = malloc(strlen(logEntry) + 1);
        strcpy(logEntries[entryCount], logEntry);
        entryCount++;
    }

    fclose(file);

    // Analyze log entries here
    int errorCount = 0;
    int warningCount = 0;
    int infoCount = 0;

    for (int i = 0; i < entryCount; i++) {
        if (strstr(logEntries[i], "ERROR")) {
            errorCount++;
        } else if (strstr(logEntries[i], "WARNING")) {
            warningCount++;
        } else {
            infoCount++;
        }
    }

    printf("Log analysis results:\n");
    printf("Errors: %d\n", errorCount);
    printf("Warnings: %d\n", warningCount);
    printf("Info: %d\n", infoCount);

    // Free allocated memory
    for (int i = 0; i < entryCount; i++) {
        free(logEntries[i]);
    }

    return 0;
}