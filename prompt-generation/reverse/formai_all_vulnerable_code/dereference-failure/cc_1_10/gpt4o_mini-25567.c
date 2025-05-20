//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_MSG_LENGTH 256

typedef enum {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

const char* logLevelToString(LogLevel level) {
    switch(level) {
        case LOG_INFO: return "INFO";
        case LOG_WARNING: return "WARNING";
        case LOG_ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

void logEvent(LogLevel level, const char* message) {
    FILE *logFile = fopen(LOG_FILE, "a");
    if (logFile == NULL) {
        fprintf(stderr, "Could not open log file %s for writing\n", LOG_FILE);
        return;
    }
    
    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strlen(timestamp) - 1] = '\0'; // Removing the newline character from ctime

    char logMsg[MAX_LOG_MSG_LENGTH];
    snprintf(logMsg, MAX_LOG_MSG_LENGTH, "[%s] [%s] %s\n", timestamp, logLevelToString(level), message);
    
    printf("%s", logMsg); // Print to console
    fprintf(logFile, "%s", logMsg); // Write to file

    fclose(logFile);
}

void demoLogging() {
    logEvent(LOG_INFO, "System initialized successfully.");
    logEvent(LOG_WARNING, "Low disk space detected.");
    logEvent(LOG_ERROR, "Failed to open configuration file.");
}

int main() {
    printf("Starting the Event Logger...\n");
    
    demoLogging();

    printf("Event logging completed. Check %s for the log entries.\n", LOG_FILE);
    return 0;
}