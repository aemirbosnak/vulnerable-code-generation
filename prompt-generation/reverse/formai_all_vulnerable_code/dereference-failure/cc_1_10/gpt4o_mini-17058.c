//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define EVENT_DESC_SIZE 256

enum LogLevel {
    INFO,
    WARNING,
    ERROR,
};

const char* logLevelToString(enum LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(enum LogLevel level, const char* description) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    time_t now;
    time(&now);
    char* timeStr = ctime(&now);
    timeStr[strlen(timeStr) - 1] = '\0';  // Remove newline character

    fprintf(file, "[%s] [%s] %s\n", timeStr, logLevelToString(level), description);
    fclose(file);
}

void performOperation(const char* operation) {
    logEvent(INFO, "Starting operation");
    sleep(1);

    if (strcmp(operation, "create") == 0) {
        logEvent(INFO, "Creating an item...");
        // Simulate item creation logic
        logEvent(INFO, "Item created successfully");
    } else if (strcmp(operation, "delete") == 0) {
        logEvent(WARNING, "Deleting an item...");
        // Simulate item deletion logic
        logEvent(INFO, "Item deleted successfully");
    } else {
        logEvent(ERROR, "Unknown operation requested");
    }

    logEvent(INFO, "Operation completed");
}

void displayLog() {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    char buffer[EVENT_DESC_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <operation>\n", argv[0]);
        return EXIT_FAILURE;
    }

    logEvent(INFO, "Application started");
    performOperation(argv[1]);
    logEvent(INFO, "Application finished");

    printf("Event log:\n");
    displayLog();

    return EXIT_SUCCESS;
}