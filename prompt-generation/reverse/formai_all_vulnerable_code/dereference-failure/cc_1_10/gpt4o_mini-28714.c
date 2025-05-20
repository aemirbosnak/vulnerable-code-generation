//GPT-4o-mini DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define LOG_FILE "event_log.txt"
#define MAX_EVENT_LENGTH 256

void log_event(const char *event) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        printf("Could not open log file for writing.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec,
            event);

    fclose(file);
}

void initialize_logger() {
    log_event("Logger initialized successfully.");
}

void log_fatal_error(const char *error_message) {
    char event[MAX_EVENT_LENGTH];
    snprintf(event, sizeof(event), "FATAL ERROR: %s", error_message);
    log_event(event);
}

void log_info(const char *info_message) {
    char event[MAX_EVENT_LENGTH];
    snprintf(event, sizeof(event), "INFO: %s", info_message);
    log_event(event);
}

void simulate_event_logging() {
    // Simulating several different events
    log_info("Starting the event logger.");
    sleep(1);

    log_info("Processing some data...");
    sleep(1);

    log_info("Data processing completed.");
    sleep(1);

    log_fatal_error("An unexpected error occurred while processing data.");
    sleep(1);

    log_info("Attempting to recover from the error...");
    sleep(1);

    log_info("Recovery successful, continue operation.");
    sleep(1);

    log_info("Event logger is shutting down.");
}

int main() {
    printf("Welcome to the Peaceful C Event Logger.\n");
    printf("This program will log various events to %s.\n", LOG_FILE);

    initialize_logger();
    simulate_event_logging();

    printf("All events have been logged peacefully. Check %s for details.\n", LOG_FILE);
    return 0;
}