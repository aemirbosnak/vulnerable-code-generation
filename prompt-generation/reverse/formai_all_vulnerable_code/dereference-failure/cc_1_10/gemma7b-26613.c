//Gemma-7B DATASET v1.0 Category: System event logger ; Style: enthusiastic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
  char timestamp[26];
  char event_name[256];
  char event_details[MAX_LOG_SIZE];
  struct EventLog* next;
} EventLog;

void log_event(char* event_name, char* event_details) {
  time_t t = time(NULL);
  struct tm* tm = localtime(&t);
  EventLog* new_event = malloc(sizeof(EventLog));
  new_event->timestamp[0] = tm->tm_hour;
  new_event->timestamp[1] = tm->tm_min;
  new_event->timestamp[2] = tm->tm_sec;
  snprintf(new_event->event_name, 256, "%s", event_name);
  snprintf(new_event->event_details, MAX_LOG_SIZE, "%s", event_details);
  new_event->next = NULL;

  EventLog* head = NULL;
  if (head == NULL) {
    head = new_event;
  } else {
    EventLog* tail = head;
    while (tail->next != NULL) {
      tail = tail->next;
    }
    tail->next = new_event;
  }

  free(new_event);
}

int main() {
  log_event("System Boot", "The system has booted successfully.");
  log_event("User Login", "User 'John Doe' has logged in.");
  log_event("Application Start", "Application 'My App' has started.");

  EventLog* head = NULL;
  EventLog* current = head;
  while (current) {
    printf("Timestamp: %s\n", current->timestamp);
    printf("Event Name: %s\n", current->event_name);
    printf("Event Details: %s\n", current->event_details);
    printf("\n");
    current = current->next;
  }

  return 0;
}