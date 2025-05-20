//Gemma-7B DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 1024

typedef struct EventLog {
    char **events;
    int capacity;
    int head;
    int tail;
} EventLog;

EventLog *event_log_create(int capacity) {
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(sizeof(char *) * capacity);
    log->capacity = capacity;
    log->head = 0;
    log->tail = -1;

    return log;
}

void event_log_add(EventLog *log, char *event) {
    log->events[++log->tail] = event;
    if (log->tail == log->capacity - 1) {
        log->tail = -1;
    }
}

void event_log_print(EventLog *log) {
    for (int i = log->head; i <= log->tail; i++) {
        printf("%s\n", log->events[i]);
    }
}

int main() {
    EventLog *log = event_log_create(MAX_EVENT_SIZE);

    event_log_add(log, "Hello, world!");
    event_log_add(log, "This is an event.");
    event_log_add(log, "The sky is blue.");

    event_log_print(log);

    free(log->events);
    free(log);

    return 0;
}