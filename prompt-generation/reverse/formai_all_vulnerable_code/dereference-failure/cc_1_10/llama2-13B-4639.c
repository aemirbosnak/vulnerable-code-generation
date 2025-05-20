//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_LENGTH 256
#define MAX_EVENT_COUNT 100

typedef struct {
    char name[64];
    char message[256];
    time_t timestamp;
} event_t;

event_t events[MAX_EVENT_COUNT];
int event_count = 0;

void log_event(const char *name, const char *message) {
    event_t *new_event = malloc(sizeof(event_t));
    strcpy(new_event->name, name);
    strcpy(new_event->message, message);
    new_event->timestamp = time(NULL);
    if (event_count >= MAX_EVENT_COUNT) {
        // Roll back to the beginning of the array if full
        for (int i = 0; i < MAX_EVENT_COUNT; i++) {
            if (events[i].timestamp < new_event->timestamp) {
                memmove(&events[i + 1], &events[i], sizeof(event_t) * (MAX_EVENT_COUNT - i - 1));
                break;
            }
        }
        memcpy(&events[0], new_event, sizeof(event_t));
        event_count++;
    } else {
        memcpy(&events[event_count], new_event, sizeof(event_t));
        event_count++;
    }
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("Event: %s - %s at %s\n", events[i].name, events[i].message, ctime(&events[i].timestamp));
    }
}

int main() {
    log_event("User", "Logged in");
    log_event("User", "Logged out");
    log_event("System", "Crash detected");
    log_event("System", "Recovered from crash");
    print_events();
    return 0;
}