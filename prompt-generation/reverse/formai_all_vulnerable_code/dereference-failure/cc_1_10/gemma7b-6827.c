//Gemma-7B DATASET v1.0 Category: System event logger ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
  char **logs;
  int size;
  int head;
  int tail;
} EventLog;

EventLog *eventLog_init(int size) {
  EventLog *log = malloc(sizeof(EventLog));
  log->logs = malloc(size * sizeof(char *));
  log->size = size;
  log->head = 0;
  log->tail = -1;

  return log;
}

void eventLog_add(EventLog *log, char *event) {
  log->logs[++log->tail] = event;

  if (log->tail == log->size - 1) {
    log->tail = -1;
  }

  if (log->head == log->tail) {
    log->head = 0;
  }
}

void eventLog_print(EventLog *log) {
  for (int i = log->head; i != log->tail; i++) {
    printf("%s\n", log->logs[i]);
  }
}

int main() {
  EventLog *log = eventLog_init(MAX_LOG_SIZE);

  eventLog_add(log, "Hello, world!");
  eventLog_add(log, "This is an event.");
  eventLog_add(log, "Another event.");

  eventLog_print(log);

  return 0;
}