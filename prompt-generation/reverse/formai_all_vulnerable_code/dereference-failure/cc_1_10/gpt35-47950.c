//FormAI DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the log file path
#define LOG_FILE_PATH "sample_log_file.log"

// Define the maximum line length
#define MAX_LINE_LENGTH 1024

// Struct to store log entries
typedef struct {
    char level[10];
    char message[MAX_LINE_LENGTH];
} LogEntry;

// Function to parse a line from the log file
LogEntry parse_log_line(char* line) {
    LogEntry entry;

    // Parse the log level
    char *level_pos = strchr(line, ']') + 2;
    char *message_pos = strchr(level_pos, ' ');

    strncpy(entry.level, level_pos, message_pos - level_pos);
    entry.level[message_pos - level_pos] = '\0';

    // Parse the log message
    strncpy(entry.message, message_pos + 1, strlen(message_pos) - 2);

    return entry;
}

int main() {
    // Open the log file
    FILE *log_file = fopen(LOG_FILE_PATH, "r");

    // Check if the log file was opened successfully
    if (!log_file) {
        printf("Failed to open log file!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize an array to store log entries
    LogEntry entries[1000];

    // Parse each line from the log file
    char line[MAX_LINE_LENGTH];
    int num_entries = 0;
    while (fgets(line, MAX_LINE_LENGTH, log_file)) {
        LogEntry entry = parse_log_line(line);
        entries[num_entries++] = entry;
    }

    // Close the log file
    fclose(log_file);

    // Print the parsed log entries
    for (int i = 0; i < num_entries; i++) {
        printf("Log entry %d:\n", i);
        printf("  Level: %s\n", entries[i].level);
        printf("  Message: %s\n", entries[i].message);
    }

    return 0;
}