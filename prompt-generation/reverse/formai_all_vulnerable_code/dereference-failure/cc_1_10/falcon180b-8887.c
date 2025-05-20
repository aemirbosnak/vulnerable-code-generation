//Falcon-180B DATASET v1.0 Category: System event logger ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 1000

typedef struct {
    char *event_name;
    int event_type;
    time_t event_time;
} event_t;

event_t event_buffer[MAX_EVENTS];
int event_count = 0;

void add_event(char *name, int type) {
    event_t *event = &event_buffer[event_count];
    event->event_name = strdup(name);
    event->event_type = type;
    event->event_time = time(NULL);
    event_count++;
}

void log_events() {
    if (event_count == 0) {
        printf("No events to log.\n");
        return;
    }

    printf("Event log:\n");
    printf("--------------------\n");

    for (int i = 0; i < event_count; i++) {
        event_t *event = &event_buffer[i];
        printf("%s (%d) - %s", event->event_name, event->event_type, ctime(&event->event_time));
    }
}

int main() {
    add_event("Program start", 1);
    add_event("User login", 2);
    add_event("File opened", 3);
    add_event("Database query", 4);
    add_event("Network request", 5);
    add_event("Program end", 6);

    log_events();

    return 0;
}