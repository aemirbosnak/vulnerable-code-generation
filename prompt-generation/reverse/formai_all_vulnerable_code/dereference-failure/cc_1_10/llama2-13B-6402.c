//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_LEN 1024
#define MAX_LINE_LEN 256

typedef struct {
    char *message;
    int len;
} log_entry_t;

typedef struct {
    log_entry_t *entries;
    int capacity;
    int size;
} log_t;

log_t *log_init(int capacity) {
    log_t *log = malloc(sizeof(log_t));
    log->capacity = capacity;
    log->size = 0;
    log->entries = calloc(capacity, sizeof(log_entry_t));
    return log;
}

void log_add(log_t *log, const char *message) {
    if (log->size >= log->capacity) {
        log_entry_t *new_entries = realloc(log->entries, (log->capacity *= 2) * sizeof(log_entry_t));
        log->entries = new_entries;
    }
    log_entry_t *entry = &log->entries[log->size++];
    entry->message = message;
    entry->len = strlen(message);
}

void log_print(log_t *log) {
    printf("Log Entries:\n");
    for (int i = 0; i < log->size; i++) {
        printf("[%d] %s\n", i, log->entries[i].message);
    }
}

int main() {
    log_t *log = log_init(10);

    log_add(log, "Hello, world!");
    log_add(log, "This is a test.");
    log_add(log, "This is another test.");

    log_print(log);

    return 0;
}