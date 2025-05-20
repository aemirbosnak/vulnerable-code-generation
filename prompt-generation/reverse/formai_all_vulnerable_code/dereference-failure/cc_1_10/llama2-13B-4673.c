//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 5

struct log_entry {
    int timestamp;
    char *message;
};

void parse_log_file(const char *file_name, struct log_entry **log_array) {
    FILE *file = fopen(file_name, "r");
    char line[MAX_LINE_LENGTH];
    int i = 0;

    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char *token = strtok(line, " ");
        int timestamp = atoi(token);
        char *message = token + strcspn(token, " ");

        // Check if the message is empty
        if (message[0] == '\0') {
            continue;
        }

        struct log_entry *new_entry = calloc(1, sizeof(struct log_entry));
        new_entry->timestamp = timestamp;
        new_entry->message = message;

        // Add the new entry to the log array
        log_array[i++] = new_entry;
    }

    fclose(file);
}

void analyze_logs(struct log_entry **log_array, int num_log_files) {
    int i = 0;
    int total_messages = 0;
    int total_timestamp_diff = 0;

    for (int j = 0; j < num_log_files; j++) {
        struct log_entry *log_entry = log_array[j];

        // Increment the total number of messages
        total_messages++;

        // Calculate the timestamp difference between the current log entry and the previous one
        if (i > 0) {
            struct log_entry *prev_log_entry = log_array[i - 1];
            total_timestamp_diff += abs(log_entry->timestamp - prev_log_entry->timestamp);
        }

        i++;
    }

    // Print the analysis results
    printf("Log Analysis Results:\n");
    printf("Total number of messages: %d\n", total_messages);
    printf("Total timestamp difference: %d\n", total_timestamp_diff);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <log_file1> <log_file2> ...\n", argv[0]);
        return 1;
    }

    // Initialize the log array
    struct log_entry *log_array[MAX_LOG_FILES];

    // Parse the log files
    for (int i = 1; i < argc; i++) {
        parse_log_file(argv[i], log_array);
    }

    // Analyze the logs
    analyze_logs(log_array, argc - 1);

    return 0;
}