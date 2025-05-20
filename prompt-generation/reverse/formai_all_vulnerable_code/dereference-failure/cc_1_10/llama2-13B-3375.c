//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <syslog.h>

#define MAX_EVENT_LENGTH 1024
#define MAX_EVENT_COUNT 1000

typedef struct {
    char *message;
    time_t timestamp;
} event_t;

event_t events[MAX_EVENT_COUNT];
int event_count = 0;

void log_event(const char *message) {
    time_t now = time(NULL);
    char timestamp_str[20];
    strftime(timestamp_str, sizeof(timestamp_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    event_t *new_event = malloc(sizeof(event_t));
    new_event->message = message;
    new_event->timestamp = now;

    if (event_count >= MAX_EVENT_COUNT) {
        // Roll over to the beginning of the array
        for (int i = 0; i < event_count; i++) {
            events[i] = events[event_count - i - 1];
        }
        event_count = 0;
    }

    events[event_count++] = *new_event;
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("%s %s\n", events[i].timestamp, events[i].message);
    }
}

int main() {
    log_event("Booting up...");
    log_event("Initializing system...");
    log_event("Starting services...");

    // Sleep for 10 seconds to generate more events
    sleep(10);

    print_events();

    return 0;
}