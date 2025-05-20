//Gemma-7B DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog
{
    char **events;
    int size;
    int capacity;
} EventLog;

void event_log_init(EventLog *log, int capacity)
{
    log->events = (char **)malloc(capacity * sizeof(char *));
    log->size = 0;
    log->capacity = capacity;
}

void event_log_add(EventLog *log, char *event)
{
    if (log->size == log->capacity)
    {
        log->events = (char **)realloc(log->events, log->capacity * 2 * sizeof(char *));
        log->capacity *= 2;
    }

    log->events[log->size++] = event;
}

void event_log_print(EventLog *log)
{
    for (int i = 0; i < log->size; i++)
    {
        printf("%s\n", log->events[i]);
    }
}

int main()
{
    EventLog log;
    event_log_init(&log, MAX_EVENT_SIZE);

    event_log_add(&log, "The hero battles the dragon.");
    event_log_add(&log, "The damsel is rescued.");
    event_log_add(&log, "The villain is defeated.");

    event_log_print(&log);

    return 0;
}