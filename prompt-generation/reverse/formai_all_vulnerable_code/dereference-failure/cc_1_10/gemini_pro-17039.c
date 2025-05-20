//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Define the maximum length of a log line
#define MAX_LOG_LINE_LENGTH 1024

// Define the maximum number of log lines to store in memory
#define MAX_LOG_LINES 100

// Define the supported log severities
#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARNING 2
#define LOG_ERROR 3
#define LOG_FATAL 4

// Define the supported log facilities
#define LOG_FACILITY_USER 0
#define LOG_FACILITY_SYSLOG 1

// Define the log line structure
typedef struct {
    int severity;
    int facility;
    char *message;
} log_line;

// Define the log structure
typedef struct {
    log_line *lines;
    int num_lines;
} log;

// Initialize the log
void log_init(log *log) {
    log->lines = NULL;
    log->num_lines = 0;
}

// Add a log line to the log
void log_add_line(log *log, int severity, int facility, const char *message) {
    // Allocate memory for the new log line
    log_line *line = malloc(sizeof(log_line));
    assert(line != NULL);

    // Initialize the new log line
    line->severity = severity;
    line->facility = facility;
    line->message = strdup(message);

    // Add the new log line to the log
    log->lines = realloc(log->lines, (log->num_lines + 1) * sizeof(log_line));
    assert(log->lines != NULL);
    log->lines[log->num_lines] = *line;
    log->num_lines++;
}

// Print the log to the console
void log_print(log *log) {
    for (int i = 0; i < log->num_lines; i++) {
        log_line *line = &log->lines[i];
        printf("%s: %s\n", line->message, line->facility);
    }
}

// Free the memory allocated for the log
void log_free(log *log) {
    for (int i = 0; i < log->num_lines; i++) {
        free(log->lines[i].message);
    }
    free(log->lines);
}

// Main function
int main() {
    // Initialize the log
    log log;
    log_init(&log);

    // Add some log lines to the log
    log_add_line(&log, LOG_DEBUG, LOG_FACILITY_USER, "This is a debug message");
    log_add_line(&log, LOG_INFO, LOG_FACILITY_SYSLOG, "This is an info message");
    log_add_line(&log, LOG_WARNING, LOG_FACILITY_USER, "This is a warning message");
    log_add_line(&log, LOG_ERROR, LOG_FACILITY_SYSLOG, "This is an error message");
    log_add_line(&log, LOG_FATAL, LOG_FACILITY_USER, "This is a fatal message");

    // Print the log to the console
    log_print(&log);

    // Free the memory allocated for the log
    log_free(&log);

    return 0;
}