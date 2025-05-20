//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: authentic
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_LINES 100000

typedef struct {
    char *log_line;
    time_t timestamp;
    char *source;
    char *message;
} log_entry;

log_entry *log_entries;
int num_log_entries;

void parse_log_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    assert(fp != NULL);

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        // Parse the log line.
        log_entry entry;
        entry.log_line = strdup(line);
        entry.timestamp = time(NULL);
        entry.source = strtok(line, " ");
        entry.message = strtok(NULL, "\n");

        // Add the entry to the array of log entries.
        log_entries[num_log_entries++] = entry;
    }

    fclose(fp);
}

void print_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        log_entry entry = log_entries[i];
        printf("%s %s: %s\n", entry.timestamp, entry.source, entry.message);
    }
}

void free_log_entries() {
    for (int i = 0; i < num_log_entries; i++) {
        free(log_entries[i].log_line);
    }
    free(log_entries);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        exit(1);
    }

    // Parse the log file.
    parse_log_file(argv[1]);

    // Print the log entries.
    print_log_entries();

    // Free the log entries.
    free_log_entries();

    return 0;
}