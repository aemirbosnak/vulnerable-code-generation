//FormAI DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for event types
#define INFO 1
#define WARNING 2
#define ERROR 3

// Define struct for events
typedef struct {
    time_t timestamp;
    int type;
    char *message;
} event;

// Define function to create and return a new event
event *create_event(int type, char *message) {
    event *new_event = malloc(sizeof(event));
    new_event->timestamp = time(NULL);
    new_event->type = type;
    new_event->message = message;
    return new_event;
}

int main() {
    // Create array of 10 events
    event *events[10];

    // Add some events to the array
    events[0] = create_event(INFO, "System initialized");
    events[1] = create_event(INFO, "User login detected");
    events[2] = create_event(WARNING, "Low disk space on drive C:");
    events[3] = create_event(ERROR, "Application crash");
    events[4] = create_event(INFO, "System shutdown initiated");
    events[5] = create_event(INFO, "System shutdown completed successfully!");
    events[6] = create_event(WARNING, "Unauthorized access attempt detected");
    events[7] = create_event(ERROR, "Critical system file corrupted");
    events[8] = create_event(INFO, "Scheduled maintenance initiated");
    events[9] = create_event(INFO, "Scheduled maintenance completed successfully");

    // Print out all events in the array
    for (int i = 0; i < 10; i++) {
        printf("[%ld] ", events[i]->timestamp);
        switch (events[i]->type) {
            case INFO:
                printf("[INFO] ");
                break;
            case WARNING:
                printf("[WARNING] ");
                break;
            case ERROR:
                printf("[ERROR] ");
                break;
        }
        printf("%s\n", events[i]->message);
    }

    // Free memory allocated for events
    for (int i = 0; i < 10; i++) {
        free(events[i]);
    }
}