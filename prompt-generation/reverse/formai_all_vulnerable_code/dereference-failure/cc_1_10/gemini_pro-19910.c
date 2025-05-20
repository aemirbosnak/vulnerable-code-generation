//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

// Define the event types
#define EVENT_LOG_INFO 0
#define EVENT_LOG_WARNING 1
#define EVENT_LOG_ERROR 2

// Define the event logger struct
typedef struct {
    int type;
    char *message;
    time_t timestamp;
} event_log_t;

// Create the event logger
event_log_t *event_logger_create() {
    event_log_t *logger = malloc(sizeof(event_log_t));
    if (logger == NULL) {
        return NULL;
    }
    logger->type = EVENT_LOG_INFO;
    logger->message = NULL;
    logger->timestamp = time(NULL);
    return logger;
}

// Destroy the event logger
void event_logger_destroy(event_log_t *logger) {
    if (logger == NULL) {
        return;
    }
    if (logger->message != NULL) {
        free(logger->message);
    }
    free(logger);
}

// Log an event
void event_logger_log(event_log_t *logger, int type, const char *format, ...) {
    if (logger == NULL) {
        return;
    }
    va_list args;
    va_start(args, format);
    logger->type = type;
    logger->timestamp = time(NULL);
    logger->message = malloc(strlen(format) + 1024);
    if (logger->message == NULL) {
        va_end(args);
        return;
    }
    vsprintf(logger->message, format, args);
    va_end(args);
}

// Get the event type
int event_logger_get_type(event_log_t *logger) {
    if (logger == NULL) {
        return -1;
    }
    return logger->type;
}

// Get the event message
const char *event_logger_get_message(event_log_t *logger) {
    if (logger == NULL) {
        return NULL;
    }
    return logger->message;
}

// Get the event timestamp
time_t event_logger_get_timestamp(event_log_t *logger) {
    if (logger == NULL) {
        return -1;
    }
    return logger->timestamp;
}

// Print the event to the console
void event_logger_print(event_log_t *logger) {
    if (logger == NULL) {
        return;
    }
    printf("%s: %s\n", ctime(&logger->timestamp), logger->message);
}

// Main function
int main() {
    // Create the event logger
    event_log_t *logger = event_logger_create();
    if (logger == NULL) {
        return EXIT_FAILURE;
    }

    // Log some events
    event_logger_log(logger, EVENT_LOG_INFO, "Starting program");
    event_logger_log(logger, EVENT_LOG_WARNING, "Encountered an error");
    event_logger_log(logger, EVENT_LOG_ERROR, "Program crashed");

    // Print the events to the console
    event_logger_print(logger);

    // Destroy the event logger
    event_logger_destroy(logger);

    return EXIT_SUCCESS;
}