//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the structure of a log entry
typedef struct log_entry {
    time_t timestamp;
    char *message;
} log_entry;

// Define the structure of a log file
typedef struct log_file {
    FILE *file;
    char *filename;
} log_file;

// Open a log file
log_file* open_log_file(char *filename) {
    log_file *log = malloc(sizeof(log_file));
    log->file = fopen(filename, "a");
    log->filename = strdup(filename);
    return log;
}

// Close a log file
void close_log_file(log_file *log) {
    fclose(log->file);
    free(log->filename);
    free(log);
}

// Write a log entry to a log file
void write_log_entry(log_file *log, log_entry *entry) {
    fprintf(log->file, "[%s] %s\n", ctime(&entry->timestamp), entry->message);
}

// Read a log file and print its contents
void read_log_file(log_file *log) {
    char line[MAX_LOG_LINE_LENGTH];
    while (fgets(line, MAX_LOG_LINE_LENGTH, log->file)) {
        printf("%s", line);
    }
}

// Main function
int main() {
    // Open a log file
    log_file *log = open_log_file("my_log.txt");

    // Create a log entry
    log_entry entry;
    entry.timestamp = time(NULL);
    entry.message = "This is a log entry.";

    // Write the log entry to the log file
    write_log_entry(log, &entry);

    // Close the log file
    close_log_file(log);

    // Read the log file and print its contents
    log = open_log_file("my_log.txt");
    read_log_file(log);
    close_log_file(log);

    return 0;
}