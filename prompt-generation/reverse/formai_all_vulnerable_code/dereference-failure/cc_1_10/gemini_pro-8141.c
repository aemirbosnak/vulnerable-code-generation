//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#define EVENT_SIZE 1024

typedef struct event_node {
  char message[EVENT_SIZE];
  time_t timestamp;
  struct event_node *next;
} event_node;

event_node *head = NULL;

void log_event(char *message) {
  event_node *new_event = malloc(sizeof(event_node));
  if (new_event == NULL) {
    perror("malloc");
    exit(1);
  }
  snprintf(new_event->message, EVENT_SIZE, "%s", message);
  new_event->timestamp = time(NULL);
  new_event->next = head;
  head = new_event;
}

void print_events(event_node *node) {
  if (node == NULL) {
    return;
  }
  syslog(LOG_INFO, "%s", node->message);
  print_events(node->next);
}

void print_events_recursively(event_node *node) {
  if (node == NULL) {
    return;
  }
  syslog(LOG_INFO, "%s", node->message);
  print_events_recursively(node->next);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("Usage: %s <message>\n", argv[0]);
    exit(1);
  }
  openlog("my_logger", LOG_PID, LOG_USER);
  log_event(argv[1]);
  print_events(head);
  print_events_recursively(head);
  closelog();
  return 0;
}