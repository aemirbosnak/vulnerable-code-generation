//Gemma-7B DATASET v1.0 Category: System event logger ; Style: shocked
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_SIZE 1024

typedef struct EventLog {
  char *timestamp;
  char *event_name;
  char *event_details;
  struct EventLog *next;
} EventLog;

EventLog *event_log_head = NULL;

void log_event(char *event_name, char *event_details) {
  EventLog *new_event = malloc(sizeof(EventLog));

  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  new_event->timestamp = malloc(MAX_LOG_SIZE);
  strftime(new_event->timestamp, MAX_LOG_SIZE, "%Y-%m-%d %H:%M:%S", tm);

  new_event->event_name = malloc(MAX_LOG_SIZE);
  strcpy(new_event->event_name, event_name);

  new_event->event_details = malloc(MAX_LOG_SIZE);
  strcpy(new_event->event_details, event_details);

  new_event->next = NULL;

  if (event_log_head == NULL) {
    event_log_head = new_event;
  } else {
    event_log_head->next = new_event;
  }
}

int main() {
  log_event("System Crash", "The system crashed due to a memory overflow.");
  log_event("User Error", "A user entered an invalid command.");
  log_event("Network Failure", "The network connection failed.");

  EventLog *current_event = event_log_head;
  while (current_event) {
    printf("Timestamp: %s\n", current_event->timestamp);
    printf("Event Name: %s\n", current_event->event_name);
    printf("Event Details: %s\n", current_event->event_details);
    printf("\n");
    current_event = current_event->next;
  }

  return 0;
}