//Gemma-7B DATASET v1.0 Category: System event logger ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
    char *events;
    int size;
    int capacity;
} EventLog;

EventLog *createEventLog(int capacity) {
    EventLog *log = (EventLog *)malloc(sizeof(EventLog));
    log->events = (char *)malloc(capacity * MAX_LOG_SIZE);
    log->size = 0;
    log->capacity = capacity;
    return log;
}

void logEvent(EventLog *log, char *event) {
    time_t t = time(NULL);
    char timestamp[26] = "";
    strftime(timestamp, 26, "%Y-%m-%d %H:%M:%S", localtime(&t));
    event = strcat(event, ", ");
    event = strcat(event, timestamp);
    event = strcat(event, "\n");
    if (log->size == log->capacity) {
        log->events = (char *)realloc(log->events, log->capacity * MAX_LOG_SIZE * 2);
        log->capacity *= 2;
    }
    memcpy(log->events + log->size, event, strlen(event));
    log->size++;
}

int main() {
    EventLog *log = createEventLog(10);
    logEvent(log, "John Doe logged in");
    logEvent(log, "Mary Jane bought a book");
    logEvent(log, "Peter Pan flew to Neverland");
    logEvent(log, "The cat sat on the mat");

    printf("Events:");
    for (int i = 0; i < log->size; i++) {
        printf("%s", log->events[i]);
    }

    printf("\n");

    free(log->events);
    free(log);

    return 0;
}