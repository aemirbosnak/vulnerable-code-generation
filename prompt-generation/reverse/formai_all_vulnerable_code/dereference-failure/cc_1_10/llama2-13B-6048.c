//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_SIZE 100000

struct log_entry {
    time_t timestamp;
    char *message;
};

void parse_log_line(char *line, struct log_entry *entry) {
    char *timestamp_str;
    char *message_str;

    timestamp_str = strtok(line, " ");
    message_str = strtok(NULL, "\n");

    entry->timestamp = strtol(timestamp_str, NULL, 10);
    entry->message = message_str;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    FILE *log_fp = fopen(log_file, "r");
    if (!log_fp) {
        perror("Failed to open log file");
        return 2;
    }

    struct log_entry *log_entries = calloc(1, sizeof(struct log_entry));
    size_t num_entries = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, log_fp)) {
        struct log_entry *entry = realloc(log_entries, (num_entries + 1) * sizeof(struct log_entry));
        if (!entry) {
            perror("Failed to allocate memory");
            break;
        }
        log_entries = entry;

        parse_log_line(line, &log_entries[num_entries]);
        num_entries++;
    }

    // Print statistics
    printf("Log file statistics:\n");
    printf("------------------------\n");
    printf("Total number of entries: %zu\n", num_entries);
    printf("Average message length: %f\n", (double)num_entries * (double)strlen(log_entries[0].message) / (double)num_entries);
    printf("Longest message: %s\n", log_entries[0].message);

    // Print each log entry on a separate line
    for (size_t i = 0; i < num_entries; i++) {
        printf("%zu: %s\n", log_entries[i].timestamp, log_entries[i].message);
    }

    free(log_entries);
    fclose(log_fp);

    return 0;
}