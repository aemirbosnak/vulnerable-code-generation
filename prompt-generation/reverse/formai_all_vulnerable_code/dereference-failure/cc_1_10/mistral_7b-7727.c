//MISTRAL-7B DATASET v1.0 Category: System event logger ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_EVENTS 50
#define SEVERITY_EMERGENCY 0
#define SEVERITY_ALERT 1
#define SEVERITY_CRITICAL 2
#define SEVERITY_ERROR 3
#define SEVERITY_WARNING 4
#define SEVERITY_NOTICE 5
#define SEVERITY_INFO 6
#define SEVERITY_DEBUG 7

typedef struct {
    int severity;
    char message[MAX_BUFFER_SIZE];
    time_t timestamp;
} Event;

Event buffer[MAX_EVENTS];
int head = 0;
int tail = 0;
int num_events = 0;

void log_event(int severity, char *message) {
    if (num_events >= MAX_EVENTS) {
        printf("Event buffer is full. Dropping event.\n");
        return;
    }

    strcpy(buffer[tail].message, message);
    buffer[tail].severity = severity;
    buffer[tail].timestamp = time(NULL);
    tail = (tail + 1) % MAX_EVENTS;
    num_events++;
}

void print_events() {
    if (num_events == 0) {
        printf("No events to display.\n");
        return;
    }

    printf("\nEvent log:\n");
    printf("----------------------------------------------------------------------------------------------------\n");

    for (int i = head; i < head + MAX_EVENTS && i < num_events; i++) {
        int index = i % MAX_EVENTS;
        printf("Severity: %d | Timestamp: %s | Message: %s\n", buffer[index].severity, ctime(&buffer[index].timestamp), buffer[index].message);
    }

    printf("----------------------------------------------------------------------------------------------------\n");
}

int main() {
    char *message;

    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        int severity = rand() % 8;
        message = malloc(MAX_BUFFER_SIZE * sizeof(char));
        sprintf(message, "Event %d: This is a test event with severity %d.\n", i, severity);
        log_event(severity, message);
        free(message);
    }

    printf("Logging completed. Displaying events:\n");
    print_events();

    return 0;
}