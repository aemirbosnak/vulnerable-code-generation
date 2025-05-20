//FormAI DATASET v1.0 Category: System event logger ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define Event Struct
typedef struct {
    char* timestamp;
    char* eventMessage;
} Event;

// Define EventLog Struct
typedef struct {
    Event* events;
    int numEvents;
} EventLog;

// Function to Add Event to Event Log
void addEvent(EventLog *log, char* message) {
    // Get Current Timestamp
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char* timestamp = asctime(&tm);
    // Create Event
    Event newEvent;
    newEvent.timestamp = timestamp;
    newEvent.eventMessage = message;
    // Add Event to Log
    log->events = realloc(log->events, (log->numEvents+1) * sizeof(Event));
    log->events[log->numEvents] = newEvent;
    log->numEvents++;
}

// Function to Print Event Log
void printLog(EventLog log) {
    printf("Event Log:\n");
    for (int i=0; i<log.numEvents; i++) {
        printf("[%s] %s\n", log.events[i].timestamp, log.events[i].eventMessage);
    }
}

int main() {
    // Create Event Log
    EventLog log;
    log.numEvents = 0;
    log.events = malloc(0);
    
    // Add Events to Log
    addEvent(&log, "Program Started");
    addEvent(&log, "Error: File Not Found");
    addEvent(&log, "File Loaded Successfully");
    
    // Print Log
    printLog(log);
    
    // Free Memory
    free(log.events);
    
    return 0;
}