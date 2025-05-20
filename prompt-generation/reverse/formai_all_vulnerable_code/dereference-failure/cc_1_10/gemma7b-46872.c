//Gemma-7B DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog {
    char *events;
    int capacity;
    int head;
    int tail;
} EventLog;

EventLog *eventLog_init(int capacity) {
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(capacity * MAX_EVENT_SIZE);
    log->capacity = capacity;
    log->head = 0;
    log->tail = 0;

    return log;
}

void eventLog_add(EventLog *log, char *event) {
    if (log->head - log->tail >= log->capacity) {
        log->tail = (log->tail + 1) % log->capacity;
    }

    int event_size = strlen(event) + 1;
    memcpy(log->events + log->head * MAX_EVENT_SIZE, event, event_size);
    log->head = (log->head + 1) % log->capacity;
}

void eventLog_print(EventLog *log) {
    for (int i = log->tail; i != log->head; i = (i + 1) % log->capacity) {
        int event_size = log->events[i * MAX_EVENT_SIZE] - 1;
        printf("%.*s\n", event_size, log->events + i * MAX_EVENT_SIZE);
    }
}

int main() {
    EventLog *log = eventLog_init(10);

    eventLog_add(log, "This is the first event.");
    eventLog_add(log, "This is the second event.");
    eventLog_add(log, "This is the third event.");

    eventLog_print(log);

    return 0;
}