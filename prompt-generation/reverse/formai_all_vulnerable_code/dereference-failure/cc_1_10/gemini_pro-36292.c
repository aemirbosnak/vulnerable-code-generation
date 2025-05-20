//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: protected
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Event types
#define EVENT_TYPE_INFO    0x01
#define EVENT_TYPE_WARNING 0x02
#define EVENT_TYPE_ERROR   0x04

// Event structure
typedef struct {
    uint32_t type;
    char* message;
} Event;

// Event logger
static Event* events[100];
static int num_events = 0;

// Log an event
void log_event(uint32_t type, char* message) {
    if (num_events >= 100) {
        return;
    }

    events[num_events] = malloc(sizeof(Event));
    events[num_events]->type = type;
    events[num_events]->message = message;

    num_events++;
}

// Print all events
void print_events() {
    for (int i = 0; i < num_events; i++) {
        switch (events[i]->type) {
            case EVENT_TYPE_INFO:
                printf("INFO: %s\n", events[i]->message);
                break;
            case EVENT_TYPE_WARNING:
                printf("WARNING: %s\n", events[i]->message);
                break;
            case EVENT_TYPE_ERROR:
                printf("ERROR: %s\n", events[i]->message);
                break;
        }
    }
}

// Main function
int main() {
    // Log some events
    log_event(EVENT_TYPE_INFO, "This is an info message");
    log_event(EVENT_TYPE_WARNING, "This is a warning message");
    log_event(EVENT_TYPE_ERROR, "This is an error message");

    // Print all events
    print_events();

    return 0;
}