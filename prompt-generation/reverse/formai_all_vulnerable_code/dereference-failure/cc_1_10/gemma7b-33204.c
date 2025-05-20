//Gemma-7B DATASET v1.0 Category: System event logger ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog {
    char **events;
    int size;
    int capacity;
} EventLog;

EventLog *event_log_init(int capacity) {
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(sizeof(char *) * capacity);
    log->size = 0;
    log->capacity = capacity;

    return log;
}

void event_log_add(EventLog *log, char *event) {
    if (log->size == log->capacity) {
        log->events = realloc(log->events, sizeof(char *) * log->capacity * 2);
        log->capacity *= 2;
    }

    log->events[log->size++] = strdup(event);
}

void event_log_print(EventLog *log) {
    for (int i = 0; i < log->size; i++) {
        printf("%s\n", log->events[i]);
    }
}

int main() {
    EventLog *log = event_log_init(10);

    event_log_add(log, "User logged in");
    event_log_add(log, "User purchased item");
    event_log_add(log, "User clicked on advertisement");

    event_log_print(log);

    free(log->events);
    free(log);

    return 0;
}