//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 256

// Structure to store log data
typedef struct {
    char *message;
    time_t timestamp;
} log_entry_t;

// Function to read log file
log_entry_t *read_log(char *log_file) {
    // Open log file in read mode
    FILE *log_fp = fopen(log_file, "r");

    // Check if log file is empty
    if (feof(log_fp)) {
        return NULL;
    }

    // Create a new log entry
    log_entry_t *entry = (log_entry_t *)calloc(1, sizeof(log_entry_t));

    // Read log entry from file
    char buffer[MAX_LINE_LENGTH];
    fgets(buffer, MAX_LINE_LENGTH, log_fp);
    entry->message = strdup(buffer);

    // Get timestamp from log entry
    struct tm *tm = localtime(&entry->timestamp);
    entry->timestamp = mktime(tm);

    return entry;
}

// Function to print log entries
void print_log(log_entry_t *entries) {
    // Print log entries in reverse chronological order
    for (int i = 0; i < sizeof(entries) / sizeof(log_entry_t *); i++) {
        log_entry_t *entry = entries + i;
        printf("%s (%ld)\n", entry->message, entry->timestamp);
    }
}

int main() {
    // Open log file
    char *log_file = "romantic_log.txt";
    FILE *log_fp = fopen(log_file, "r");

    // Read log entries
    log_entry_t *entries = read_log(log_file);

    // Print log entries
    print_log(entries);

    // Close log file
    fclose(log_fp);

    return 0;
}