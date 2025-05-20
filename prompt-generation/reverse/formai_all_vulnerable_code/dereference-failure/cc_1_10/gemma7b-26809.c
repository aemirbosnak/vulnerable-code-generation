//Gemma-7B DATASET v1.0 Category: System event logger ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EVENTS 1024

struct EventLog {
  char timestamp[26];
  char event_name[256];
  char event_details[1024];
  int event_id;
  struct EventLog* next;
};

struct EventLog* head = NULL;

void log_event(char* event_name, char* event_details) {
  struct EventLog* new_event = malloc(sizeof(struct EventLog));

  time_t t = time(NULL);
  strftime(new_event->timestamp, 26, "%H:%M:%S", localtime(&t));

  strcpy(new_event->event_name, event_name);
  strcpy(new_event->event_details, event_details);

  new_event->event_id = head ? head->event_id + 1 : 0;

  if (head) {
    head->next = new_event;
  } else {
    head = new_event;
  }

  if (head->event_id >= MAX_EVENTS) {
    printf("Event log full!\n");
  }
}

int main() {
  log_event("System boot", "System started successfully.");
  log_event("User login", "John Doe logged in.");
  log_event("File download", "User downloaded file 'my_file.pdf'.");

  struct EventLog* current_event = head;
  while (current_event) {
    printf("Event ID: %d\n", current_event->event_id);
    printf("Timestamp: %s\n", current_event->timestamp);
    printf("Event Name: %s\n", current_event->event_name);
    printf("Event Details: %s\n", current_event->event_details);
    printf("\n");
    current_event = current_event->next;
  }

  return 0;
}