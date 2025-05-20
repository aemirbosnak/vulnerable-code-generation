//Gemma-7B DATASET v1.0 Category: System event logger ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024

typedef struct EventLog
{
    char **events;
    int size;
    int capacity;
    time_t timestamp;
} EventLog;

void log_event(EventLog *log, char *event)
{
    if (log->size >= log->capacity)
    {
        log->events = realloc(log->events, log->capacity * 2);
        log->capacity *= 2;
    }

    log->events[log->size++] = event;
    log->timestamp = time(NULL);
}

int main()
{
    EventLog *log = malloc(sizeof(EventLog));
    log->events = NULL;
    log->size = 0;
    log->capacity = 16;
    log->timestamp = 0;

    log_event(log, "User logged in");
    log_event(log, "Purchased item: XYZ");
    log_event(log, "Added item to cart: ABC");
    log_event(log, "User checked out");

    for (int i = 0; i < log->size; i++)
    {
        printf("%s - %s\n", log->events[i], log->timestamp);
    }

    free(log->events);
    free(log);

    return 0;
}