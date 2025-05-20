//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

void log_event(char* event_type, char* message);

int main() {

  srand(time(NULL));

  char buffer[MAX_BUFFER_SIZE];

  int num_events = rand() % 50 + 1;  // Random number of events between 1 and 50

  printf("Generating %d system events...\n", num_events);

  for (int i = 0; i < num_events; i++) {

    // Randomly choose event type
    int event_type_num = rand() % 3;
    char* event_type;
    if (event_type_num == 0) {
      event_type = "INFO";
    } else if (event_type_num == 1) {
      event_type = "WARNING";
    } else {
      event_type = "ERROR";
    }

    // Generate random message
    sprintf(buffer, "This is a %s message for event #%d", event_type, i+1);
    char* message = buffer;

    // Log event
    log_event(event_type, message);
  }

  printf("Done generating system events.\n");

  return 0;
}

void log_event(char* event_type, char* message) {
  time_t current_time;
  char* c_time_string;
  current_time = time(NULL);
  c_time_string = ctime(&current_time);
  c_time_string[strlen(c_time_string)-1] = '\0'; // Remove newline character from end of time string
  printf("[%s] %s: %s\n", c_time_string, event_type, message);
}