//Gemma-7B DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of events that can be stored
#define MAX_EVENTS 100

// Define the event structure
typedef struct Event {
    char *name;
    int timestamp;
    struct Event *next;
} Event;

// Global variable to store the head of the event list
Event *head = NULL;

// Function to add an event to the list
void addEvent(char *name) {
    // Allocate memory for the new event
    Event *newEvent = (Event *)malloc(sizeof(Event));
    newEvent->name = strdup(name);
    newEvent->timestamp = time(NULL);
    newEvent->next = NULL;

    // If the list is empty, make the new event the head
    if (head == NULL) {
        head = newEvent;
    } else {
        // Traverse the list until the last event is reached
        Event *lastEvent = head;
        while (lastEvent->next) {
            lastEvent = lastEvent->next;
        }

        // Add the new event to the last event's next pointer
        lastEvent->next = newEvent;
    }
}

// Function to print the events
void printEvents() {
    // Traverse the list of events
    Event *event = head;
    while (event) {
        printf("%s (%d) ", event->name, event->timestamp);
        printf("\n");
        event = event->next;
    }
}

int main() {
    // Add some events to the list
    addEvent("John Doe went to the park.");
    addEvent("Jane Doe went to the store.");
    addEvent("Peter Pan flew to Neverland.");

    // Print the events
    printEvents();

    return 0;
}