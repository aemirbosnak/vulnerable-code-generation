//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_FILES 10
#define MAX_LOG_SIZE 512
#define LOG_FILE_NAME "event_log.txt"

typedef enum {
    INFO,
    WARNING,
    ERROR,
    CRITICAL
} LogLevel;

const char *log_level_strings[] = {
    "INFO",
    "WARNING",
    "ERROR",
    "CRITICAL"
};

typedef struct {
    LogLevel level;
    char message[MAX_LOG_SIZE];
} LogEvent;

typedef struct {
    FILE *log_file;
    LogLevel min_log_level;
    int log_to_console;
} Logger;

// Function prototypes
void init_logger(Logger *logger, const char *filename, LogLevel min_level, int log_to_console);
void log_event(Logger *logger, LogLevel level, const char *message);
void close_logger(Logger *logger);
void get_timestamp(char *buffer);

int main(int argc, char *argv[]) {
    Logger logger;
    LogLevel min_level = INFO; // Default level
    int log_to_console = 0; // Default does not log to console
    const char *filename = LOG_FILE_NAME;

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--file") == 0 && i + 1 < argc) {
            filename = argv[i + 1];
            i++;
        } else if (strcmp(argv[i], "--level") == 0 && i + 1 < argc) {
            if (strcmp(argv[i + 1], "INFO") == 0) min_level = INFO;
            else if (strcmp(argv[i + 1], "WARNING") == 0) min_level = WARNING;
            else if (strcmp(argv[i + 1], "ERROR") == 0) min_level = ERROR;
            else if (strcmp(argv[i + 1], "CRITICAL") == 0) min_level = CRITICAL;
            i++;
        } else if (strcmp(argv[i], "--console") == 0) {
            log_to_console = 1;
        }
    }

    // Initialize the logger
    init_logger(&logger, filename, min_level, log_to_console);

    // Log events of different severities
    log_event(&logger, INFO, "Application started.");
    log_event(&logger, WARNING, "Low disk space warning.");
    log_event(&logger, ERROR, "Failed to open configuration file.");
    log_event(&logger, CRITICAL, "Non-recoverable error occurred.");

    // Close the logger
    close_logger(&logger);

    return 0;
}

void init_logger(Logger *logger, const char *filename, LogLevel min_level, int log_to_console) {
    logger->min_log_level = min_level;
    logger->log_to_console = log_to_console;
    logger->log_file = fopen(filename, "a");
    if (!logger->log_file) {
        perror("Failed to open log file");
        exit(EXIT_FAILURE);
    }
}

void log_event(Logger *logger, LogLevel level, const char *message) {
    if (level < logger->min_log_level) {
        return; // Do not log this event
    }

    char timestamp[30];
    get_timestamp(timestamp);

    const char *level_string = log_level_strings[level];
    if (logger->log_to_console) {
        printf("[%s] [%s] %s\n", timestamp, level_string, message);
    }

    fprintf(logger->log_file, "[%s] [%s] %s\n", timestamp, level_string, message);
    fflush(logger->log_file); // Ensure log is written immediately
}

void close_logger(Logger *logger) {
    if (logger->log_file) {
        fclose(logger->log_file);
    }
}

void get_timestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 30, "%Y-%m-%d %H:%M:%S", tm_info);
}