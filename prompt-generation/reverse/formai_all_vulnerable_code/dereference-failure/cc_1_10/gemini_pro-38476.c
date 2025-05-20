//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_EVENT_LEN 1000

typedef struct {
    char *message;
    time_t timestamp;
} event_t;

event_t events[MAX_EVENTS];
int event_count = 0;

void log_event(const char *format, ...) {
    if (event_count == MAX_EVENTS) {
        fprintf(stderr, "Event log is full\n");
        return;
    }

    va_list args;
    va_start(args, format);
    char *message = malloc(MAX_EVENT_LEN);
    vsnprintf(message, MAX_EVENT_LEN, format, args);
    va_end(args);

    events[event_count].message = message;
    events[event_count].timestamp = time(NULL);
    event_count++;
}

void print_events() {
    for (int i = 0; i < event_count; i++) {
        printf("%ld: %s\n", events[i].timestamp, events[i].message);
    }
}

int main() {
    log_event("Program started");
    log_event("User logged in");
    log_event("User created a new file");
    log_event("User saved the file");
    log_event("User closed the program");

    print_events();

    return 0;
}