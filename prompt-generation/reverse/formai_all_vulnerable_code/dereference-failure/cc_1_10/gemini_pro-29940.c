//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#define MAX_EVENTS 100
#define MAX_EVENT_SIZE 1024

typedef struct event {
    char *message;
    time_t timestamp;
} event;

event events[MAX_EVENTS];
int event_count = 0;

void log_event(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    char buffer[MAX_EVENT_SIZE];
    vsnprintf(buffer, MAX_EVENT_SIZE, fmt, args);

    if (event_count < MAX_EVENTS) {
        events[event_count].message = malloc(strlen(buffer) + 1);
        strcpy(events[event_count].message, buffer);
        events[event_count].timestamp = time(NULL);
        event_count++;
    }

    va_end(args);
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("%s: %s\n", ctime(&events[i].timestamp), events[i].message);
    }
}

int main() {
    log_event("Started program at %s", ctime(&events[0].timestamp));

    // Do some stuff...

    log_event("Finished program at %s", ctime(&events[MAX_EVENTS - 1].timestamp));

    print_events();

    return 0;
}