//Gemma-7B DATASET v1.0 Category: System event logger ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024

typedef struct EventLog {
    char *events;
    int size;
    int capacity;
} EventLog;

EventLog *eventLog_init(int capacity) {
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(capacity * MAX_EVENT_SIZE);
    log->size = 0;
    log->capacity = capacity;

    return log;
}

void eventLog_add(EventLog *log, char *event) {
    if (log->size >= log->capacity) {
        return;
    }

    log->events[log->size++] = event;
}

void eventLog_print(EventLog *log) {
    for (int i = 0; i < log->size; i++) {
        printf("%s\n", log->events[i]);
    }
}

int main() {
    EventLog *log = eventLog_init(10);

    eventLog_add(log, "Hello, world!");
    eventLog_add(log, "This is an event.");
    eventLog_add(log, "The sky is blue.");

    eventLog_print(log);

    free(log->events);
    free(log);

    return 0;
}