//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENT_SIZE 1024
#define MAX_EVENTS 1000

typedef struct {
    char *message;
    time_t timestamp;
} event_t;

event_t events[MAX_EVENTS];
int head = 0;
int tail = 0;

void log_event(const char *message) {
    event_t *new_event = (event_t *)malloc(sizeof(event_t));
    new_event->message = message;
    new_event->timestamp = time(NULL);

    if (head == MAX_EVENTS) {
        printf("WARNING: Event buffer is full, dropping oldest event\n");
        tail = (tail + 1) % MAX_EVENTS;
    }

    events[tail] = *new_event;
    tail = (tail + 1) % MAX_EVENTS;
}

void print_events() {
    int i;
    for (i = head; i != tail; i = (i + 1) % MAX_EVENTS) {
        event_t *event = &events[i];
        printf("%s (%ld) %s\n", event->message, event->timestamp, event->message);
    }
}

int main() {
    log_event("Hello, world!");
    log_event("This is a test event");
    log_event("This is another test event");
    log_event("And another one");

    print_events();

    return 0;
}