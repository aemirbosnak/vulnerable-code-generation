//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define MAX_LINE_LENGTH 256

// Structure to store log data
typedef struct {
    char timestamp[20];  // Timestamp in ISO 8601 format
    char level[10];      // Log level (DEBUG, INFO, WARNING, ERROR)
    char message[256];  // Log message
} log_data_t;

// Function to parse log data from a file
log_data_t *parse_log_file(const char *file_path) {
    log_data_t *log_data = NULL;
    size_t line_num = 0;
    size_t line_len = 0;
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(file_path, "r");

    if (file == NULL) {
        perror("Error opening log file");
        return NULL;
    }

    // Skip first line (timestamp)
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        goto error;
    }

    // Parse log data lines
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        line_num++;

        // Trim whitespace from line
        line_len = strcspn(line, "\n\r");
        line[line_len] = '\0';

        // Extract timestamp and log level
        strcpy(log_data->timestamp, line);
        log_data->timestamp[19] = '\0'; // Truncate timestamp to 20 char max
        log_data->level[0] = line[10];  // Extract log level from first 10 char
        log_data->level[1] = '\0'; // Truncate log level to 10 char max

        // Extract log message
        log_data->message[0] = '\0';
        if (line_len > 10) {
            strncat(log_data->message, line + 11, line_len - 11);
        }

        // Check if log message is too long
        if (strlen(log_data->message) > MAX_LINE_LENGTH - 11) {
            log_data->message[MAX_LINE_LENGTH - 11] = '\0';
        }
    }

error:
    fclose(file);
    return log_data;
}

// Function to print log data
void print_log_data(log_data_t *log_data) {
    printf("Log Data:\n");
    printf("Timestamp: %s\n", log_data->timestamp);
    printf("Log Level: %s\n", log_data->level);
    printf("Message: %s\n", log_data->message);
}

int main() {
    // Example usage of log analysis
    log_data_t *log_data = parse_log_file("example_log.txt");
    print_log_data(log_data);

    return 0;
}