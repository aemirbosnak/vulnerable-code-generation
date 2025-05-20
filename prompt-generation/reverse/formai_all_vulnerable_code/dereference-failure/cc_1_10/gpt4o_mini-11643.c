//GPT-4o-mini DATASET v1.0 Category: Log analysis ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_BUFFER_SIZE 1024
#define MAX_LOG_FILES 5

typedef struct {
    FILE *file;
    char filename[50];
} LogFile;

LogFile logFiles[MAX_LOG_FILES];
int logFileCount = 0;

// Log levels
typedef enum { DEBUG, INFO, WARN, ERROR } LogLevel;

// Function to initialize log files
void initLogFiles() {
    for (int i = 0; i < MAX_LOG_FILES; i++) {
        snprintf(logFiles[i].filename, sizeof(logFiles[i].filename), "logfile_%d.log", i);
        logFiles[i].file = fopen(logFiles[i].filename, "a");
        if (logFiles[i].file == NULL) {
            perror("Error opening log file");
            exit(EXIT_FAILURE);
        }
        logFileCount++;
    }
}

// Function to close all log files
void closeLogFiles() {
    for (int i = 0; i < logFileCount; i++) {
        fclose(logFiles[i].file);
    }
}

// Function to get the current timestamp as a string
void getTimestamp(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info;
    tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

// Function to log messages
void logMessage(LogLevel level, const char *message) {
    char timestamp[20];
    getTimestamp(timestamp, sizeof(timestamp));

    const char *levelStr = (level == DEBUG) ? "DEBUG" :
                           (level == INFO) ? "INFO" :
                           (level == WARN) ? "WARN" : "ERROR";

    for (int i = 0; i < logFileCount; i++) {
        fprintf(logFiles[i].file, "[%s] [%s] %s\n", timestamp, levelStr, message);
        fflush(logFiles[i].file);
    }
}

// Utility function to simulate different log messages
void simulateLogging() {
    logMessage(INFO, "Application started.");
    logMessage(DEBUG, "Initializing components.");
    logMessage(WARN, "Low memory warning.");
    logMessage(ERROR, "Failed to load configuration.");
    logMessage(INFO, "Application running.");
    logMessage(DEBUG, "Debugging application state.");
    logMessage(ERROR, "Unhandled exception occurred.");
    logMessage(INFO, "Application terminating.");
}

int main() {
    initLogFiles();
    
    simulateLogging();
    
    closeLogFiles();

    return 0;
}