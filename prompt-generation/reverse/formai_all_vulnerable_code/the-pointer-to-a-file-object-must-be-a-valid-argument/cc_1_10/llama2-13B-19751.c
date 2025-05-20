//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_SIZE 256

// Structure to hold log data
typedef struct {
    char timestamp[20];
    char username[20];
    char message[MAX_LINE_SIZE];
} log_data_t;

// Function to parse log file
void parse_log(const char* log_file) {
    // Open log file
    FILE* log_fp = fopen(log_file, "r");

    // Check if log file is empty
    if (feof(log_fp)) {
        printf("Log file is empty!\n");
        return;
    }

    // Read log file line by line
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, log_fp)) {
        // Extract timestamp and username
        char* timestamp = strtok(line, " ");
        char* username = strtok(NULL, " ");

        // Create log data struct
        log_data_t log_data;
        strcpy(log_data.timestamp, timestamp);
        strcpy(log_data.username, username);
        strcpy(log_data.message, line);

        // Print log data
        printf("[%s] %s: %s\n", log_data.timestamp, log_data.username, log_data.message);
    }

    // Close log file
    fclose(log_fp);
}

// Example usage
int main() {
    // Log file path
    const char* log_file = "/path/to/log.txt";

    // Parse log file
    parse_log(log_file);

    return 0;
}