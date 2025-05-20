//FormAI DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Struct for storing events
typedef struct {
    char *event_name;
    char *event_time;
    struct Event *next_event;
} Event;

// Function to allocate memory for new events
Event* create_event(char *event_name, char *event_time) {
    Event *new_event = (Event*) malloc(sizeof(Event));
    if (new_event == NULL) {
        printf("Error: Insufficient memory\n");
        exit(EXIT_FAILURE);
    }
    new_event->event_name = event_name;
    new_event->event_time = event_time;
    new_event->next_event = NULL;
    return new_event;
}

// Function to recursively print events to console
void print_events(Event *event) {
    if (event == NULL) return;
    printf("Event Name: %s | Event Time: %s\n", event->event_name, event->event_time);
    print_events(event->next_event);
}

// Function to add an event to the event list
void add_event(Event **event_list, char *event_name, char *event_time) {
    Event *new_event = create_event(event_name, event_time);
    new_event->next_event = *event_list;
    *event_list = new_event;
}

// Example program to log events
int main() {
    Event *event_list = NULL;
    add_event(&event_list, "Event 1", "10:30 AM");
    add_event(&event_list, "Event 2", "12:45 PM");
    add_event(&event_list, "Event 3", "2:00 PM");
    add_event(&event_list, "Event 4", "4:15 PM");
    printf("System Event Logger\n");
    printf("===================\n");
    printf("Events logged so far:\n");
    print_events(event_list);
    return 0;
}