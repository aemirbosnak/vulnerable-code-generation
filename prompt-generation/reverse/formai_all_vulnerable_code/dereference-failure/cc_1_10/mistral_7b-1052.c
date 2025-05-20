//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LEN 256

// Struct to hold event data
typedef struct {
    char event[MAX_EVENT_LEN];
    time_t timestamp;
} Event;

// Global variables
Event events[MAX_EVENTS];
int num_events = 0;

// Function to log events
void log_event(const char *event_str) {
    if (num_events >= MAX_EVENTS) {
        printf("Error: Maximum number of events reached!\n");
        return;
    }

    strncpy(events[num_events].event, event_str, MAX_EVENT_LEN);
    events[num_events].timestamp = time(NULL);
    num_events++;
}

// Function to print all logged events
void print_events() {
    int i;

    printf("\nCurrent Events:\n");
    for (i = 0; i < num_events; i++) {
        printf("%d. %s [%s]\n", i + 1, events[i].event, ctime(&events[i].timestamp));
    }
}

// Main function
int main(int argc, char *argv[]) {
    int i;

    if (argc < 2) {
        printf("Usage: %s <event>\n", argv[0]);
        return 1;
    }

    log_event(argv[1]);
    print_events();

    for (i = 0; i < num_events; i++) {
        if (strcmp(events[i].event, argv[1]) == 0) {
            printf("\nEvent \"%s\" found in logs at %s\n", argv[1], ctime(&events[i].timestamp));
            break;
        }
    }

    return 0;
}