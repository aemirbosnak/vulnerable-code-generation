//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define LOG_FILE_PATH "event.log"
#define MAX_LOG_MESSAGE 256

typedef enum {
    INFO,
    WARNING,
    ERROR,
    DEBUG
} LogLevel;

const char *logLevelToString(LogLevel level) {
    switch (level) {
        case INFO: return "INFO";
        case WARNING: return "WARNING";
        case ERROR: return "ERROR";
        case DEBUG: return "DEBUG";
        default: return "UNKNOWN";
    }
}

void writeLog(LogLevel level, const char *message) {
    FILE *logFile = fopen(LOG_FILE_PATH, "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    time_t now = time(NULL);
    char *timeString = ctime(&now);
    // Remove newline character from time string
    timeString[strlen(timeString) - 1] = '\0'; 

    fprintf(logFile, "[%s] [%s]: %s\n", timeString, logLevelToString(level), message);
    fclose(logFile);
}

void simulateEvents() {
    const char *events[] = {
        "System Boot",
        "User Login: Alice",
        "User Login: Bob",
        "File Opened: /etc/config.txt",
        "File Read Error: /etc/secret.txt",
        "User Logout: Alice",
        "System Shutdown",
        "Disk Full Warning",
        "Debugging User Session: Bob",
        "Network Connection Established",
        "Network Connection Lost",
        "User Attempted Unauthorized Access",
        "Backup Completed",
        "System Update Started",
        "System Update Completed"
    };

    for (int i = 0; i < sizeof(events) / sizeof(events[0]); i++) {
        sleep(1); // Simulate a delay for realism
        if (i % 3 == 0) {
            writeLog(INFO, events[i]);
        } else if (i % 3 == 1) {
            writeLog(WARNING, events[i]);
        } else {
            writeLog(ERROR, events[i]);
        }
    }
}

void displayLog() {
    FILE *logFile = fopen(LOG_FILE_PATH, "r");
    if (logFile == NULL) {
        perror("Could not open log file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LOG_MESSAGE];
    while (fgets(buffer, sizeof(buffer), logFile)) {
        printf("%s", buffer);
    }
    fclose(logFile);
}

int main() {
    printf("Welcome to the Event Logger!\n");
    printf("Logging system events to %s...\n", LOG_FILE_PATH);
    
    simulateEvents();

    printf("Here are the logged events:\n");
    displayLog();

    return 0;
}