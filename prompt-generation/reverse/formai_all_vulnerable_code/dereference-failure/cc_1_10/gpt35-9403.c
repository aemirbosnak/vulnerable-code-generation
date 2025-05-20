//FormAI DATASET v1.0 Category: System event logger ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    time_t timestamp;
    char* event;
} EventLogItem;

typedef struct {
    EventLogItem* events;
    int size;
    int capacity;
} EventLog;

// Function to initialize a new event log
EventLog* initEventLog() {
    EventLog* log = malloc(sizeof(EventLog));
    log->events = malloc(sizeof(EventLogItem) * 10);
    log->size = 0;
    log->capacity = 10;
    return log;
}

// Function to add an event to the log
void addEvent(EventLog* log, char* event) {
    // If the log reaches its capacity, double the capacity
    if (log->size == log->capacity) {
        log->events = realloc(log->events, sizeof(EventLogItem) * log->capacity * 2);
        log->capacity *= 2;
    }

    // Create a new EventLogItem and add it to the log
    EventLogItem newEvent = { time(NULL), event };
    log->events[log->size] = newEvent;
    log->size++;
}

// Function to print out all events in the log
void printEventLog(EventLog* log) {
    printf("Event Log:\n");
    for (int i = 0; i < log->size; i++) {
        printf("%ld : %s\n", log->events[i].timestamp, log->events[i].event);
    }
}

int main() {
    EventLog* log = initEventLog();

    // Add some sample events to the log
    addEvent(log, "Program started");
    addEvent(log, "File opened");
    addEvent(log, "Data loaded successfully");
    addEvent(log, "User logged in");

    // Print out the whole event log
    printEventLog(log);

    // Free up memory used by the event log
    free(log->events);
    free(log);
    
    return 0;
}