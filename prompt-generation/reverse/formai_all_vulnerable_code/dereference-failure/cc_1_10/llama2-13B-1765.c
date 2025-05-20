//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define MAX_EVENT_LENGTH 512
#define MAX_EVENTS 1000

typedef struct {
    char *name;
    char *message;
    time_t timestamp;
} event_t;

event_t events[MAX_EVENTS];
int num_events = 0;

void log_event(const char *name, const char *message) {
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char buffer[64];

    // Format the timestamp in the satisfied style
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm);

    // Create a new event struct
    event_t *event = (event_t *) malloc(sizeof(event_t));
    event->name = name;
    event->message = message;
    event->timestamp = now;

    // Add the event to the event array
    events[num_events] = *event;
    num_events++;

    // If the event array is full, reset it
    if (num_events == MAX_EVENTS) {
        num_events = 0;
        memset(events, 0, sizeof(events));
    }
}

void print_events() {
    int i;
    for (i = 0; i < num_events; i++) {
        printf("%s (%s) at %s\n", events[i].name, events[i].message, events[i].timestamp);
    }
}

int main() {
    log_event("Hello", "World");
    log_event("Goodbye", "C");
    log_event("Hello Again", "Satisfied!");

    print_events();

    return 0;
}