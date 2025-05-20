//Gemma-7B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 1024

typedef struct EventLog
{
    char **events;
    int size;
    int capacity;
} EventLog;

void event_log_init(EventLog *log, int capacity)
{
    log->events = NULL;
    log->size = 0;
    log->capacity = capacity;

    log->events = (char **)malloc(capacity * sizeof(char *));

    for (int i = 0; i < capacity; i++)
    {
        log->events[i] = (char *)malloc(MAX_EVENT_SIZE);
    }
}

void event_log_add(EventLog *log, char *event)
{
    if (log->size == log->capacity)
    {
        // Expand the log if necessary
        log->events = (char **)realloc(log->events, log->capacity * 2 * sizeof(char *));

        for (int i = log->capacity; i < log->capacity * 2; i++)
        {
            log->events[i] = (char *)malloc(MAX_EVENT_SIZE);
        }

        log->capacity *= 2;
    }

    log->events[log->size++] = event;
}

int main()
{
    EventLog log;
    event_log_init(&log, 10);

    event_log_add(&log, "Hello, world!");
    event_log_add(&log, "This is a test event.");
    event_log_add(&log, "Foo bar!");

    for (int i = 0; i < log.size; i++)
    {
        printf("%s\n", log.events[i]);
    }

    return 0;
}