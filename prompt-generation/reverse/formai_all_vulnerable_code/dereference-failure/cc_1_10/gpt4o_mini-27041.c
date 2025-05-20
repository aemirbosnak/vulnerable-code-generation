//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_MESSAGE_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} LogLevel;

const char *logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char *message) {
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Remove newline character

    fprintf(file, "[%s] [%s]: %s\n", timestamp, logLevelToString(level), message);
    fclose(file);
}

void simulateEvents() {
    const char *events[] = {
        "System started successfully.",
        "New user connected to the server.",
        "Disk space is running low.",
        "Failed to open configuration file.",
        "User 'admin' has logged out.",
        "Critical error: unable to connect to database."
    };

    for (int i = 0; i < sizeof(events) / sizeof(events[0]); ++i) {
        sleep(1); 
        LogLevel level = INFO;

        if (i == 2) {
            level = WARNING;
        } else if (i == 3) {
            level = ERROR;
        } else if (i == 5) {
            level = CRITICAL;
        }

        logEvent(level, events[i]);
    }
}

void displayLogContents() {
    FILE *file = fopen(LOG_FILE, "r");
    if (!file) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }

    printf("Log Contents:\n");
    char buffer[MAX_MESSAGE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main() {
    logEvent(INFO, "Starting the event logger program...");
    
    simulateEvents();

    logEvent(INFO, "All events simulated successfully.");
    
    displayLogContents();

    return 0;
}