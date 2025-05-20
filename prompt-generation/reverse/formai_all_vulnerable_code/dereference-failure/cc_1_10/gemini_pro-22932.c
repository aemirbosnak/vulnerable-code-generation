//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <syslog.h>

#define MAX_SIZE 1024

typedef struct event {
  char *message;
  int priority;
} event_t;

event_t *event_new(const char *message, int priority) {
  event_t *event = malloc(sizeof(event_t));
  if (event == NULL) {
    return NULL;
  }

  event->message = strdup(message);
  if (event->message == NULL) {
    free(event);
    return NULL;
  }

  event->priority = priority;
  return event;
}

void event_free(event_t *event) {
  if (event == NULL) {
    return;
  }

  free(event->message);
  free(event);
}

void event_log(event_t *event) {
  if (event == NULL) {
    return;
  }

  openlog("event_logger", LOG_PID | LOG_CONS, LOG_LOCAL0);
  syslog(event->priority, "%s", event->message);
  closelog();
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <message> <priority>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *message = argv[1];
  int priority = atoi(argv[2]);

  event_t *event = event_new(message, priority);
  if (event == NULL) {
    fprintf(stderr, "Error creating event\n");
    return EXIT_FAILURE;
  }

  event_log(event);
  event_free(event);

  return EXIT_SUCCESS;
}