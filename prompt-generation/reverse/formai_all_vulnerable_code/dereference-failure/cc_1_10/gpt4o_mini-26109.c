//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure for the logger
typedef struct {
    FILE *logFile;
} EventLogger;

// Function to get the current timestamp as a string
char* get_current_timestamp() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char *timestamp = malloc(20);
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", t);
    return timestamp;
}

// Function to initialize the logger
EventLogger* init_logger(const char *filename) {
    EventLogger *logger = malloc(sizeof(EventLogger));
    logger->logFile = fopen(filename, "a");
    if (logger->logFile == NULL) {
        fprintf(stderr, "Error opening log file: %s\n", filename);
        free(logger);
        return NULL;
    }
    return logger;
}

// Function to log an event
void log_event(EventLogger *logger, const char *event) {
    char *timestamp = get_current_timestamp();
    fprintf(logger->logFile, "[%s] %s\n", timestamp, event);
    free(timestamp);
    fflush(logger->logFile);
}

// Function to close the logger
void close_logger(EventLogger *logger) {
    if (logger) {
        fclose(logger->logFile);
        free(logger);
    }
}

// Function to simulate a process with logging
void simulate_process(EventLogger *logger) {
    log_event(logger, "Process started.");

    // Simulating user input
    char user_input[100];
    printf("Enter some input (type 'quit' to exit): ");
    while (1) {
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = 0; // Remove newline character

        if (strcmp(user_input, "quit") == 0) {
            log_event(logger, "User chose to exit.");
            break;
        }

        log_event(logger, user_input);
        printf("You entered: %s\n", user_input);
        log_event(logger, "User input received.");
    }

    log_event(logger, "Process ended.");
}

// Main function
int main() {
    const char *log_filename = "event_log.txt";
    EventLogger *logger = init_logger(log_filename);

    if (logger == NULL) {
        return EXIT_FAILURE;
    }

    simulate_process(logger);
    close_logger(logger);
    
    printf("Event logging completed. Check '%s' for logs.\n", log_filename);
    return EXIT_SUCCESS;
}