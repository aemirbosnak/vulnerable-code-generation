//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 1000

typedef struct event {
    char* event_name;
    char* event_description;
    struct event* next;
} Event;

Event* event_list = NULL;
int event_count = 0;

void add_event(char* event_name, char* event_description) {
    Event* new_event = malloc(sizeof(Event));
    new_event->event_name = strdup(event_name);
    new_event->event_description = strdup(event_description);
    new_event->next = NULL;

    if (event_list == NULL) {
        event_list = new_event;
    } else {
        Event* current = event_list;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_event;
    }

    event_count++;
}

void remove_event(char* event_name) {
    Event* current = event_list;
    Event* prev = NULL;

    while (current!= NULL) {
        if (strcmp(current->event_name, event_name) == 0) {
            if (prev == NULL) {
                event_list = current->next;
            } else {
                prev->next = current->next;
            }

            free(current->event_name);
            free(current->event_description);
            free(current);
            event_count--;

            return;
        }

        prev = current;
        current = current->next;
    }
}

void display_events() {
    if (event_count == 0) {
        printf("No events recorded.\n");
        return;
    }

    Event* current = event_list;
    printf("Event List:\n");

    while (current!= NULL) {
        printf("%s: %s\n", current->event_name, current->event_description);
        current = current->next;
    }
}

int main() {
    add_event("Start", "Program started");
    add_event("Stop", "Program stopped");
    add_event("Error", "An error occurred");

    display_events();

    remove_event("Start");
    display_events();

    return 0;
}