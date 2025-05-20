//Gemma-7B DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOG_SIZE 1024

typedef struct EventLog {
  char *events;
  int size;
  int head;
  int tail;
} EventLog;

void event_log_init(EventLog *log) {
  log->events = malloc(LOG_SIZE);
  log->size = LOG_SIZE;
  log->head = 0;
  log->tail = -1;
}

void event_log_add(EventLog *log, char *event) {
  log->tail++;
  if (log->tail == log->size - 1) {
    log->tail = 0;
  }
  log->events[log->tail] = event;
}

void event_log_print(EventLog *log) {
  int i = log->head;
  while (i != log->tail) {
    printf("%s\n", log->events[i]);
    i++;
    if (i == log->size - 1) {
      i = 0;
    }
  }
}

int main() {
  EventLog log;
  event_log_init(&log);

  event_log_add(&log, "Hello, world!");
  event_log_add(&log, "This is a event.");
  event_log_add(&log, "Goodbye, cruel world!");

  event_log_print(&log);

  return 0;
}