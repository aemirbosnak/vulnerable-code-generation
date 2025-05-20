//FormAI DATASET v1.0 Category: Log analysis ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000

typedef struct {
    char *timestamp;
    char *message;
} log_entry;

int main() {
    log_entry *log_entries[MAX_LOG_ENTRIES];
    int num_entries = 0;

    FILE *log_file = fopen("example.log", "r");
    if (!log_file) {
        printf("Error opening log file\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *delim = " - ";

    while ((read = getline(&line, &len, log_file)) != -1) {
        char *timestamp = strtok(line, delim);
        char *message = strtok(NULL, delim);

        log_entry *entry = (log_entry*) malloc(sizeof(log_entry));
        entry->timestamp = strdup(timestamp);
        entry->message = strdup(message);

        log_entries[num_entries++] = entry;
    }

    fclose(log_file);

    printf("Found %d log entries\n\n", num_entries);

    // Loop through log entries and look for specific errors
    int num_errors = 0;
    for (int i = 0; i < num_entries; i++) {
        log_entry *entry = log_entries[i];

        if (strstr(entry->message, "Error") != NULL) {
            printf("%s - %s", entry->timestamp, entry->message);
            num_errors++;
        }
    }

    printf("\n\nFound %d errors\n", num_errors);

    // Free memory for log entries
    for (int i = 0; i < num_entries; i++) {
        log_entry *entry = log_entries[i];
        free(entry->timestamp);
        free(entry->message);
        free(entry);
    }

    if (line) {
        free(line);
    }

    return 0;
}