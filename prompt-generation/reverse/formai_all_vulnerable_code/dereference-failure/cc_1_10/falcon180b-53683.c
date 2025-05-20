//Falcon-180B DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000
#define LOG_FILE "event_log.txt"

typedef struct {
    char event_type[50];
    char event_description[200];
    time_t timestamp;
} EventLog;

void add_event_to_log(EventLog* log, char* event_type, char* event_description) {
    strcpy(log->event_type, event_type);
    strcpy(log->event_description, event_description);
    log->timestamp = time(NULL);
    log += sizeof(EventLog);
}

void log_event(char* event_type, char* event_description) {
    FILE* log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open log file.\n");
        return;
    }

    EventLog log_entry;
    add_event_to_log(&log_entry, event_type, event_description);

    fwrite(&log_entry, sizeof(EventLog), 1, log_file);
    fclose(log_file);
}

void print_log(FILE* log_file) {
    rewind(log_file);

    EventLog log_entry;
    while (fread(&log_entry, sizeof(EventLog), 1, log_file) == 1) {
        printf("%s - %s - %s\n", log_entry.event_type, log_entry.event_description, ctime(&log_entry.timestamp));
    }
}

int main() {
    log_event("INFO", "Program started");

    // Example events
    log_event("WARNING", "Low disk space");
    log_event("ERROR", "Database connection failed");
    log_event("DEBUG", "Variable value: 42");

    print_log(fopen(LOG_FILE, "r"));

    return 0;
}