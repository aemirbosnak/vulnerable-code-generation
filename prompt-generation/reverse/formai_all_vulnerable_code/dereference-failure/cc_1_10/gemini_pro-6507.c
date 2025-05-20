//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LOG_SIZE (1024 * 1024)
#define MAX_LOG_LINES 10000

typedef struct {
    time_t timestamp;
    char level;
    char *message;
} log_entry;

log_entry *log_entries;
int num_log_entries;

void log_init() {
    log_entries = malloc(sizeof(log_entry) * MAX_LOG_LINES);
    if (log_entries == NULL) {
        fprintf(stderr, "Error allocating memory for log entries\n");
        exit(1);
    }
    num_log_entries = 0;
}

void log_fini() {
    free(log_entries);
}

void log_add(char level, char *message) {
    if (num_log_entries >= MAX_LOG_LINES) {
        fprintf(stderr, "Error: Log is full\n");
        return;
    }

    log_entries[num_log_entries].timestamp = time(NULL);
    log_entries[num_log_entries].level = level;
    log_entries[num_log_entries].message = strdup(message);
    num_log_entries++;
}

void log_print() {
    for (int i = 0; i < num_log_entries; i++) {
        printf("%s %c %s\n", ctime(&log_entries[i].timestamp), log_entries[i].level, log_entries[i].message);
    }
}

int main() {
    log_init();

    log_add('E', "Error: Could not open file");
    log_add('W', "Warning: File is too large");
    log_add('I', "Info: File was successfully opened");

    log_print();

    log_fini();

    return 0;
}