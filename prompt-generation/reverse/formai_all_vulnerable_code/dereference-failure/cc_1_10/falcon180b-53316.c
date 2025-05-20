//Falcon-180B DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LOG_SIZE 1000
#define MAX_EVENT_LENGTH 256

typedef struct {
    char event[MAX_EVENT_LENGTH];
    time_t timestamp;
} Event;

typedef struct {
    Event *events;
    int size;
    int capacity;
} Log;

void init_log(Log *log) {
    log->events = malloc(MAX_LOG_SIZE * sizeof(Event));
    log->size = 0;
    log->capacity = MAX_LOG_SIZE;
}

void log_event(Log *log, const char *event) {
    if (log->size >= log->capacity) {
        printf("Log is full. Event '%s' was not logged.\n", event);
        return;
    }

    Event *e = &log->events[log->size];
    strncpy(e->event, event, MAX_EVENT_LENGTH);
    e->timestamp = time(NULL);

    log->size++;
}

void print_log(Log *log) {
    if (log->size == 0) {
        printf("Log is empty.\n");
        return;
    }

    printf("Log:\n");
    for (int i = 0; i < log->size; i++) {
        Event *e = &log->events[i];
        printf("%s - %s\n", ctime(&e->timestamp), e->event);
    }
}

int main() {
    Log log;
    init_log(&log);

    log_event(&log, "Program started");

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Log event\n");
        printf("2. Print log\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char event[MAX_EVENT_LENGTH];
                printf("Enter event: ");
                scanf("%s", event);
                log_event(&log, event);
                break;
            }
            case 2: {
                print_log(&log);
                break;
            }
            case 3: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while (choice!= 3);

    return 0;
}