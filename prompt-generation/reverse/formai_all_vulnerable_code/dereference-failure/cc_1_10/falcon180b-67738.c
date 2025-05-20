//Falcon-180B DATASET v1.0 Category: System event logger ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of events that can be logged
#define MAX_EVENTS 100

// Define the structure for an event
typedef struct {
    char* eventName;
    time_t eventTime;
} Event;

// Define the function for logging an event
void logEvent(Event* event) {
    FILE* file = fopen("event_log.txt", "a");
    if (file == NULL) {
        printf("Error: could not open event log file.\n");
        exit(1);
    }
    fprintf(file, "%s,%ld\n", event->eventName, event->eventTime);
    fclose(file);
}

// Define the function for reading the event log
void readEventLog() {
    FILE* file = fopen("event_log.txt", "r");
    if (file == NULL) {
        printf("Error: could not open event log file.\n");
        exit(1);
    }
    char line[80];
    while (fgets(line, sizeof(line), file)!= NULL) {
        printf("%s", line);
    }
    fclose(file);
}

int main() {
    // Initialize the event log
    FILE* file = fopen("event_log.txt", "w");
    if (file == NULL) {
        printf("Error: could not create event log file.\n");
        exit(1);
    }
    fprintf(file, "Event Name,Event Time\n");
    fclose(file);

    // Log some events
    Event events[MAX_EVENTS];
    int numEvents = 0;
    events[numEvents].eventName = strdup("Program Started");
    events[numEvents].eventTime = time(NULL);
    logEvent(&events[numEvents]);
    numEvents++;

    events[numEvents].eventName = strdup("User Logged In");
    events[numEvents].eventTime = time(NULL);
    logEvent(&events[numEvents]);
    numEvents++;

    events[numEvents].eventName = strdup("File Opened");
    events[numEvents].eventTime = time(NULL);
    logEvent(&events[numEvents]);
    numEvents++;

    // Read the event log
    readEventLog();

    return 0;
}