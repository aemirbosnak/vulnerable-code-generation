//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LENGTH 1024
#define MAX_LINE_LENGTH 256

typedef struct {
    char *timestamp;
    char *message;
} log_entry_t;

typedef struct {
    log_entry_t *entries;
    int count;
    int capacity;
} log_t;

void log_init(log_t *log) {
    log->entries = NULL;
    log->count = 0;
    log->capacity = 10;
}

void log_add(log_t *log, const char *timestamp, const char *message) {
    if (log->count == log->capacity) {
        log->capacity *= 2;
        log->entries = realloc(log->entries, sizeof(log_entry_t) * log->capacity);
    }
    log->entries[log->count].timestamp = timestamp;
    log->entries[log->count].message = message;
    log->count++;
}

void log_print(log_t *log) {
    int i;
    for (i = 0; i < log->count; i++) {
        printf("%s - %s\n", log->entries[i].timestamp, log->entries[i].message);
    }
}

int main() {
    log_t *log = malloc(sizeof(log_t));
    log_init(log);

    // Add some logs
    log_add(log, "2022-01-01 12:00:00", "Started the day");
    log_add(log, "2022-01-01 12:05:00", "Finished the first task");
    log_add(log, "2022-01-01 12:10:00", "Started the second task");
    log_add(log, "2022-01-01 12:20:00", "Finished the second task");

    // Print the logs
    log_print(log);

    // Free the memory
    free(log->entries);
    free(log);

    return 0;
}