//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the structure of a log entry
typedef struct log_entry {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Define the function to parse a log line
log_entry *parse_log_line(char *line) {
    // Allocate memory for the log entry
    log_entry *entry = malloc(sizeof(log_entry));

    // Parse the timestamp
    char *timestamp = strtok(line, " ");
    entry->timestamp = malloc(strlen(timestamp) + 1);
    strcpy(entry->timestamp, timestamp);

    // Parse the level
    char *level = strtok(NULL, " ");
    entry->level = malloc(strlen(level) + 1);
    strcpy(entry->level, level);

    // Parse the message
    char *message = strtok(NULL, "\n");
    entry->message = malloc(strlen(message) + 1);
    strcpy(entry->message, message);

    // Return the log entry
    return entry;
}

// Define the function to print a log entry
void print_log_entry(log_entry *entry) {
    // Print the timestamp
    printf("%s ", entry->timestamp);

    // Print the level
    printf("%s ", entry->level);

    // Print the message
    printf("%s\n", entry->message);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a log file
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the log file
    FILE *log_file = fopen(argv[1], "r");
    if (log_file == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the log file line by line
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log_file)) {
        // Parse the log line
        log_entry *entry = parse_log_line(line);

        // Print the log entry
        print_log_entry(entry);

        // Free the memory allocated for the log entry
        free(entry->timestamp);
        free(entry->level);
        free(entry->message);
        free(entry);
    }

    // Close the log file
    fclose(log_file);

    return EXIT_SUCCESS;
}