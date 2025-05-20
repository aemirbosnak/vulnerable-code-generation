//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_EVENT_SIZE 1024
#define MAX_EVENT_COUNT 1000

typedef struct {
    char timestamp[20];
    char event_type[50];
    char message[1024];
} event_t;

event_t events[MAX_EVENT_COUNT];
int event_count = 0;

void log_event(const char* event_type, const char* message) {
    char timestamp[20];
    struct tm now;
    char str_time[20];

    // Get the current time
    time_t now_time = time(NULL);
    localtime_r(&now_time, &now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &now);

    // Create a new event
    event_t new_event;
    strcpy(new_event.timestamp, timestamp);
    strcpy(new_event.event_type, event_type);
    strcpy(new_event.message, message);

    // Add the new event to the event array
    memmove(&events[event_count], &new_event, sizeof(event_t));
    event_count++;

    // If the event count exceeds the maximum, overwrite the oldest event
    if (event_count > MAX_EVENT_COUNT) {
        event_count = MAX_EVENT_COUNT;
        memmove(&events[0], &events[1], (event_count - 1) * sizeof(event_t));
    }
}

void print_events() {
    int i;
    for (i = 0; i < event_count; i++) {
        printf("%s: %s %s\n", events[i].timestamp, events[i].event_type, events[i].message);
    }
}

int main() {
    // Example usage of the log_event function
    log_event("INFO", "System started");
    log_event("WARNING", "Memory usage high");
    log_event("ERROR", "File not found");

    // Print the events
    print_events();

    return 0;
}