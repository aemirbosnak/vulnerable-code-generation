//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

// Define the facility and priority levels for the logger
#define FACILITY LOG_LOCAL0
#define PRIORITY LOG_INFO

// Define the maximum length of the log message
#define MAX_LOG_MESSAGE_LENGTH 1024

// Open the system event logger
void open_logger(void) {
    // Set the facility and priority levels for the logger
    openlog("myapp", LOG_PID, FACILITY);
}

// Close the system event logger
void close_logger(void) {
    // Close the logger
    closelog();
}

// Log a message to the system event logger
void log_message(const char *message) {
    // Log the message to the logger
    syslog(PRIORITY, "%s", message);
}

// Get the current time as a string
char *get_current_time(void) {
    // Get the current time
    time_t current_time = time(NULL);

    // Convert the current time to a string
    char *current_time_string = ctime(&current_time);

    // Remove the newline character from the end of the string
    current_time_string[strlen(current_time_string) - 1] = '\0';

    // Return the current time string
    return current_time_string;
}

// Main function
int main(void) {
    // Open the system event logger
    open_logger();

    // Log a message to the logger
    log_message("This is a test message.");

    // Get the current time as a string
    char *current_time_string = get_current_time();

    // Log the current time to the logger
    log_message(current_time_string);

    // Close the system event logger
    close_logger();

    return 0;
}