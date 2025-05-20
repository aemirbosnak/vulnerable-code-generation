//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a log level enum
typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
} log_level;

// Define a log message struct
typedef struct {
    log_level level;
    char *message;
} log_message;

// Create a log function that takes a log message as an argument
void log(log_message *message) {
    // Print the log message to the console
    switch (message->level) {
        case LOG_LEVEL_DEBUG:
            printf("[DEBUG] %s\n", message->message);
            break;
        case LOG_LEVEL_INFO:
            printf("[INFO] %s\n", message->message);
            break;
        case LOG_LEVEL_WARN:
            printf("[WARN] %s\n", message->message);
            break;
        case LOG_LEVEL_ERROR:
            printf("[ERROR] %s\n", message->message);
            break;
        case LOG_LEVEL_FATAL:
            printf("[FATAL] %s\n", message->message);
            break;
    }

    // Free the allocated memory for the log message
    free(message->message);
    free(message);
}

// Create a main function
int main() {
    // Create a log message
    log_message *message = malloc(sizeof(log_message));
    message->level = LOG_LEVEL_INFO;
    message->message = malloc(strlen("Hello, world!") + 1);
    strcpy(message->message, "Hello, world!");

    // Log the message
    log(message);

    return 0;
}