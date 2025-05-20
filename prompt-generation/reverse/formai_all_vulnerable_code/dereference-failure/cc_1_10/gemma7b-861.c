//Gemma-7B DATASET v1.0 Category: System event logger ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog
{
    char **events;
    int capacity;
    int head;
    int tail;
} EventLog;

EventLog *eventLog_init(int capacity)
{
    EventLog *log = malloc(sizeof(EventLog));
    log->events = malloc(sizeof(char *) * capacity);
    log->capacity = capacity;
    log->head = 0;
    log->tail = -1;

    return log;
}

void eventLog_add(EventLog *log, char *event)
{
    if (log->tail == log->head - 1)
    {
        log->events = realloc(log->events, log->capacity * 2);
        log->capacity *= 2;
        log->tail = log->head - 1;
    }

    log->events[++log->tail] = strdup(event);
}

void eventLog_print(EventLog *log)
{
    for (int i = log->head; i <= log->tail; i++)
    {
        printf("%s\n", log->events[i]);
    }
}

int main()
{
    EventLog *log = eventLog_init(10);

    eventLog_add(log, "The cat jumped on the mat.");
    eventLog_add(log, "The dog barked at the mailman.");
    eventLog_add(log, "The house burned down.");

    eventLog_print(log);

    return 0;
}