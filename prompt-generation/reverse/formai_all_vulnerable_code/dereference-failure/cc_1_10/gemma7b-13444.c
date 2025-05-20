//Gemma-7B DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENT_SIZE 256

typedef struct EventLog {
  char *events;
  int capacity;
  int head;
  int tail;
} EventLog;

EventLog *createEventLog(int capacity) {
  EventLog *log = (EventLog *)malloc(sizeof(EventLog));
  log->events = (char *)malloc(capacity * MAX_EVENT_SIZE);
  log->capacity = capacity;
  log->head = 0;
  log->tail = 0;

  return log;
}

void logEvent(EventLog *log, char *event) {
  int eventSize = strlen(event) + 1;

  if (eventSize > MAX_EVENT_SIZE) {
    return;
  }

  log->events[log->tail] = event;
  log->tail = (log->tail + 1) % log->capacity;

  if (log->head == log->tail) {
    log->head = 0;
  }
}

int main() {
  EventLog *log = createEventLog(10);

  logEvent(log, "Hello, world!");
  logEvent(log, "This is an event.");
  logEvent(log, "The quick brown fox jumps over the lazy dog.");

  for (int i = 0; i < log->tail; i++) {
    printf("%s\n", log->events[i]);
  }

  return 0;
}