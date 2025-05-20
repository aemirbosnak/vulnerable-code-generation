//Gemma-7B DATASET v1.0 Category: System event logger ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 256

struct EventLog
{
    char **events;
    int size;
    int capacity;
    time_t timestamp;
};

void log_event(struct EventLog *log, char *event)
{
    if (log->size == log->capacity)
    {
        log->events = realloc(log->events, log->capacity * 2);
        log->capacity *= 2;
    }

    log->events[log->size++] = strdup(event);
    log->timestamp = time(NULL);
}

int main()
{
    struct EventLog *log = malloc(sizeof(struct EventLog));
    log->events = NULL;
    log->size = 0;
    log->capacity = MAX_EVENT_SIZE;
    log->timestamp = 0;

    log_event(log, "The cat jumped on the mat.");
    log_event(log, "The dog barked at the mailman.");
    log_event(log, "The house burned down.");

    printf("Events:");
    for (int i = 0; i < log->size; i++)
    {
        printf("\n%s", log->events[i]);
    }

    printf("\nTimestamp:");
    for (int i = 0; i < log->size; i++)
    {
        printf("\n%ld", log->timestamp);
    }

    free(log->events);
    free(log);

    return 0;
}