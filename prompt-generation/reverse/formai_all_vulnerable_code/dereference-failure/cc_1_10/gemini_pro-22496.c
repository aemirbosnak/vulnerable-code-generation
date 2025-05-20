//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 1000

// Structure to store a single log entry
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Array to store all log entries
log_entry log_entries[MAX_NUM_LINES];

// Function to parse a single line of log data
void parse_log_line(char *line, log_entry *entry) {
    // Split the line into timestamp, level, and message
    char *timestamp = strtok(line, " ");
    char *level = strtok(NULL, " ");
    char *message = strtok(NULL, "\n");

    // Copy the timestamp, level, and message into the entry struct
    entry->timestamp = strdup(timestamp);
    entry->level = strdup(level);
    entry->message = strdup(message);
}

// Function to read log data from a file
int read_log_data(char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read each line of the file
    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Parse the log line
        parse_log_line(line, &log_entries[line_num]);

        // Increment the line number
        line_num++;
    }

    // Close the file
    fclose(file);

    // Return the number of lines read
    return line_num;
}

// Function to print a log entry
void print_log_entry(log_entry *entry) {
    // Print the timestamp, level, and message
    printf("%s %s %s\n", entry->timestamp, entry->level, entry->message);
}

// Function to filter log entries by level
void filter_log_entries(char *level) {
    // Iterate over all log entries
    for (int i = 0; i < MAX_NUM_LINES; i++) {
        // If the log entry level matches the specified level, print it
        if (strcmp(log_entries[i].level, level) == 0) {
            print_log_entry(&log_entries[i]);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified a log file
    if (argc != 2) {
        printf("Usage: %s <log file>\n", argv[0]);
        return -1;
    }

    // Read the log data from the file
    int num_lines = read_log_data(argv[1]);
    if (num_lines == -1) {
        return -1;
    }

    // Filter the log entries by level
    filter_log_entries("ERROR");

    return 0;
}