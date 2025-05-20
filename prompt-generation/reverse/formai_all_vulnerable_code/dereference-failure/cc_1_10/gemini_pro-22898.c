//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <sys/syslog.h>
#include <err.h>

#define MAX_EVENTS 100

typedef struct {
    time_t timestamp;
    char *message;
} event_t;

event_t events[MAX_EVENTS];
uint32_t event_count = 0;

void add_event(const char *message) {
    if (event_count >= MAX_EVENTS) {
        warnx("Event log is full");
        return;
    }

    events[event_count].timestamp = time(NULL);
    events[event_count].message = strdup(message);
    event_count++;
}

void print_events() {
    for (uint32_t i = 0; i < event_count; i++) {
        printf("%ld: %s\n", events[i].timestamp, events[i].message);
    }
}

void clean_events() {
    for (uint32_t i = 0; i < event_count; i++) {
        free(events[i].message);
    }
    event_count = 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        errx(1, "Usage: %s <message>", argv[0]);
    }

    openlog("sample_logger", LOG_PID | LOG_CONS, LOG_USER);

    syslog(LOG_INFO, "%s", argv[1]);

    add_event(argv[1]);

    print_events();

    clean_events();

    closelog();

    return 0;
}