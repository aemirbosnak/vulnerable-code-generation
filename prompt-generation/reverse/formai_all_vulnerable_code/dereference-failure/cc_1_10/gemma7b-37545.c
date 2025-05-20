//Gemma-7B DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1024
#define LOG_FILE_NAME "event_log.txt"

typedef struct EventLogEvent {
    char *description;
    int timestamp;
    struct EventLogEvent *next;
} EventLogEvent;

EventLogEvent *addEventLogEvent(char *description)
{
    EventLogEvent *newEvent = malloc(sizeof(EventLogEvent));
    newEvent->description = strdup(description);
    newEvent->timestamp = time(NULL);
    newEvent->next = NULL;

    return newEvent;
}

void writeEventLog(EventLogEvent *event)
{
    FILE *logFile = fopen(LOG_FILE_NAME, "a");
    fprintf(logFile, "%d: %s\n", event->timestamp, event->description);
    fclose(logFile);
}

int main()
{
    EventLogEvent *head = NULL;

    // Simulate logging some events
    addEventLogEvent("User logged in");
    addEventLogEvent("Order placed");
    addEventLogEvent("Payment processed");

    // Write the events to the log file
    for (EventLogEvent *event = head; event; event = event->next)
    {
        writeEventLog(event);
    }

    // Print the events from the log file
    FILE *logFile = fopen(LOG_FILE_NAME, "r");
    char line[MAX_LOG_SIZE];
    while (fgets(line, MAX_LOG_SIZE, logFile) != NULL)
    {
        printf("%s", line);
    }
    fclose(logFile);

    return 0;
}