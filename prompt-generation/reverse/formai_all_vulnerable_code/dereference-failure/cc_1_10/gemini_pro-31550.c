//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a log entry
typedef struct {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Define the maximum number of log entries to store
#define MAX_LOG_ENTRIES 100

// Define the log file name
#define LOG_FILE_NAME "log.txt"

// Create an array to store the log entries
log_entry log_entries[MAX_LOG_ENTRIES];

// Create a variable to store the number of log entries
int num_log_entries = 0;

// Function to read the log file and store the log entries in the array
void read_log_file() {
    // Open the log file for reading
    FILE *log_file = fopen(LOG_FILE_NAME, "r");

    // Check if the file was opened successfully
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(1);
    }

    // Read the log file line by line
    char line[1024];
    while (fgets(line, sizeof(line), log_file) != NULL) {
        // Parse the log entry
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Allocate memory for the log entry
        log_entry *log_entry = malloc(sizeof(log_entry));

        // Store the log entry in the array
        log_entry->timestamp = strdup(timestamp);
        log_entry->level = strdup(level);
        log_entry->message = strdup(message);

        log_entries[num_log_entries] = *log_entry;
        num_log_entries++;
    }

    // Close the log file
    fclose(log_file);
}

// Function to print the log entries
void print_log_entries() {
    // Iterate over the log entries
    for (int i = 0; i < num_log_entries; i++) {
        // Print the log entry
        printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
    }
}

// Function to filter the log entries by level
void filter_log_entries_by_level(char *level) {
    // Iterate over the log entries
    for (int i = 0; i < num_log_entries; i++) {
        // Check if the log entry level matches the specified level
        if (strcmp(log_entries[i].level, level) == 0) {
            // Print the log entry
            printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
        }
    }
}

// Function to filter the log entries by message
void filter_log_entries_by_message(char *message) {
    // Iterate over the log entries
    for (int i = 0; i < num_log_entries; i++) {
        // Check if the log entry message contains the specified message
        if (strstr(log_entries[i].message, message) != NULL) {
            // Print the log entry
            printf("%s %s %s\n", log_entries[i].timestamp, log_entries[i].level, log_entries[i].message);
        }
    }
}

// Function to free the memory allocated for the log entries
void free_log_entries() {
    // Iterate over the log entries
    for (int i = 0; i < num_log_entries; i++) {
        // Free the memory allocated for the log entry
        free(log_entries[i].timestamp);
        free(log_entries[i].level);
        free(log_entries[i].message);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Read the log file
    read_log_file();

    // Print the log entries
    print_log_entries();

    // Filter the log entries by level
    filter_log_entries_by_level("ERROR");

    // Filter the log entries by message
    filter_log_entries_by_message("failed");

    // Free the memory allocated for the log entries
    free_log_entries();

    return 0;
}