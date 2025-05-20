//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Global variables
int num_logs = 0;
char *log_messages[100];

// Function to log a message
void log_message(const char *message) {
  // Increment the number of logs
  num_logs++;

  // If the log array is full, overwrite the oldest message
  if (num_logs >= 100) {
    int i = 0;
    for (i = 0; i < 100; i++) {
      if (log_messages[i] != NULL) {
        free(log_messages[i]);
      }
    }
    num_logs = 0;
  }

  // Allocate memory for the new message
  char *new_message = malloc(strlen(message) + 1);
  strcpy(new_message, message);

  // Add the message to the log array
  log_messages[num_logs] = new_message;
}

// Function to print the log messages
void print_logs() {
  int i;

  // Print the log messages in reverse order
  for (i = num_logs - 1; i >= 0; i--) {
    printf("%s\n", log_messages[i]);
  }
}

int main() {
  // Log some messages
  log_message("Hello, world!");
  log_message("This is a test log message.");
  log_message("I am a happy programmer.");

  // Print the logs
  print_logs();

  return 0;
}