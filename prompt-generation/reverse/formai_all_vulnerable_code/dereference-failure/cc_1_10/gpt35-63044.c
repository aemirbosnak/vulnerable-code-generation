//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_LENGTH 1000

typedef struct {
    char message[MAX_LOG_LENGTH];
    int severity;
} LogEntry;

void add_entry(LogEntry **log, int *log_size, char *message, int severity) {
    LogEntry *new_entry = (LogEntry*) malloc(sizeof(LogEntry));
    strncpy(new_entry->message, message, MAX_LOG_LENGTH);
    new_entry->severity = severity;

    (*log_size)++;
    *log = (LogEntry*) realloc(*log, (*log_size) * sizeof(LogEntry));
    (*log)[*log_size - 1] = *new_entry;
}

void print_entry(LogEntry entry) {
    printf("[%d]: %s\n", entry.severity, entry.message);
}

void print_all(LogEntry *log, int log_size) {
    for (int i = 0; i < log_size; i++) {
        print_entry(log[i]);
    }
}

int main() {
    LogEntry *log = NULL;
    int log_size = 0;

    add_entry(&log, &log_size, "Connection established.", 2);
    add_entry(&log, &log_size, "Received request from client A.", 1);
    add_entry(&log, &log_size, "Sending response to client A.", 1);
    add_entry(&log, &log_size, "Received request from client B.", 2);
    add_entry(&log, &log_size, "Error: could not read configuration file.", 3);

    printf("All entries:\n");
    print_all(log, log_size);

    printf("\nError entries:\n");
    for (int i = 0; i < log_size; i++) {
        if (log[i].severity == 3) {
            print_entry(log[i]);
        }
    }

    // Free memory
    free(log);

    return 0;
}