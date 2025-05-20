//FormAI DATASET v1.0 Category: System event logger ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOG_FILE "event.log"
#define MAX_LOG_ENTRIES 1000

typedef struct {
    time_t timestamp;
    char* event_message;
} LogEntry;

typedef struct {
    bool is_enabled;
    int max_entries;
    int num_entries;
    LogEntry* entries;
} EventLogger;

void init_logger(EventLogger* logger, bool is_enabled, int max_entries) {
    logger->is_enabled = is_enabled;
    logger->max_entries = max_entries;
    logger->num_entries = 0;
    logger->entries = (LogEntry*) malloc(max_entries * sizeof(LogEntry));
}

void log_event(EventLogger* logger, char* message) {
    if (!logger->is_enabled) {
        return;
    }

    // get current system time
    time_t current_time = time(NULL);

    // create new log entry
    LogEntry new_entry;
    new_entry.timestamp = current_time;
    new_entry.event_message = (char*) malloc(strlen(message) * sizeof(char));
    strcpy(new_entry.event_message, message);

    // if logger is full, remove oldest entry
    if (logger->num_entries >= logger->max_entries) {
        free(logger->entries[0].event_message);
        for (int i = 0; i < logger->num_entries - 1; i++) {
            logger->entries[i] = logger->entries[i + 1];
        }
        logger->num_entries--;
    }

    // add new entry to logger
    logger->entries[logger->num_entries] = new_entry;
    logger->num_entries++;

    // write log entry to file
    FILE* file = fopen(LOG_FILE, "a");
    fprintf(file, "%ld,%s\n", current_time, message);
    fclose(file);
}

void print_log(EventLogger* logger) {
    printf("--- EVENT LOG ---\n");
    for (int i = 0; i < logger->num_entries; i++) {
        printf("%s\n", logger->entries[i].event_message);
    }
}

int main() {
    // initialize event logger
    EventLogger logger;
    init_logger(&logger, true, MAX_LOG_ENTRIES);

    // log some events
    log_event(&logger, "Program started");
    log_event(&logger, "User clicked button A");
    log_event(&logger, "User clicked button B");
    log_event(&logger, "Program exited");

    // print log to console
    print_log(&logger);

    return 0;
}