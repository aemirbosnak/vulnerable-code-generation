//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 10000
#define MIN_LOG_SIZE 1

typedef struct {
    double time;
    double value;
} log_entry_t;

typedef struct {
    log_entry_t *entries;
    int capacity;
    int size;
} log_t;

log_t *create_log(int capacity) {
    log_t *log = (log_t *)calloc(1, sizeof(log_t));
    log->capacity = capacity;
    log->size = 0;
    log->entries = (log_entry_t *)calloc(capacity, sizeof(log_entry_t));
    return log;
}

void add_log_entry(log_t *log, double time, double value) {
    if (log->size >= log->capacity) {
        log_entry_t *new_entries = (log_entry_t *)realloc(log->entries, (log->capacity += 10) * sizeof(log_entry_t));
        log->entries = new_entries;
    }
    log->entries[log->size].time = time;
    log->entries[log->size].value = value;
    log->size++;
}

void print_log(log_t *log) {
    int i;
    for (i = 0; i < log->size; i++) {
        printf("%.2f %f\n", log->entries[i].time, log->entries[i].value);
    }
}

int main() {
    log_t *log = create_log(10);

    add_log_entry(log, 1.0, 10.0);
    add_log_entry(log, 2.0, 20.0);
    add_log_entry(log, 3.0, 30.0);
    add_log_entry(log, 4.0, 40.0);

    print_log(log);

    return 0;
}