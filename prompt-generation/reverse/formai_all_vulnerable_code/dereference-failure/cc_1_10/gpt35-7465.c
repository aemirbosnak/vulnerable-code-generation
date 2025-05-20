//FormAI DATASET v1.0 Category: System event logger ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100

// Struct to hold the event data
struct Event {
    char* timestamp;
    char* name;
};

// Function to add an event to the logger
void log_event(char* event_name, int event_id, struct Event* event_log) {
    // Get the current time
    time_t current_time;
    time(&current_time);
    char* timestamp = ctime(&current_time);
    timestamp[strlen(timestamp) - 1] = '\0'; // remove trailing newline

    // Create the event struct
    struct Event new_event;
    new_event.timestamp = timestamp;

    // Allocate memory for the event name and copy it
    char* event_name_copy = (char*) malloc(strlen(event_name) + 1);
    strcpy(event_name_copy, event_name);
    new_event.name = event_name_copy;

    // Add the event to the log
    event_log[event_id] = new_event;

    printf("[%s] Event '%s' logged with ID %d\n", new_event.timestamp, new_event.name, event_id);
}

// Function to print all events in the log
void print_log(struct Event* event_log, int num_events) {
    printf("--- EVENT LOG ---\n");
    for (int i = 0; i < num_events; i++) {
        printf("%s: %s\n", event_log[i].timestamp, event_log[i].name);
    }
}

int main() {
    // Create an array to hold the events
    struct Event event_log[MAX_EVENTS];

    // Log some events
    log_event("System Start", 0, event_log);
    log_event("User Login", 1, event_log);
    log_event("File Download", 2, event_log);

    // Print the log
    print_log(event_log, 3);

    return 0;
}