//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the log entry data
struct log_entry {
    char *timestamp;
    char *level;
    char *message;
};

// Function to parse a log entry from a line of text
struct log_entry *parse_log_entry(char *line) {
    // Allocate memory for the log entry
    struct log_entry *entry = malloc(sizeof(struct log_entry));

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

// Function to print a log entry
void print_log_entry(struct log_entry *entry) {
    printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

// Main function
int main() {
    // Open the log file
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        perror("Error opening log file");
        return EXIT_FAILURE;
    }

    // Parse the log file
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the log entry
        struct log_entry *entry = parse_log_entry(line);

        // Print the log entry
        print_log_entry(entry);

        // Free the memory allocated for the log entry
        free(entry->timestamp);
        free(entry->level);
        free(entry->message);
        free(entry);
    }

    // Close the log file
    fclose(file);

    return EXIT_SUCCESS;
}