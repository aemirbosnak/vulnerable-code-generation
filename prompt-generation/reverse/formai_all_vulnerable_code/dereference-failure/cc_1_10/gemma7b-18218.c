//Gemma-7B DATASET v1.0 Category: System event logger ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog
{
    char timestamp[MAX_EVENT_SIZE];
    char event_name[MAX_EVENT_SIZE];
    char event_data[MAX_EVENT_SIZE];
    struct EventLog* next;
} EventLog;

EventLog* createEventLog(char* name, char* data)
{
    EventLog* new_event = malloc(sizeof(EventLog));

    time_t t = time(NULL);
    strftime(new_event->timestamp, MAX_EVENT_SIZE, "%Y-%m-%d %H:%M:%S", localtime(&t));

    strcpy(new_event->event_name, name);
    strcpy(new_event->event_data, data);

    new_event->next = NULL;

    return new_event;
}

void logEvent(EventLog* event_log, char* name, char* data)
{
    EventLog* new_event = createEventLog(name, data);

    if (event_log)
    {
        new_event->next = event_log;
    }

    event_log = new_event;
}

int main()
{
    EventLog* event_log = NULL;

    logEvent(event_log, "User logged in", "John Doe");
    logEvent(event_log, "Order placed", "Product A");
    logEvent(event_log, "Payment processed", "Credit card");

    for (EventLog* event = event_log; event; event = event->next)
    {
        printf("Timestamp: %s\n", event->timestamp);
        printf("Event name: %s\n", event->event_name);
        printf("Event data: %s\n", event->event_data);
        printf("\n");
    }

    return 0;
}