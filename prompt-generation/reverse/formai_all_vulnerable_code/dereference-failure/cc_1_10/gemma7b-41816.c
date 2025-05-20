//Gemma-7B DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENT_SIZE 1024
#define EVENT_LOG_FILE "event.log"

typedef struct EventLogEvent {
  char timestamp[64];
  char event_name[MAX_EVENT_SIZE];
  char event_data[MAX_EVENT_SIZE];
  struct EventLogEvent* next;
} EventLogEvent;

EventLogEvent* event_log_add_event(EventLogEvent* head, char* event_name, char* event_data) {
  EventLogEvent* new_event = malloc(sizeof(EventLogEvent));
  time_t t = time(NULL);
  strftime(new_event->timestamp, sizeof(new_event->timestamp), "%Y-%m-%d %H:%M:%S", localtime(&t));
  strncpy(new_event->event_name, event_name, MAX_EVENT_SIZE - 1);
  strncpy(new_event->event_data, event_data, MAX_EVENT_SIZE - 1);
  new_event->next = NULL;

  if (head == NULL) {
    return new_event;
  } else {
    head->next = new_event;
    return head;
  }
}

void event_log_print_events(EventLogEvent* head) {
  EventLogEvent* current_event = head;
  while (current_event) {
    printf("Timestamp: %s\n", current_event->timestamp);
    printf("Event Name: %s\n", current_event->event_name);
    printf("Event Data: %s\n", current_event->event_data);
    printf("\n");
    current_event = current_event->next;
  }
}

int main() {
  EventLogEvent* event_log = NULL;
  event_log_add_event(event_log, "System Startup", "System started successfully");
  event_log_add_event(event_log, "User Login", "User John Doe logged in");
  event_log_add_event(event_log, "File Download", "User downloaded file abc.txt");
  event_log_print_events(event_log);

  return 0;
}