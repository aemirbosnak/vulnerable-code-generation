//Gemma-7B DATASET v1.0 Category: System event logger ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
    char *events;
    int size;
    int head;
    int tail;
} EventLog;

void initEventLog(EventLog *log) {
    log->events = (char *)malloc(MAX_LOG_SIZE);
    log->size = MAX_LOG_SIZE;
    log->head = 0;
    log->tail = 0;
}

void logEvent(EventLog *log, char *event) {
    time_t t = time(NULL);
    char timestamp[20];
    strftime(timestamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&t));

    if (log->tail - log->head >= log->size) {
        log->head = (log->head + 1) % log->size;
    }

    int event_size = strlen(event) + 1;
    log->events[log->tail] = (char *)malloc(event_size);
    strcpy(log->events[log->tail], event);
    log->tail = (log->tail + 1) % log->size;
}

int main() {
    EventLog log;
    initEventLog(&log);

    logEvent(&log, "John Doe bought a banana.");
    logEvent(&log, "Mary Smith went to the park.");
    logEvent(&log, "Bob White cooked a pizza.");

    printf("Events:");
    for (int i = 0; i < log.tail - log.head; i++) {
        printf("\n%s", log.events[log.head + i]);
    }

    return 0;
}