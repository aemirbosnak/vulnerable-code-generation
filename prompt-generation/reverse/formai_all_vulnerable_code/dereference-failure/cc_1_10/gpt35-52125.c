//FormAI DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_ENTRIES 1000
#define MAX_ERROR_MESSAGES 50

typedef struct {
    char datetime[20];
    char hostname[20];
    char message[MAX_LINE_LENGTH];
} LogEntry;

int analyzeLogFile(const char* filename) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    LogEntry logEntries[MAX_LOG_ENTRIES];
    int entryCount = 0;
    char errorMessages[MAX_ERROR_MESSAGES][MAX_LINE_LENGTH];
    int i, j, k;
    int hasWarnings = 0;
    int hasErrors = 0;
    int hasCriticals = 0;

    // Open the log file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("[ERROR] Unable to open file \"%s\"\n", filename);
        return 1;
    }

    // Read each line of the log file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        LogEntry entry;
        char* ptr;

        // Parse the datetime
        ptr = strtok(line, " ");
        strcpy(entry.datetime, ptr);

        // Parse the hostname
        ptr = strtok(NULL, " ");
        strcpy(entry.hostname, ptr);

        // Parse the message
        ptr = strtok(NULL, "\n");
        strcpy(entry.message, ptr);

        // Add the log entry to the array
        logEntries[entryCount++] = entry;
    }

    // Close the file
    fclose(file);

    // Analyze the log entries
    for (i = 0; i < entryCount; i++) {
        LogEntry entry = logEntries[i];

        // Check for warnings, errors, and critical messages
        if (strstr(entry.message, "Warning")) {
            hasWarnings = 1;
        }

        if (strstr(entry.message, "Error")) {
            hasErrors = 1;
            strcpy(errorMessages[k++], entry.message);
        }

        if (strstr(entry.message, "Critical")) {
            hasCriticals = 1;
            strcpy(errorMessages[k++], entry.message);
        }

        // Print the log entry
        printf("%s %s %s\n", entry.datetime, entry.hostname, entry.message);
    }

    // Print summary information
    printf("\n");

    if (hasWarnings) {
        printf("[WARNING] Log contains warnings\n");
    }

    if (hasErrors) {
        printf("[ERROR] Log contains %d errors\n", k);
        for (j = 0; j < k; j++) {
            printf("[ERROR] %s\n", errorMessages[j]);
        }
    } else {
        printf("[INFO] No errors found\n");
    }

    if (hasCriticals) {
        printf("[CRITICAL] Log contains %d critical messages\n", k);
        for (j = 0; j < k; j++) {
            printf("[CRITICAL] %s\n", errorMessages[j]);
        }
    } else {
        printf("[INFO] No critical messages found\n");
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: log-analyzer <log-file>\n");
        return 1;
    }

    return analyzeLogFile(argv[1]);
}