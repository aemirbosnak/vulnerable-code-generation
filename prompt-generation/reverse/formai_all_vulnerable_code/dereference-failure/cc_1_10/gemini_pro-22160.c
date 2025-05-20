//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of lines in the log file
#define MAX_LINES 1000

// Define the maximum length of a line in the log file
#define MAX_LINE_LENGTH 1024

// Define the structure of a log entry
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Define the function to read the log file into an array of log entries
int read_log_file(char *filename, log_entry *log_entries) {
    // Open the log file for reading
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Read the first line of the log file
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return -1;
    }

    // Parse the first line of the log file to get the number of lines in the file
    int num_lines = atoi(line);

    // Allocate memory for the array of log entries
    log_entries = (log_entry *)malloc(sizeof(log_entry) * num_lines);
    if (log_entries == NULL) {
        return -1;
    }

    // Read the rest of the lines in the log file
    for (int i = 0; i < num_lines; i++) {
        // Read the next line of the log file
        if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
            return -1;
        }

        // Parse the line to get the timestamp, level, and message
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Store the timestamp, level, and message in the log entry
        log_entries[i].timestamp = timestamp;
        log_entries[i].level = level;
        log_entries[i].message = message;
    }

    // Close the log file
    fclose(fp);

    return 0;
}

// Define the function to print the log entries to the console
void print_log_entries(log_entry *log_entries, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }
}

// Define the function to free the memory allocated for the array of log entries
void free_log_entries(log_entry *log_entries, int num_lines) {
    for (int i = 0; i < num_lines; i++) {
        free(log_entries[i].timestamp);
        free(log_entries[i].level);
        free(log_entries[i].message);
    }
    free(log_entries);
}

// Define the main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a log file name
    if (argc < 2) {
        printf("Usage: %s <log file name>\n", argv[0]);
        return -1;
    }

    // Read the log file into an array of log entries
    log_entry *log_entries;
    int num_lines = read_log_file(argv[1], log_entries);
    if (num_lines == -1) {
        printf("Error reading log file\n");
        return -1;
    }

    // Print the log entries to the console
    print_log_entries(log_entries, num_lines);

    // Free the memory allocated for the array of log entries
    free_log_entries(log_entries, num_lines);

    return 0;
}