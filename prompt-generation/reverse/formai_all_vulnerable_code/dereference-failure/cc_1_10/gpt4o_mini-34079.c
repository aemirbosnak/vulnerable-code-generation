//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "application.log"
#define ERROR_LOG_FILE "error.log"
#define MAX_LOG_LINE_LENGTH 256

typedef enum LogLevel {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} LogLevel;

const char *log_level_to_string(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case DEBUG: return "DEBUG";
        default: return "UNKNOWN";
    }
}

void log_message(LogLevel level, const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (!log_file) {
        fprintf(stderr, "Could not open log file for writing\n");
        return;
    }
    
    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Remove newline
    
    fprintf(log_file, "[%s] %s: %s\n", time_str, log_level_to_string(level), message);
    fclose(log_file);
}

void log_error(const char *error_message) {
    FILE *error_file = fopen(ERROR_LOG_FILE, "a");
    if (!error_file) {
        fprintf(stderr, "Could not open error file for writing\n");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';  // Remove newline
    
    fprintf(error_file, "[%s] ERROR: %s\n", time_str, error_message);
    fclose(error_file);
}

void process_data(int data) {
    if (data < 0) {
        log_error("Invalid data received: Data must be non-negative.");
        return;
    }
    
    log_message(INFO, "Data processing started.");
    
    // Simulated data processing
    if (data % 2 == 0) {
        log_message(DEBUG, "Data event: received even number.");
        // Simulate processing...
    } else {
        log_message(WARNING, "Data event: received odd number, potential issue spotted.");
    }
    
    // Completing data processing
    log_message(INFO, "Data processing completed.");
}

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        log_error("Could not open file for reading.");
        return;
    }
    
    char line[MAX_LOG_LINE_LENGTH];
    log_message(INFO, "File read started.");
    
    while (fgets(line, sizeof(line), file)) {
        log_message(DEBUG, line);
        int data = atoi(line);
        process_data(data);
    }
    
    fclose(file);
    log_message(INFO, "File read completed.");
}

int main(int argc, char *argv[]) {
    log_message(INFO, "Application started.");

    if (argc < 2) {
        log_error("No input file provided.");
        exit(EXIT_FAILURE);
    }

    read_file(argv[1]);
    
    log_message(INFO, "Application finished.");
    return 0;
}