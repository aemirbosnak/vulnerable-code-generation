//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#define LOG_FILE "event_log.txt"
#define MAX_LOG_LENGTH 256
#define LOG_LEVEL_INFO 1
#define LOG_LEVEL_WARNING 2
#define LOG_LEVEL_ERROR 3
#define LOG_LEVEL_DEBUG 4

typedef struct {
    int level;
    const char *name;
} LogLevel;

LogLevel log_levels[] = {
    {LOG_LEVEL_INFO, "INFO"},
    {LOG_LEVEL_WARNING, "WARNING"},
    {LOG_LEVEL_ERROR, "ERROR"},
    {LOG_LEVEL_DEBUG, "DEBUG"}
};

int configured_log_level = LOG_LEVEL_INFO; // Default log level

void set_log_level(int level) {
    if (level >= LOG_LEVEL_INFO && level <= LOG_LEVEL_DEBUG) {
        configured_log_level = level;
    } else {
        fprintf(stderr, "Invalid log level\n");
    }
}

const char* get_current_time() {
    time_t now;
    time(&now);
    return ctime(&now);
}

void log_event(int level, const char *format, ...) {
    if (level < configured_log_level) {
        return; // Skip logging this event
    }
    
    FILE *file = fopen(LOG_FILE, "a");
    if (!file) {
        fprintf(stderr, "Could not open log file for writing\n");
        return;
    }

    va_list args;
    char log_message[MAX_LOG_LENGTH];

    va_start(args, format);
    vsnprintf(log_message, sizeof(log_message), format, args);
    va_end(args);

    fprintf(file, "[%s] [%s] %s\n", get_current_time(), log_levels[level - 1].name, log_message);
    fclose(file);
}

void configure_logging(int argc, char *argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "INFO") == 0) {
            set_log_level(LOG_LEVEL_INFO);
        } else if (strcmp(argv[1], "WARNING") == 0) {
            set_log_level(LOG_LEVEL_WARNING);
        } else if (strcmp(argv[1], "ERROR") == 0) {
            set_log_level(LOG_LEVEL_ERROR);
        } else if (strcmp(argv[1], "DEBUG") == 0) {
            set_log_level(LOG_LEVEL_DEBUG);
        } else {
            fprintf(stderr, "Unknown log level. Using default (INFO).\n");
        }
    }
}

int main(int argc, char *argv[]) {
    configure_logging(argc, argv);
    
    log_event(LOG_LEVEL_INFO, "Application started.");
    log_event(LOG_LEVEL_DEBUG, "Debugging information: %d", 42);
    log_event(LOG_LEVEL_WARNING, "This is a warning message.");
    log_event(LOG_LEVEL_ERROR, "An error occurred: %s", "File not found");
    
    log_event(LOG_LEVEL_INFO, "Performing some operations...");
    
    // Simulating more operations
    for (int i = 0; i < 5; i++) {
        log_event(LOG_LEVEL_DEBUG, "Iteration %d", i);
        if (i == 3) {
            log_event(LOG_LEVEL_WARNING, "Reached the halfway mark.");
        }
    }

    log_event(LOG_LEVEL_ERROR, "Operation failed unexpectedly.");
    log_event(LOG_LEVEL_INFO, "Application finished processing.");

    return 0;
}