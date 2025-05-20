//Falcon-180B DATASET v1.0 Category: System event logger ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_EVENTS 100
#define EVENT_LOG_FILE "event_log.txt"
#define EVENT_LOG_BUF_SIZE 1024

typedef struct {
    char* message;
    time_t timestamp;
} Event;

FILE* eventLogFile = NULL;
Event events[MAX_EVENTS];
int numEvents = 0;

void initEventLogger() {
    eventLogFile = fopen(EVENT_LOG_FILE, "a");
    if (eventLogFile == NULL) {
        fprintf(stderr, "Error: could not open event log file.\n");
        exit(1);
    }
}

void logEvent(const char* message) {
    if (numEvents >= MAX_EVENTS) {
        fprintf(stderr, "Error: event buffer is full.\n");
        return;
    }

    events[numEvents].message = strdup(message);
    events[numEvents].timestamp = time(NULL);
    numEvents++;

    char buf[EVENT_LOG_BUF_SIZE];
    snprintf(buf, EVENT_LOG_BUF_SIZE, "[%ld] %s\n", events[numEvents-1].timestamp, events[numEvents-1].message);
    fwrite(buf, strlen(buf), 1, eventLogFile);
}

void closeEventLogger() {
    fclose(eventLogFile);
}

int main() {
    initEventLogger();

    logEvent("Program started.");
    sleep(1);

    logEvent("Some event occurred.");
    sleep(2);

    logEvent("Another event occurred.");
    sleep(3);

    closeEventLogger();

    return 0;
}