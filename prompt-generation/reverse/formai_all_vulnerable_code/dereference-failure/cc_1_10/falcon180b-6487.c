//Falcon-180B DATASET v1.0 Category: System event logger ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 256
#define MAX_EVENTS 100

// Structure to hold event information
typedef struct {
    char message[MAX_EVENT_SIZE];
    time_t timestamp;
} Event;

// Function to log an event
void log_event(Event* events, int num_events, const char* message) {
    time_t now = time(NULL);
    strftime(message, MAX_EVENT_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&now));
    strcat(message, " - ");
    strcat(message, events[num_events-1].message);
    printf("%s\n", message);
}

int main() {
    Event events[MAX_EVENTS];
    int num_events = 0;

    printf("Starting event logger...\n");

    // Example events
    log_event(events, num_events++, "Program started.");
    log_event(events, num_events++, "Initialization complete.");

    // Simulate some program activity
    for (int i = 0; i < 10; i++) {
        log_event(events, num_events++, "Activity #");
        log_event(events, num_events++, "Activity #");
    }

    // Log an error event
    log_event(events, num_events++, "Error: Out of memory.");

    // Log a warning event
    log_event(events, num_events++, "Warning: File not found.");

    // Log some more activity
    log_event(events, num_events++, "Activity #");
    log_event(events, num_events++, "Activity #");

    // End program and log event
    log_event(events, num_events++, "Program ended.");

    printf("Event log:\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s\n", events[i].message);
    }

    return 0;
}