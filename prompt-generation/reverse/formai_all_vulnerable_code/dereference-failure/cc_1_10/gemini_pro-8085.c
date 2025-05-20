//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold log entry
typedef struct {
    char *timestamp;
    char *message;
} LogEntry;

// Function to compare two log entries
int compare_log_entries(const void *a, const void *b) {
    const LogEntry *entry1 = (const LogEntry *)a;
    const LogEntry *entry2 = (const LogEntry *)b;
    return strcmp(entry1->timestamp, entry2->timestamp);
}

// Function to read log entries from a file
void read_log_entries(char *filename, LogEntry **entries, int *num_entries) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of log entries
    int num_entries_read;
    fscanf(file, "%d\n", &num_entries_read);

    // Allocate memory for the log entries
    *entries = (LogEntry *)malloc(num_entries_read * sizeof(LogEntry));

    // Read the log entries
    for (int i = 0; i < num_entries_read; i++) {
        // Allocate memory for the timestamp and message
        (*entries)[i].timestamp = (char *)malloc(256);
        (*entries)[i].message = (char *)malloc(256);

        // Read the timestamp and message
        fscanf(file, "%s %s\n", (*entries)[i].timestamp, (*entries)[i].message);
    }

    fclose(file);

    *num_entries = num_entries_read;
}

// Function to print log entries
void print_log_entries(LogEntry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        printf("%s %s\n", entries[i].timestamp, entries[i].message);
    }
}

// Function to free log entries
void free_log_entries(LogEntry *entries, int num_entries) {
    for (int i = 0; i < num_entries; i++) {
        free(entries[i].timestamp);
        free(entries[i].message);
    }
    free(entries);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Read the log entries from the file
    LogEntry *entries;
    int num_entries;
    read_log_entries(argv[1], &entries, &num_entries);

    // Sort the log entries by timestamp
    qsort(entries, num_entries, sizeof(LogEntry), compare_log_entries);

    // Print the log entries
    print_log_entries(entries, num_entries);

    // Free the log entries
    free_log_entries(entries, num_entries);

    return 0;
}