//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct event {
  time_t timestamp;
  char *message;
  char *log_entry;
} event_t;

// Create a new event
event_t *event_new(char *message) {
  event_t *event = malloc(sizeof(event_t));
  event->timestamp = time(NULL);
  event->message = strdup(message);
  event->log_entry = NULL;
  return event;
}

// Free an event
void event_free(event_t *event) {
  if (event->message) free(event->message);
  if (event->log_entry) free(event->log_entry);
  free(event);
}

// Write an event to the log file
void event_log(FILE *log_file, event_t *event) {
  char *timestamp = ctime(&event->timestamp);
  timestamp[strlen(timestamp) - 1] = '\0'; // Remove the newline
  snprintf(event->log_entry, 256, "%s %s\n", timestamp, event->message);
  fputs(event->log_entry, log_file);
}

// Main function
int main(int argc, char **argv) {
  // Open the log file
  FILE *log_file = fopen("log.txt", "w");
  if (!log_file) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Create some events
  event_t *event1 = event_new("Event 1");
  event_t *event2 = event_new("Event 2");
  event_t *event3 = event_new("Event 3");

  // Log the events
  event_log(log_file, event1);
  event_log(log_file, event2);
  event_log(log_file, event3);

  // Free the events
  event_free(event1);
  event_free(event2);
  event_free(event3);

  // Close the log file
  fclose(log_file);

  return EXIT_SUCCESS;
}