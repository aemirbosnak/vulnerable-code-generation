//Gemma-7B DATASET v1.0 Category: System event logger ; Style: mathematical
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
  char timestamp[64];
  char event_name[64];
  char event_details[MAX_LOG_SIZE];
  struct EventLog* next;
} EventLog;

EventLog* head = NULL;

void log_event(char* name, char* details)
{
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);

  EventLog* new_log = (EventLog*)malloc(sizeof(EventLog));

  strcpy(new_log->timestamp, asctime(tm));
  strcpy(new_log->event_name, name);
  strcpy(new_log->event_details, details);

  new_log->next = head;
  head = new_log;
}

int main()
{
  log_event("Math Function", "Logarithm function working perfectly.");
  log_event("Algebraic Equation", "Quadratic equation solver has bugs.");
  log_event("Calculus Problem", "Integration and differentiation formulas are implemented.");

  EventLog* current_log = head;

  while(current_log)
  {
    printf("Timestamp: %s\n", current_log->timestamp);
    printf("Event Name: %s\n", current_log->event_name);
    printf("Event Details: %s\n", current_log->event_details);
    printf("\n");

    current_log = current_log->next;
  }

  return 0;
}