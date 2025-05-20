//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10

struct log_entry {
    time_t timestamp;
    char *message;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    char *log_file = argv[1];
    char *log_content = NULL;
    size_t log_content_size = 0;

    // Open the log file and read its contents
    FILE *log_file_ptr = fopen(log_file, "r");
    if (log_file_ptr == NULL) {
        perror("Error opening log file");
        return 2;
    }

    // Read the log file contents into a buffer
    log_content_size = fread(log_content, 1, MAX_LINE_LENGTH, log_file_ptr);
    log_content[log_content_size] = '\0';

    // Tokenize the log content into individual lines
    char *token = strtok(log_content, "\n");
    struct log_entry *log_entries = calloc(1, sizeof(struct log_entry));
    int i = 0;

    while (token != NULL) {
        // Extract the timestamp and message from each line
        char *timestamp_str = strtok(token, ":");
        char *message_str = strtok(NULL, "\0");

        struct log_entry *new_entry = calloc(1, sizeof(struct log_entry));
        new_entry->timestamp = strtol(timestamp_str, NULL, 10);
        new_entry->message = message_str;

        // Add the entry to the list
        log_entries[i++] = *new_entry;

        // Advance to the next line
        token = strtok(NULL, "\n");
    }

    // Print the log entries in reverse chronological order
    for (int i = i - 1; i >= 0; i--) {
        struct log_entry *entry = log_entries + i;
        printf("%ld: %s\n", entry->timestamp, entry->message);
    }

    // Free memory
    free(log_content);
    free(log_entries);

    return 0;
}