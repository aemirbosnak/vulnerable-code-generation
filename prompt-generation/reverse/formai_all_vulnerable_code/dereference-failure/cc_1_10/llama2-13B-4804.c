//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LINE_LENGTH 1024
#define MAX_LOG_FILES 10

// Structure to store log data
typedef struct {
    char *file_name;
    char *message;
    time_t timestamp;
} log_data_t;

// Function to parse log files and store data in a struct
void parse_log_file(const char *file_name, log_data_t *log_data) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Skip empty lines and comments
        if (strlen(line) == 0 || line[0] == '#') {
            continue;
        }
        // Extract timestamp and message
        char *timestamp = strtok(line, ":");
        char *message = strtok(NULL, "\n");
        log_data->timestamp = strtol(timestamp, NULL, 10);
        log_data->message = message;
        break;
    }
    fclose(file);
}

// Function to print log data
void print_log_data(log_data_t *log_data) {
    printf("%s: %s (%ld)\n", log_data->file_name, log_data->message, log_data->timestamp);
}

int main(int argc, char *argv[]) {
    // Process command line arguments
    if (argc != 2) {
        printf("Usage: %s <log_file_path>\n", argv[0]);
        return 1;
    }
    // Open log files and store data in a struct
    log_data_t log_data;
    parse_log_file(argv[1], &log_data);
    // Print log data
    print_log_data(&log_data);
    return 0;
}