//Falcon-180B DATASET v1.0 Category: System event logger ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event.log"

// Event structure
typedef struct {
    char *description;
    time_t timestamp;
} Event;

// Function prototypes
void log_event(const char *description);
void print_event_log();

int main() {
    log_event("Program started");

    // Simulate some events
    log_event("Button clicked");
    log_event("File opened");
    log_event("Data saved");

    print_event_log();

    return 0;
}

// Log an event to the log file
void log_event(const char *description) {
    FILE *log_file;
    Event event;

    log_file = fopen(EVENT_LOG_FILE, "a");
    if (log_file == NULL) {
        printf("Error: Could not open event log file.\n");
        return;
    }

    event.description = strdup(description);
    event.timestamp = time(NULL);

    fwrite(&event, sizeof(Event), 1, log_file);

    fclose(log_file);
}

// Print the event log
void print_event_log() {
    FILE *log_file;
    Event event;
    int event_count = 0;

    log_file = fopen(EVENT_LOG_FILE, "r");
    if (log_file == NULL) {
        printf("No events found.\n");
        return;
    }

    while (fread(&event, sizeof(Event), 1, log_file) == 1) {
        printf("%s - %s\n", ctime(&event.timestamp), event.description);
        event_count++;

        if (event_count >= MAX_EVENTS) {
            break;
        }
    }

    fclose(log_file);
}