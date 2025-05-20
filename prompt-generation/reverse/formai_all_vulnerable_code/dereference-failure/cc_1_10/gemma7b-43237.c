//Gemma-7B DATASET v1.0 Category: System event logger ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1024

typedef struct EventLog {
  char **events;
  int size;
  int capacity;
} EventLog;

void logEvent(EventLog *log, char *event)
{
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char timestamp[26] = "";
  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", tm);

  if (log->size >= log->capacity)
  {
    log->events = realloc(log->events, log->capacity * 2);
    log->capacity *= 2;
  }

  log->events[log->size++] = strdup(event);
  log->events[log->size - 1] = timestamp;
}

int main()
{
  EventLog *log = malloc(sizeof(EventLog));
  log->events = malloc(MAX_EVENTS * sizeof(char *));
  log->size = 0;
  log->capacity = MAX_EVENTS;

  logEvent(log, "John Doe has logged in.");
  logEvent(log, "Jane Doe has purchased a new product.");
  logEvent(log, "The system has experienced an error.");

  for (int i = 0; i < log->size; i++)
  {
    printf("%s - %s\n", log->events[i], log->events[i + 1]);
  }

  free(log->events);
  free(log);

  return 0;
}