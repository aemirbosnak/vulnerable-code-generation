//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

typedef enum {
    EVENT_INFO,
    EVENT_WARNING,
    EVENT_ERROR,
    EVENT_DEBUG
} LogLevel;

const char *levelToString(LogLevel level) {
    switch (level) {
        case EVENT_INFO: return "INFO";
        case EVENT_WARNING: return "WARNING";
        case EVENT_ERROR: return "ERROR";
        case EVENT_DEBUG: return "DEBUG";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char *event) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }

    time_t currentTime = time(NULL);
    char *timeString = ctime(&currentTime);
    timeString[strlen(timeString) - 1] = '\0'; // Remove newline

    fprintf(logFile, "[%s] [%s] %s\n", timeString, levelToString(level), event);
    fclose(logFile);
}

void createLogFile() {
    struct stat buffer;
    if (stat(LOG_FILE, &buffer) != 0) {
        FILE *logFile = fopen(LOG_FILE, "w");
        if (logFile != NULL) {
            fclose(logFile);
            logEvent(EVENT_INFO, "Log file created.");
        } else {
            perror("Unable to create log file");
        }
    }
}

void readLogFile() {
    FILE *logFile = fopen(LOG_FILE, "r");
    if (logFile == NULL) {
        perror("Could not open log file");
        return;
    }

    char line[MAX_EVENT_LENGTH];
    printf("Event Log:\n");
    while (fgets(line, sizeof(line), logFile) != NULL) {
        printf("%s", line);
    }
    fclose(logFile);
}

void simulateEvents() {
    logEvent(EVENT_INFO, "System started.");
    logEvent(EVENT_DEBUG, "Debugging the initialization sequence.");
    logEvent(EVENT_WARNING, "Low memory warning.");
    logEvent(EVENT_ERROR, "Unable to connect to the database.");
    logEvent(EVENT_INFO, "Shutdown initiated.");
}

int main() {
    createLogFile();
    simulateEvents();
    readLogFile();
    return 0;
}