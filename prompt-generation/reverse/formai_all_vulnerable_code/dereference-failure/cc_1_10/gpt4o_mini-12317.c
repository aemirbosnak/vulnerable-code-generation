//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "system_events.log"
#define MAX_MESSAGE_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR
} LogLevel;

const char* logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char* message) {
    FILE* file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Failed to open log file");
        return;
    }

    time_t now = time(NULL);
    char* timeString = ctime(&now);
    timeString[strlen(timeString) - 1] = '\0'; // Remove newline character

    fprintf(file, "[%s] [%s] %s\n", timeString, logLevelToString(level), message);
    fclose(file);
}

void simulateSystemEvents() {
    logEvent(INFO, "System booting up.");
    logEvent(WARNING, "Low memory warning.");
    logEvent(ERROR, "Failed to connect to database.");
    logEvent(INFO, "User logged in successfully.");
    logEvent(ERROR, "Unexpected error occurred during transaction.");
    logEvent(INFO, "System shutting down.");
}

void readLogFile() {
    FILE* file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        perror("Failed to read log file");
        return;
    }

    char buffer[MAX_MESSAGE_LENGTH];
    printf("\n--- Log Contents ---\n");
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    printf("Starting System Event Logger...\n");

    // Simulate some system events
    simulateSystemEvents();

    // Read and display the log entries
    readLogFile();

    return 0;
}