//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A custom log level enum for our program.
typedef enum {
    LOG_LEVEL_DEBUG  = 1,
    LOG_LEVEL_INFO   = 2,
    LOG_LEVEL_WARN  = 3,
    LOG_LEVEL_ERROR  = 4,
    LOG_LEVEL_FATAL  = 5,
} log_level_t;

// A custom log function that takes a log level and a message.
void log_message(log_level_t level, const char *message) {
    // Print the log level to the console.
    switch (level) {
        case LOG_LEVEL_DEBUG:
            printf("[DEBUG] ");
            break;
        case LOG_LEVEL_INFO:
            printf("[INFO] ");
            break;
        case LOG_LEVEL_WARN:
            printf("[WARN] ");
            break;
        case LOG_LEVEL_ERROR:
            printf("[ERROR] ");
            break;
        case LOG_LEVEL_FATAL:
            printf("[FATAL] ");
            break;
    }

    // Print the log message to the console.
    printf("%s\n", message);
}

// A custom log analysis function that reads a log file and prints out all the log messages of a specified level.
void log_analysis(const char *filename, log_level_t level) {
    // Open the log file for reading.
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening log file");
        return;
    }

    // Read the log file line by line.
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // Parse the log level from the line.
        log_level_t log_level;
        if (strncmp(line, "[DEBUG]", 7) == 0) {
            log_level = LOG_LEVEL_DEBUG;
        } else if (strncmp(line, "[INFO]", 6) == 0) {
            log_level = LOG_LEVEL_INFO;
        } else if (strncmp(line, "[WARN]", 6) == 0) {
            log_level = LOG_LEVEL_WARN;
        } else if (strncmp(line, "[ERROR]", 7) == 0) {
            log_level = LOG_LEVEL_ERROR;
        } else if (strncmp(line, "[FATAL]", 7) == 0) {
            log_level = LOG_LEVEL_FATAL;
        } else {
            continue;
        }

        // Check if the log level matches the specified level.
        if (level == log_level) {
            // Print the log message to the console.
            printf("%s", line);
        }
    }

    // Close the log file.
    fclose(file);
}

// The main function.
int main(int argc, char **argv) {
    // Check if the user has specified a log file and a log level.
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <log file> <log level>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the log level from the command line.
    log_level_t level;
    if (strcmp(argv[2], "DEBUG") == 0) {
        level = LOG_LEVEL_DEBUG;
    } else if (strcmp(argv[2], "INFO") == 0) {
        level = LOG_LEVEL_INFO;
    } else if (strcmp(argv[2], "WARN") == 0) {
        level = LOG_LEVEL_WARN;
    } else if (strcmp(argv[2], "ERROR") == 0) {
        level = LOG_LEVEL_ERROR;
    } else if (strcmp(argv[2], "FATAL") == 0) {
        level = LOG_LEVEL_FATAL;
    } else {
        fprintf(stderr, "Invalid log level: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Perform log analysis on the specified log file and log level.
    log_analysis(argv[1], level);

    return EXIT_SUCCESS;
}