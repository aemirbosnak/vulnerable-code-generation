//Gemma-7B DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog
{
    char *events;
    int size;
    int capacity;
} EventLog;

EventLog *createEventLog(int capacity)
{
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(capacity * MAX_EVENT_SIZE);
    log->size = 0;
    log->capacity = capacity;
    return log;
}

void logEvent(EventLog *log, char *event)
{
    if (log->size >= log->capacity)
    {
        // Log full, need to expand
        log->events = realloc(log->events, log->capacity * MAX_EVENT_SIZE * 2);
        log->capacity *= 2;
    }

    int event_size = strlen(event) + 1;
    memcpy(log->events + log->size, event, event_size);
    log->size += event_size;
}

void printEvents(EventLog *log)
{
    for (int i = 0; i < log->size; i++)
    {
        printf("%s\n", log->events[i]);
    }
}

int main()
{
    EventLog *log = createEventLog(10);

    logEvent(log, "Hello, world!");
    logEvent(log, "This is an event.");
    logEvent(log, "Another event.");

    printEvents(log);

    free(log->events);
    free(log);

    return 0;
}