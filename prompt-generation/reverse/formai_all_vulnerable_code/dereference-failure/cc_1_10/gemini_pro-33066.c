//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a LogEntry struct
typedef struct LogEntry {
    int id;
    char* timestamp;
    char* message;
} LogEntry;

// Define a Log struct
typedef struct Log {
    LogEntry* entries;
    int numEntries;
} Log;

// Create a new log
Log* createLog() {
    Log* log = malloc(sizeof(Log));
    log->entries = NULL;
    log->numEntries = 0;
    return log;
}

// Add an entry to the log
void addEntry(Log* log, int id, char* timestamp, char* message) {
    log->entries = realloc(log->entries, (log->numEntries + 1) * sizeof(LogEntry));
    log->entries[log->numEntries].id = id;
    log->entries[log->numEntries].timestamp = strdup(timestamp);
    log->entries[log->numEntries].message = strdup(message);
    log->numEntries++;
}

// Print the log to a file
void printLog(Log* log, FILE* file) {
    for (int i = 0; i < log->numEntries; i++) {
        fprintf(file, "%d %s %s\n", log->entries[i].id, log->entries[i].timestamp, log->entries[i].message);
    }
}

// Free the memory allocated for the log
void freeLog(Log* log) {
    for (int i = 0; i < log->numEntries; i++) {
        free(log->entries[i].timestamp);
        free(log->entries[i].message);
    }
    free(log->entries);
    free(log);
}

// Main function
int main() {
    // Create a new log
    Log* log = createLog();

    // Add some entries to the log
    addEntry(log, 1, "2023-03-08 10:00:00", "This is the first entry.");
    addEntry(log, 2, "2023-03-08 10:01:00", "This is the second entry.");
    addEntry(log, 3, "2023-03-08 10:02:00", "This is the third entry.");

    // Print the log to a file
    FILE* file = fopen("log.txt", "w");
    printLog(log, file);
    fclose(file);

    // Free the memory allocated for the log
    freeLog(log);

    return 0;
}