//Falcon-180B DATASET v1.0 Category: System event logger ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1000
#define MAX_LOG_ENTRY_SIZE 256
#define LOG_FILE_NAME "event_log.txt"

// Struct to hold log entry information
typedef struct {
    char message[MAX_LOG_ENTRY_SIZE];
    time_t timestamp;
} log_entry_t;

// Function to format timestamp as a string
char* format_timestamp(time_t timestamp) {
    struct tm* time_info = localtime(&timestamp);
    char* timestamp_str = malloc(sizeof(char) * 32);
    strftime(timestamp_str, 32, "%Y-%m-%d %H:%M:%S", time_info);
    return timestamp_str;
}

// Function to write log entry to file
void write_log_entry(log_entry_t entry) {
    FILE* log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
    fprintf(log_file, "%s - %s\n", entry.message, format_timestamp(entry.timestamp));
    fclose(log_file);
}

// Function to log an event
void log_event(char* message) {
    log_entry_t entry = {
       .message = message,
       .timestamp = time(NULL)
    };
    write_log_entry(entry);
}

// Function to initialize logging system
void init_logging() {
    FILE* log_file = fopen(LOG_FILE_NAME, "w");
    if (log_file == NULL) {
        printf("Error: Could not create log file.\n");
        exit(1);
    }
    fprintf(log_file, "=============================\n");
    fprintf(log_file, "Logging started on %s\n", format_timestamp(time(NULL)));
    fprintf(log_file, "=============================\n");
    fclose(log_file);
}

// Function to cleanup logging system
void cleanup_logging() {
    FILE* log_file = fopen(LOG_FILE_NAME, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        exit(1);
    }
    fprintf(log_file, "=============================\n");
    fprintf(log_file, "Logging ended on %s\n", format_timestamp(time(NULL)));
    fprintf(log_file, "=============================\n");
    fclose(log_file);
}

int main() {
    init_logging();
    log_event("Program started");
    log_event("Some event occurred");
    log_event("Another event occurred");
    cleanup_logging();
    return 0;
}