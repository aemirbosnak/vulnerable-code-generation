//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_LOG_LINE_LENGTH 1024
#define MAX_ERROR_COUNT 10

// Structure to hold log line information
typedef struct {
    char *message;
    int severity;
} log_line_t;

// Function to parse log line and return severity
int parse_log_line(const char *log_line, log_line_t *log_line_info) {
    int i;
    char *severity_str;

    // Extract message and severity from log line
    log_line_info->message = strtok(log_line, ": ");
    severity_str = strtok(NULL, ":");

    // Convert severity to integer
    if (strcmp(severity_str, "ERROR") == 0) {
        log_line_info->severity = MAX_ERROR_COUNT;
    } else if (strcmp(severity_str, "WARNING") == 0) {
        log_line_info->severity = MAX_ERROR_COUNT - 1;
    } else {
        log_line_info->severity = 0;
    }

    return log_line_info->severity;
}

// Function to process log file and produce report
void process_log(const char *log_file_name) {
    FILE *log_file = fopen(log_file_name, "r");
    char log_line[MAX_LOG_LINE_LENGTH];
    log_line_t log_line_info;
    int error_count = 0;

    // Read log file line by line
    while (fgets(log_line, MAX_LOG_LINE_LENGTH, log_file) != NULL) {
        // Parse log line and get severity
        parse_log_line(log_line, &log_line_info);

        // Increment error count for errors and warnings
        if (log_line_info.severity >= MAX_ERROR_COUNT) {
            error_count++;
        }

        // Print log line and severity
        printf("%s (%d): %s\n", log_file_name, log_line_info.severity, log_line_info.message);
    }

    // Print report on error and warning counts
    printf("Error Count: %d\n", error_count);
    printf("Warning Count: %d\n", error_count - error_count);

    fclose(log_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <log_file_name>\n", argv[0]);
        return 1;
    }

    process_log(argv[1]);

    return 0;
}