//Falcon-180B DATASET v1.0 Category: System event logger ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 100

typedef struct {
    char event[EVENT_SIZE];
    time_t timestamp;
} Event;

int event_count = 0;
Event events[MAX_EVENTS];

void log_event(char* event_str) {
    struct tm* now;
    time_t current_time = time(NULL);
    now = localtime(&current_time);

    strftime(event_str, EVENT_SIZE, "%Y-%m-%d %H:%M:%S", now);

    strcat(event_str, " ");
    strcat(event_str, event_str + strlen(event_str) - 3);

    if (event_count >= MAX_EVENTS) {
        printf("Event buffer full!\n");
        return;
    }

    strcpy(events[event_count].event, event_str);
    events[event_count].timestamp = current_time;

    event_count++;
}

void print_events() {
    int i;
    for (i = 0; i < event_count; i++) {
        printf("%s - %s\n", events[i].event, ctime(&events[i].timestamp));
    }
}

int main() {
    log_event("Program started");

    // Simulate some events
    log_event("Button clicked");
    log_event("File saved");
    log_event("Network request sent");

    // Print event log
    print_events();

    return 0;
}