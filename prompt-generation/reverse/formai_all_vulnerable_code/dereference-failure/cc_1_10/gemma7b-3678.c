//Gemma-7B DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <time.h>

#define MAX_EVENTS 1024

typedef struct EventLog {
    char event_name[256];
    int event_id;
    time_t timestamp;
    struct EventLog* next;
} EventLog;

EventLog* head = NULL;

void log_event(char* event_name, int event_id) {
    time_t timestamp = time(NULL);
    EventLog* new_event = malloc(sizeof(EventLog));

    strcpy(new_event->event_name, event_name);
    new_event->event_id = event_id;
    new_event->timestamp = timestamp;
    new_event->next = NULL;

    if (head == NULL) {
        head = new_event;
    } else {
        head->next = new_event;
        head = new_event;
    }

    if (head->next == NULL) {
        printf("Event logged successfully!\n");
    }
}

int main() {
    log_event("System boot", 1);
    log_event("User login", 2);
    log_event("Application launch", 3);

    EventLog* current_event = head;
    while (current_event) {
        printf("Event name: %s\n", current_event->event_name);
        printf("Event ID: %d\n", current_event->event_id);
        printf("Timestamp: %s\n", asctime(localtime(&current_event->timestamp)));
        printf("\n");
        current_event = current_event->next;
    }

    return 0;
}