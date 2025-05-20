//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_SIZE 256

// Structure to hold log data
typedef struct log_entry {
    char timestamp[20];  // Format: "YYYY-MM-DD HH:MM:SS"
    char source[50];     // Source of the log message (e.g. "server", "client")
    char message[256];   // Log message itself
} log_entry_t;

// Function to parse log data from a file
log_entry_t* parse_log(char* log_file) {
    // Open log file in read mode
    FILE* log_fp = fopen(log_file, "r");

    // Check if log file is empty
    if (feof(log_fp)) {
        return NULL;
    }

    // Initialize log entry struct
    log_entry_t* log_entry = (log_entry_t*) malloc(sizeof(log_entry_t));

    // Read log data from file
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, log_fp)) {
        // Skip empty lines
        if (strcmp(line, "") == 0) {
            continue;
        }

        // Extract timestamp and source from line
        char* timestamp = strtok(line, "-");
        char* source = strtok(NULL, " ");

        // Extract log message from line
        char* message = strtok(NULL, "\n");

        // Initialize log entry struct with extracted data
        strcpy(log_entry->timestamp, timestamp);
        strcpy(log_entry->source, source);
        strcpy(log_entry->message, message);

        // Return log entry struct
        return log_entry;
    }

    // Log file is empty, return NULL
    return NULL;
}

// Function to print log entries
void print_log(log_entry_t* log_entry) {
    printf("Log Entry: %s %s %s\n", log_entry->timestamp, log_entry->source, log_entry->message);
}

int main(int argc, char** argv) {
    // Check if log file path is provided
    if (argc < 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }

    // Parse log data from file
    log_entry_t* log_entry = parse_log(argv[1]);

    // Print log entries
    print_log(log_entry);

    // Free memory
    free(log_entry);

    return 0;
}