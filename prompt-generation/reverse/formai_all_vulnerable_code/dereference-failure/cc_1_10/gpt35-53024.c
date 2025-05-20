//FormAI DATASET v1.0 Category: Log analysis ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

// Data structure to store log entry information
typedef struct {
    char timestamp[20];
    char message[100];
    int severity;
} LogEntry;

// Function to parse log entries from a file and store them in an array
int parseLogEntries(LogEntry *entries, const char *filename) {
    FILE *file;
    char line[200];
    int count = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        // Parse timestamp, message, and severity from the log entry
        char *timestamp = strtok(line, ",");
        char *message = strtok(NULL, ",");
        char *severity_str = strtok(NULL, ",");
        int severity = atoi(severity_str);

        // Create a new log entry and add it to the array
        LogEntry entry;
        strncpy(entry.timestamp, timestamp, sizeof(entry.timestamp));
        strncpy(entry.message, message, sizeof(entry.message));
        entry.severity = severity;
        entries[count++] = entry;
    }

    fclose(file);

    return count;
}

// Function to sort log entries by timestamp
void sortLogEntries(LogEntry *entries, int count) {
    int i, j;
    LogEntry temp;

    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (strcmp(entries[i].timestamp, entries[j].timestamp) > 0) {
                temp = entries[i];
                entries[i] = entries[j];
                entries[j] = temp;
            }
        }
    }
}

// Function to filter log entries by severity level
int filterLogEntries(LogEntry *entries, int count, int min_severity, int max_severity) {
    int i, j = 0;

    for (i = 0; i < count; i++) {
        if (entries[i].severity >= min_severity && entries[i].severity <= max_severity) {
            entries[j++] = entries[i];
        }
    }

    return j;
}

int main() {
    LogEntry entries[MAX_LOG_ENTRIES];
    int count;

    // Parse log entries from a file
    count = parseLogEntries(entries, "example.log");
    if (count < 0) {
        return 1;
    }

    // Sort log entries by timestamp
    sortLogEntries(entries, count);

    // Filter log entries by severity level
    count = filterLogEntries(entries, count, 1, 3);

    // Print out the filtered log entries
    int i;
    for (i = 0; i < count; i++) {
        printf("%s: %s\n", entries[i].timestamp, entries[i].message);
    }

    return 0;
}