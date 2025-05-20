//FormAI DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Event {
    time_t timestamp;
    char description[256];
    struct Event* next;
} Event;

Event* head = NULL;
Event* tail = NULL;

void log_event(char* description) {
    Event* new_event = (Event*) malloc(sizeof(Event));
    new_event->timestamp = time(NULL);
    strcpy(new_event->description, description);
    new_event->next = NULL;

    if (head == NULL) {
        head = new_event;
        tail = new_event;
    } else {
        tail->next = new_event;
        tail = new_event;
    }
}

void print_events() {
    Event* current_event = head;

    while (current_event != NULL) {
        printf("%s -- %s\n", ctime(&(current_event->timestamp)), current_event->description);
        current_event = current_event->next;
    }
}

int main() {
    // log some events
    log_event("System started");
    log_event("User logged in");
    log_event("File saved");
    log_event("Program exited");
    
    // print the events
    printf("System events:\n");
    print_events();

    return 0;
}