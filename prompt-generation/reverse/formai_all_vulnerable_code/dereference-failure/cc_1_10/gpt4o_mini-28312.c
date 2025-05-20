//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function declarations
void log_event(const char *event);
void log_error(const char *error_msg);
void log_info(const char *info_msg);
void initialize_logger(const char *filename);
void flush_log();
void close_logger();

// Global Variables
FILE *logfile;

int main() {
    // Initialize the logger
    initialize_logger("event_log.txt");

    // Log some events
    log_event("Program started");
    log_info("Initializing components...");
    
    // Simulating some operations
    for (int i = 0; i < 5; ++i) {
        char event[50];
        sprintf(event, "Operation %d completed", i + 1);
        log_event(event);
        
        // Simulate an error on the third operation
        if (i == 2) {
            log_error("An error occurred during operation 3");
        }
    }

    log_event("Program finished");

    // Close the logger
    close_logger();
    return 0;
}

/**
 * @brief Initialize the logger to write to the specified file.
 */
void initialize_logger(const char *filename) {
    logfile = fopen(filename, "a");
    if (logfile == NULL) {
        fprintf(stderr, "Error: Could not open log file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    log_event("Logger initialized");
}

/**
 * @brief Log a generic event with a timestamp.
 */
void log_event(const char *event) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    fprintf(logfile, "[%s] EVENT: %s\n", timestamp, event);
    fflush(logfile); // Ensure it writes to the file immediately
}

/**
 * @brief Log an error message with a timestamp.
 */
void log_error(const char *error_msg) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    fprintf(logfile, "[%s] ERROR: %s\n", timestamp, error_msg);
}

/**
 * @brief Log an informational message with a timestamp.
 */
void log_info(const char *info_msg) {
    time_t now;
    time(&now);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character
    fprintf(logfile, "[%s] INFO: %s\n", timestamp, info_msg);
}

/**
 * @brief Flush the log to ensure all data is written to the file.
 */
void flush_log() {
    fflush(logfile);
}

/**
 * @brief Close the logger and release the file handle.
 */
void close_logger() {
    if (logfile != NULL) {
        log_event("Logger closed");
        fclose(logfile);
    }
}