//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define an enum for different log levels
typedef enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
} LogLevel;

// define a struct to represent a log message
typedef struct LogMessage {
    LogLevel level;
    char* message;
} LogMessage;

// define a function to parse a log message from a string
LogMessage parse_log_message(char* str) {
    LogMessage log_msg;
    char* level_str = strtok(str, " ");
    if (strcmp(level_str, "DEBUG") == 0) {
        log_msg.level = LOG_DEBUG;
    } else if (strcmp(level_str, "INFO") == 0) {
        log_msg.level = LOG_INFO;
    } else if (strcmp(level_str, "WARN") == 0) {
        log_msg.level = LOG_WARN;
    } else if (strcmp(level_str, "ERROR") == 0) {
        log_msg.level = LOG_ERROR;
    } else {
        fprintf(stderr, "Unknown log level: %s\n", level_str);
        exit(1);
    }
    log_msg.message = strtok(NULL, "\n");
    return log_msg;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <logfile>\n", argv[0]);
        exit(1);
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", argv[1]);
        exit(1);
    }
    char* line = NULL;
    size_t len = 0;
    ssize_t nread;
    while ((nread = getline(&line, &len, fp)) != -1) {
        LogMessage log_msg = parse_log_message(line);
        switch (log_msg.level) {
            case LOG_DEBUG:
                printf("DEBUG: %s", log_msg.message);
                break;
            case LOG_INFO:
                printf("INFO: %s", log_msg.message);
                break;
            case LOG_WARN:
                printf("WARNING: %s", log_msg.message);
                break;
            case LOG_ERROR:
                printf("ERROR: %s", log_msg.message);
                break;
            default:
                fprintf(stderr, "Unknown log level: %d\n", log_msg.level);
                exit(1);
        }
    }
    free(line);
    fclose(fp);
    return 0;
}