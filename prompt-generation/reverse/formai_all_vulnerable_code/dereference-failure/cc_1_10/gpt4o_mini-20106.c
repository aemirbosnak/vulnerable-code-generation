//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "system_events.log"
#define BUFFER_SIZE 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char *logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(const char *message, LogLevel level) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file: %s\n", LOG_FILE);
        return;
    }

    time_t now = time(NULL);
    char *timeString = ctime(&now);
    timeString[strcspn(timeString, "\n")] = 0; // Remove newline character

    fprintf(logFile, "[%s] [%s]: %s\n", timeString, logLevelToString(level), message);
    fclose(logFile);
}

void simulateEvents() {
    logEvent("System boot initiated.", INFO);
    logEvent("Loading configurations...", INFO);
    
    // Simulating some warning events
    for (int i = 0; i < 3; i++) {
        char message[BUFFER_SIZE];
        snprintf(message, sizeof(message), "Warning: Potential issue detected %d!", i + 1);
        logEvent(message, WARNING);
    }

    // Simulating a critical error
    logEvent("Critical error while trying to access database!", ERROR);
    
    logEvent("System boot completed.", INFO);
}

void printLogFile() {
    FILE *logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file: %s\n", LOG_FILE);
        return;
    }

    char line[BUFFER_SIZE];
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), logFile) != NULL) {
        printf("%s", line);
    }
    fclose(logFile);
}

int main() {
    // Clear previous log contents
    FILE *logFile = fopen(LOG_FILE, "w");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file for writing: %s\n", LOG_FILE);
        return EXIT_FAILURE;
    }
    fclose(logFile);

    // Simulating events
    simulateEvents();

    // Print the log contents
    printLogFile();

    return EXIT_SUCCESS;
}