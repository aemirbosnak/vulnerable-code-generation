//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 100
#define EVENT_SIZE 100

typedef struct {
    char timestamp[20];
    char event_type[30];
    char description[EVENT_SIZE];
} Event;

Event* events = NULL;
int event_count = 0;
int event_capacity = 0;

void log_event(const char* event_type, const char* description) {
    if (event_count >= event_capacity) {
        event_capacity *= 2;
        events = realloc(events, event_capacity * sizeof(Event));
        if (!events) {
            fprintf(stderr, "Failed to allocate memory for event logger\n");
            exit(1);
        }
    }

    time_t now = time(NULL);
    strftime(events[event_count].timestamp, sizeof(events[event_count].timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    strcpy(events[event_count].event_type, event_type);
    strcpy(events[event_count].description, description);
    event_count++;
}

void print_events() {
    if (!event_count) {
        printf("No events logged\n");
        return;
    }

    printf("\nEvent Log:\n");
    printf("--------------------\n");
    for (int i = 0; i < event_count; i++) {
        printf("%s - %s: %s\n", events[i].timestamp, events[i].event_type, events[i].description);
    }
    printf("--------------------\n");
}

int main() {
    log_event("INFO", "Program started");

    // Example usage
    for (int i = 0; i < 5; i++) {
        log_event("ERROR", ("Error occurred: %d", rand() % 100));
    }

    print_events();

    free(events);

    return 0;
}