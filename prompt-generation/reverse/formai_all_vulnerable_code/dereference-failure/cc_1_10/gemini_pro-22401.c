//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a log entry
typedef struct log_entry {
    char *timestamp;
    char *level;
    char *message;
} log_entry;

// Read a log file and store the entries in an array
int read_log(const char *filename, log_entry **entries) {
    // Open the log file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    // Allocate memory for the array of log entries
    *entries = malloc(sizeof(log_entry));
    if (*entries == NULL) {
        fclose(fp);
        return -1;
    }

    // Read the log entries
    int num_entries = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the log entry
        char *timestamp = strtok(line, " ");
        char *level = strtok(NULL, " ");
        char *message = strtok(NULL, "\n");

        // Allocate memory for the log entry
        *entries = realloc(*entries, (num_entries + 1) * sizeof(log_entry));
        if (*entries == NULL) {
            fclose(fp);
            return -1;
        }

        // Store the log entry
        (*entries)[num_entries].timestamp = strdup(timestamp);
        (*entries)[num_entries].level = strdup(level);
        (*entries)[num_entries].message = strdup(message);

        num_entries++;
    }

    // Close the log file
    fclose(fp);

    return num_entries;
}

// Print the log entries
void print_log(log_entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s %s\n", entries[i].timestamp, entries[i].level, entries[i].message);
    }
}

// Free the memory allocated for the log entries
void free_log(log_entry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].timestamp);
        free(entries[i].level);
        free(entries[i].message);
    }
    free(entries);
}

int main() {
    // Read the log file
    log_entry *entries;
    int num_entries = read_log("log.txt", &entries);
    if (num_entries == -1) {
        fprintf(stderr, "Error reading log file\n");
        return EXIT_FAILURE;
    }

    // Print the log entries
    print_log(entries, num_entries);

    // Free the memory allocated for the log entries
    free_log(entries, num_entries);

    return EXIT_SUCCESS;
}