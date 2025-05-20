//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of an event message
#define MAX_EVENT_SIZE 1024

// Define the types of events that can be logged
typedef enum {
  EVENT_INFO,
  EVENT_WARNING,
  EVENT_ERROR,
  EVENT_FATAL
} event_type;

// Define the struct for an event
typedef struct {
  time_t timestamp;
  event_type type;
  char message[MAX_EVENT_SIZE];
} event;

// Define the function to log an event
void log_event(event *event) {
  // Open the log file
  FILE *log_file = fopen("log.txt", "a");
  if (log_file == NULL) {
    perror("Error opening log file");
    exit(1);
  }

  // Write the event to the log file
  fprintf(log_file, "%ld,%d,%s\n", event->timestamp, event->type, event->message);

  // Close the log file
  fclose(log_file);
}

// Define the function to create an event
event *create_event(event_type type, char *message) {
  // Allocate memory for the event
  event *event = malloc(sizeof(event));
  if (event == NULL) {
    perror("Error allocating memory for event");
    exit(1);
  }

  // Initialize the event
  event->timestamp = time(NULL);
  event->type = type;
  strcpy(event->message, message);

  // Return the event
  return event;
}

// Define the main function
int main() {
  // Create an event
  event *event = create_event(EVENT_INFO, "This is an informational message");

  // Log the event
  log_event(event);

  // Free the memory allocated for the event
  free(event);

  // Return 0 to indicate success
  return 0;
}