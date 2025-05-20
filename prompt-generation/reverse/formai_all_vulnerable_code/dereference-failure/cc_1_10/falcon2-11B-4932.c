//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define a structure to hold event log data
typedef struct {
    char event_name[50];
    int timestamp;
    char description[100];
} EventLog;

// Function to generate a unique event log ID
int generateEventId() {
    srand(time(NULL));
    int id = rand();
    while (id == 0) {
        id = rand();
    }
    return id;
}

// Function to print event log details
void printEventLog(EventLog *event_log) {
    printf("Event: %s\n", event_log->event_name);
    printf("Timestamp: %d\n", event_log->timestamp);
    printf("Description: %s\n", event_log->description);
}

// Function to add a new event log to the event log array
void addEventLog(EventLog *event_logs, int eventId, char *eventName, char *description) {
    EventLog *newEventLog = (EventLog *)malloc(sizeof(EventLog));
    strcpy(newEventLog->event_name, eventName);
    newEventLog->timestamp = eventId;
    strcpy(newEventLog->description, description);
    eventId++;
    event_logs[eventId - 1] = *newEventLog;
}

// Function to display all event logs
void displayEventLogs(EventLog *event_logs) {
    int i = 0;
    printf("Event Logs:\n");
    while (i < event_logs[i].timestamp) {
        printf("Event ID: %d\n", event_logs[i].timestamp);
        printEventLog(&event_logs[i]);
        i++;
    }
}

int main() {
    // Create an array to hold event logs
    EventLog *event_logs = (EventLog *)malloc(100 * sizeof(EventLog));
    int eventId = 0;

    // Generate and print event logs
    addEventLog(event_logs, eventId, "Event 1", "This is the first event log");
    addEventLog(event_logs, eventId, "Event 2", "This is the second event log");
    addEventLog(event_logs, eventId, "Event 3", "This is the third event log");

    // Display event logs
    displayEventLogs(event_logs);

    // Free memory
    for (int i = 0; i < 100; i++) {
        free(event_logs[i].event_name);
        free(event_logs[i].description);
        free(event_logs[i].event_name);
    }
    free(event_logs);

    return 0;
}