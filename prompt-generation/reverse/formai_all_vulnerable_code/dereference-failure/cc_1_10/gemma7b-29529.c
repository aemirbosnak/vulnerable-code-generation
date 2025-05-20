//Gemma-7B DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog
{
  char *events;
  int size;
  int capacity;
} EventLog;

EventLog *createEventLog()
{
  EventLog *log = malloc(sizeof(EventLog));
  log->events = malloc(MAX_LOG_SIZE);
  log->size = 0;
  log->capacity = MAX_LOG_SIZE;
  return log;
}

void addEvent(EventLog *log, char *event)
{
  if (log->size >= log->capacity)
  {
    printf("Log full!\n");
    return;
  }

  log->events[log->size++] = event;
}

void printEvents(EventLog *log)
{
  for (int i = 0; i < log->size; i++)
  {
    printf("%s\n", log->events[i]);
  }
}

int main()
{
  EventLog *log = createEventLog();

  addEvent(log, "The cat jumped onto the mat.");
  addEvent(log, "The dog barked at the mailman.");
  addEvent(log, "The house shook with thunder.");

  printEvents(log);

  free(log->events);
  free(log);

  return 0;
}