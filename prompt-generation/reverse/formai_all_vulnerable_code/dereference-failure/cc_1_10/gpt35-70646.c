//FormAI DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Event structure
typedef struct event {
    time_t timestamp;
    char* message;
} Event;

// Event log
typedef struct eventLog {
    Event* events;
    int capacity;
    int size;
} EventLog;

// Function to create event
Event createEvent(char* message) {
    Event event;
    event.timestamp = time(NULL);
    event.message = message;
    return event;
}

// Function to create event log
EventLog createEventLog(int capacity) {
    EventLog log;
    log.events = malloc(capacity * sizeof(Event));
    log.capacity = capacity;
    log.size = 0;
    return log;
}

// Function to add event to log
void addEvent(Event event, EventLog* log) {
    // Check if log is full
    if (log->size >= log->capacity) {
        // Double the capacity of the log
        log->capacity *= 2;
        log->events = realloc(log->events, log->capacity * sizeof(Event));
    }
    // Add event to log
    log->events[log->size] = event;
    log->size++;
}

// Function to print event log
void printEventLog(EventLog log) {
    printf("Event Log:\n");
    for (int i = 0; i < log.size; i++) {
        Event event = log.events[i];
        printf("[%s]: %s\n", ctime(&(event.timestamp)), event.message);
    }
}

// Example program
int main() {
    // Create event log
    EventLog log = createEventLog(10);
    
    // Add events to log
    addEvent(createEvent("System started."), &log);
    addEvent(createEvent("File opened."), &log);
    addEvent(createEvent("Connection established."), &log);
    addEvent(createEvent("User authenticated."), &log);
    addEvent(createEvent("System shutdown initiated."), &log);
    addEvent(createEvent("File closed."), &log);
    addEvent(createEvent("Connection closed."), &log);
    addEvent(createEvent("System shutdown complete."), &log);
    
    // Print event log
    printEventLog(log);
    
    // Free memory
    free(log.events);
    
    return 0;
}