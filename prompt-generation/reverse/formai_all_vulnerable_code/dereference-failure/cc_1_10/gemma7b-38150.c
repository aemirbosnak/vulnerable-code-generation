//Gemma-7B DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an event logging structure
typedef struct EventLog {
    char *event_name;
    char *event_details;
    struct EventLog *next;
} EventLog;

// Function to create a new event log entry
EventLog *create_event_log(char *event_name, char *event_details) {
    EventLog *new_event_log = malloc(sizeof(EventLog));

    new_event_log->event_name = strdup(event_name);
    new_event_log->event_details = strdup(event_details);
    new_event_log->next = NULL;

    return new_event_log;
}

// Function to add an event log entry to the head of the list
void add_event_log(EventLog **head, char *event_name, char *event_details) {
    EventLog *new_event_log = create_event_log(event_name, event_details);

    if (*head == NULL) {
        *head = new_event_log;
    } else {
        (*head)->next = new_event_log;
        *head = new_event_log;
    }
}

int main() {
    EventLog *event_log = NULL;

    // Add some event log entries
    add_event_log(&event_log, "User logged in", "John Doe");
    add_event_log(&event_log, "User purchased a product", "Jane Doe");
    add_event_log(&event_log, "User updated their profile", "Bob Smith");

    // Print the event log entries
    for (EventLog *current_event_log = event_log; current_event_log != NULL; current_event_log = current_event_log->next) {
        printf("Event name: %s\n", current_event_log->event_name);
        printf("Event details: %s\n", current_event_log->event_details);
        printf("\n");
    }

    return 0;
}