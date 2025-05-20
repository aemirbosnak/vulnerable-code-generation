//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "log.txt"

typedef struct {
    time_t timestamp;
    char *message;
} log_entry;

log_entry *log_entries;
int num_log_entries = 0;

void log_init(void) {
    FILE *fp = fopen(LOG_FILE, "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fclose(fp);
}

void log_entry_create(char *message) {
    log_entries = realloc(log_entries, (num_log_entries + 1) * sizeof(log_entry));
    log_entries[num_log_entries].timestamp = time(NULL);
    log_entries[num_log_entries].message = strdup(message);
    num_log_entries++;
}

void log_entry_destroy(log_entry *entry) {
    free(entry->message);
}

void log_entry_print(log_entry *entry) {
    printf("%ld %s", entry->timestamp, entry->message);
}

void log_print(void) {
    for (int i = 0; i < num_log_entries; i++) {
        log_entry_print(&log_entries[i]);
    }
}

void log_destroy(void) {
    for (int i = 0; i < num_log_entries; i++) {
        log_entry_destroy(&log_entries[i]);
    }
    free(log_entries);
}

int main(int argc, char **argv) {
    log_init();
    log_entry_create("Hello, world!");
    log_entry_create("This is a test.");
    log_entry_create("Goodbye, world!");
    log_print();
    log_destroy();
    return 0;
}