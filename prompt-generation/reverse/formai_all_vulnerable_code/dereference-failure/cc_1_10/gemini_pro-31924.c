//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Custom data structure for event logging
typedef struct Event {
    time_t timestamp;
    char *message;
    int severity;
} Event;

// Global array to store event logs
Event *logs[100];
int log_count = 0;

// Function to create a new event log entry
Event *create_event(char *message, int severity) {
    Event *event = malloc(sizeof(Event));
    event->timestamp = time(NULL);
    event->message = strdup(message);
    event->severity = severity;
    return event;
}

// Function to add an event log entry to the global array
void add_event(Event *event) {
    if (log_count < 100) {
        logs[log_count++] = event;
    } else {
        printf("Error: Event log is full.\n");
    }
}

// Function to print the event logs
void print_logs() {
    for (int i = 0; i < log_count; i++) {
        Event *event = logs[i];
        printf("%ld: %s (Severity: %d)\n", event->timestamp, event->message, event->severity);
    }
}

// Main function
int main() {
    // Create some sample event logs
    Event *event1 = create_event("System startup completed successfully", 0);
    Event *event2 = create_event("Application error: File not found", 1);
    Event *event3 = create_event("Security alert: Unauthorized access attempt", 2);

    // Add the event logs to the global array
    add_event(event1);
    add_event(event2);
    add_event(event3);

    // Print the event logs
    printf("Event Logs:\n");
    print_logs();

    return 0;
}