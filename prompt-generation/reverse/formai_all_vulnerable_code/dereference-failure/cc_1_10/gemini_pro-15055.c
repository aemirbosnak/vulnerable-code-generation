//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold log entry data
typedef struct log_entry {
    char *message;
    int level;
    char *timestamp;
} log_entry;

// Define a function to parse a log entry from a string
log_entry parse_log_entry(char *line) {
    log_entry entry;

    // Split the line into message, level, and timestamp
    char *parts[3];
    int num_parts = 0;
    char *part = strtok(line, " ");
    while (part != NULL && num_parts < 3) {
        parts[num_parts++] = part;
        part = strtok(NULL, " ");
    }

    // Store the message, level, and timestamp in the entry struct
    entry.message = strdup(parts[0]);
    entry.level = atoi(parts[1]);
    entry.timestamp = strdup(parts[2]);

    return entry;
}

// Define a function to print a log entry
void print_log_entry(log_entry entry) {
    printf("[%s] [%d] %s\n", entry.timestamp, entry.level, entry.message);
}

// Define a function to read a log file and print its entries
void read_log_file(char *filename) {
    // Open the log file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    // Read the log file line by line and parse each line
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        log_entry entry = parse_log_entry(line);

        // Print the log entry
        print_log_entry(entry);

        // Free the memory allocated for the log entry
        free(entry.message);
        free(entry.timestamp);
    }

    // Close the log file
    fclose(file);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if a filename was provided as an argument
    if (argc < 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return 1;
    }

    // Read the log file and print its entries
    read_log_file(argv[1]);

    return 0;
}