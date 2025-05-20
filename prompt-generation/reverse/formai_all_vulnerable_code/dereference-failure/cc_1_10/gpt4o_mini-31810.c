//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_SIZE 256

// Enum for event types
typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} EventType;

// Function to log an event
void log_event(EventType type, const char *message) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for writing.\n");
        return;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    // Remove the newline character from ctime output
    time_str[strlen(time_str) - 1] = '\0'; 

    const char *event_type_str;
    switch (type) {
        case INFO: event_type_str = "INFO"; break;
        case WARNING: event_type_str = "WARNING"; break;
        case ERROR: event_type_str = "ERROR"; break;
        case DEBUG: event_type_str = "DEBUG"; break;
        default: event_type_str = "UNKNOWN"; break;
    }

    fprintf(log_file, "[%s] %s: %s\n", time_str, event_type_str, message);
    fclose(log_file);
}

// Function to simulate some events
void simulate_events() {
    log_event(INFO, "Application started successfully.");
    log_event(DEBUG, "Debugging application flow.");
    log_event(WARNING, "Low memory warning.");
    log_event(ERROR, "An error occurred while processing data.");
    log_event(INFO, "User logged in.");
    log_event(DEBUG, "User settings loaded.");
    log_event(INFO, "Operation completed successfully.");
}

// Function to read and display events from the log file
void display_log() {
    FILE *log_file = fopen(LOG_FILE, "r");
    if (log_file == NULL) {
        fprintf(stderr, "Could not open log file for reading.\n");
        return;
    }

    char log_line[MAX_LOG_SIZE];
    printf("Event Log:\n");
    while (fgets(log_line, sizeof(log_line), log_file) != NULL) {
        printf("%s", log_line);
    }
    fclose(log_file);
}

// Main function to execute the event logger
int main() {
    // Initialize the log file
    FILE *log_file = fopen(LOG_FILE, "w");
    if (log_file == NULL) {
        fprintf(stderr, "Could not create log file.\n");
        return EXIT_FAILURE;
    }
    fclose(log_file);

    // Simulate logging of events
    simulate_events();

    // Display the logged events
    display_log();

    return EXIT_SUCCESS;
}