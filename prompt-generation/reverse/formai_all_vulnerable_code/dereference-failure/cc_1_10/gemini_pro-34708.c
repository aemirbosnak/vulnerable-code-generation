//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct {
    char *log_entry;
    int log_entry_size;
} log_entry_t;

typedef struct {
    log_entry_t *log_entries;
    int log_entries_count;
} log_t;

log_t *log_new() {
    log_t *log = malloc(sizeof(log_t));
    log->log_entries = NULL;
    log->log_entries_count = 0;
    return log;
}

void log_free(log_t *log) {
    for (int i = 0; i < log->log_entries_count; i++) {
        free(log->log_entries[i].log_entry);
    }
    free(log->log_entries);
    free(log);
}

void log_add_entry(log_t *log, char *log_entry, int log_entry_size) {
    log->log_entries = realloc(log->log_entries, (log->log_entries_count + 1) * sizeof(log_entry_t));
    log->log_entries[log->log_entries_count].log_entry = malloc(log_entry_size + 1);
    memcpy(log->log_entries[log->log_entries_count].log_entry, log_entry, log_entry_size);
    log->log_entries[log->log_entries_count].log_entry[log_entry_size] = '\0';
    log->log_entries_count++;
}

int main() {
    log_t *log = log_new();

    char *log_entry = "This is a log entry.";
    int log_entry_size = strlen(log_entry);

    log_add_entry(log, log_entry, log_entry_size);

    printf("Log entry: %s\n", log->log_entries[0].log_entry);

    log_free(log);

    return 0;
}