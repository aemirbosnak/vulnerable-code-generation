//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

typedef struct LogEntry {
    char timestamp[20];
    char severity[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return -1;
    }

    char *log_file_path = argv[1];

    FILE *log_file = fopen(log_file_path, "r");
    if (log_file == NULL) {
        printf("Unable to open log file: %s\n", log_file_path);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    LogEntry log_entries[MAX_LINE_LENGTH];
    int num_entries = 0;

    while (fgets(line, MAX_LINE_LENGTH, log_file) != NULL) {
        // Ignore empty lines
        if (strlen(line) <= 1) continue;

        LogEntry entry;

        // Extract timestamp
        char *timestamp = strtok(line, " ");
        strcpy(entry.timestamp, timestamp);

        // Extract severity
        char *severity = strtok(NULL, " ");
        strcpy(entry.severity, severity);

        // Extract message
        char *message = strtok(NULL, "\n");
        strcpy(entry.message, message);

        // Add entry to buffer
        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    // Print all entries
    for (int i = 0; i < num_entries; i++) {
        printf("[%s] [%s] %s\n", log_entries[i].timestamp, log_entries[i].severity, log_entries[i].message);
    }

    return 0;
}