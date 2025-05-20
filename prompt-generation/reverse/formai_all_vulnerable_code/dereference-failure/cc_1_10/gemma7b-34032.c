//Gemma-7B DATASET v1.0 Category: System event logger ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024

typedef struct EventLog
{
    char timestamp[26];
    char event_type[64];
    char event_data[MAX_EVENT_SIZE];
} EventLog;

EventLog event_log[100];

int event_log_index = 0;

void log_event(char *type, char *data)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);

    event_log[event_log_index].timestamp[0] = tm->tm_hour;
    event_log[event_log_index].timestamp[1] = tm->tm_min;
    event_log[event_log_index].timestamp[2] = tm->tm_sec;

    event_log[event_log_index].event_type[0] = type[0];
    event_log[event_log_index].event_type[1] = type[1];
    event_log[event_log_index].event_type[2] = '\0';

    event_log[event_log_index].event_data[0] = '\0';
    if (data)
    {
        strncpy(event_log[event_log_index].event_data, data, MAX_EVENT_SIZE - 1);
    }

    event_log_index++;

    if (event_log_index >= 100)
    {
        event_log_index = 0;
    }
}

int main()
{
    log_event("Player Joined", "John Doe");
    log_event("Item Picked Up", "Sword");
    log_event("Chat Message", "Hello, world!");

    int i = 0;
    for (i = 0; i < event_log_index; i++)
    {
        printf("Timestamp: %s\n", event_log[i].timestamp);
        printf("Event Type: %s\n", event_log[i].event_type);
        printf("Event Data: %s\n", event_log[i].event_data);
        printf("\n");
    }

    return 0;
}