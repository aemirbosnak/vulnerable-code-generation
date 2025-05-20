//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

typedef enum {
    INFO,
    WARNING,
    ERROR,
} LogLevel;

const char *logLevelNames[] = {
    "INFO",
    "WARNING",
    "ERROR"
};

void getCurrentTime(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tm_info);
}

void logEvent(LogLevel level, const char *eventDescription) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file != NULL) {
        char currentTime[20];
        getCurrentTime(currentTime, sizeof(currentTime));
        fprintf(file, "[%s] [%s]: %s\n", currentTime, logLevelNames[level], eventDescription);
        fclose(file);
    } else {
        printf("Error opening log file!\n");
    }
}

void printUsage() {
    printf("Usage: event_logger <log_level> <event_description>\n");
    printf("Log Levels: info, warning, error\n");
}

LogLevel parseLogLevel(const char *levelStr) {
    if (strcmp(levelStr, "info") == 0) {
        return INFO;
    } else if (strcmp(levelStr, "warning") == 0) {
        return WARNING;
    } else if (strcmp(levelStr, "error") == 0) {
        return ERROR;
    }
    return -1;
}

void showLastLogs(int numLogs) {
    FILE *file = fopen(LOG_FILE, "r");
    if (file == NULL) {
        printf("Could not open log file for reading.\n");
        return;
    }
    
    char line[MAX_EVENT_LENGTH];
    char **lines = malloc(numLogs * sizeof(char *));
    int count = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (count < numLogs) {
            lines[count] = malloc(strlen(line) + 1);
            strcpy(lines[count], line);
            count++;
        } else {
            free(lines[0]);
            for (int i = 1; i < numLogs; i++) {
                lines[i - 1] = lines[i];
            }
            lines[numLogs - 1] = malloc(strlen(line) + 1);
            strcpy(lines[numLogs - 1], line);
        }
    }
    fclose(file);
    
    printf("Last %d logs:\n", numLogs);
    for (int i = 0; i < count && i < numLogs; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }
    free(lines);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printUsage();
        return 1;
    }

    LogLevel level = parseLogLevel(argv[1]);
    if (level == -1) {
        printf("Invalid log level: %s\n", argv[1]);
        printUsage();
        return 1;
    }
    
    char eventDescription[MAX_EVENT_LENGTH];
    snprintf(eventDescription, sizeof(eventDescription), "%s", argv[2]);
    
    logEvent(level, eventDescription);
    printf("Event logged: [%s] %s\n", logLevelNames[level], eventDescription);
    
    if (argc == 4 && strcmp(argv[3], "show_last") == 0) {
        int numLogs = 5; // Show last 5 logs by default
        showLastLogs(numLogs);
    }
    
    return 0;
}