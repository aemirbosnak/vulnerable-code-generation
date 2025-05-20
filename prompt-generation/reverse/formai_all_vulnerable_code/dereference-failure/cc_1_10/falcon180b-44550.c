//Falcon-180B DATASET v1.0 Category: System event logger ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENT_LENGTH 1000
#define MAX_LOG_LENGTH 1000000

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    Event *events;
    int num_events;
    int event_index;
} EventLog;

void init_event_log(EventLog *log) {
    log->events = (Event *) malloc(MAX_LOG_LENGTH * sizeof(Event));
    log->num_events = 0;
    log->event_index = 0;
}

void log_event(EventLog *log, const char *event) {
    if (log->num_events == MAX_LOG_LENGTH) {
        printf("Log is full, cannot log event.\n");
        return;
    }

    strncpy(log->events[log->num_events].event, event, MAX_EVENT_LENGTH);
    log->events[log->num_events].timestamp = time(NULL);
    log->num_events++;
}

void print_event_log(EventLog *log) {
    printf("Event Log:\n");
    printf("--------------------\n");

    for (int i = 0; i < log->num_events; i++) {
        printf("%s: %s\n", ctime(&log->events[i].timestamp), log->events[i].event);
    }
}

int main() {
    EventLog log;
    init_event_log(&log);

    log_event(&log, "Romeo and Juliet meet at the party");
    log_event(&log, "Romeo and Juliet profess their love for each other");
    log_event(&log, "Romeo and Juliet decide to get married in secret");
    log_event(&log, "Friar Laurence agrees to marry Romeo and Juliet");
    log_event(&log, "Tybalt challenges Romeo to a duel");
    log_event(&log, "Romeo kills Tybalt and is banished from Verona");
    log_event(&log, "Friar Laurence gives Juliet a potion to fake her death");
    log_event(&log, "Romeo believes Juliet is dead and takes his own life");
    log_event(&log, "Juliet wakes up and sees Romeo dead, then takes her own life");

    print_event_log(&log);

    return 0;
}