//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

typedef struct {
  int code;
  char *message;
} error_t;

error_t *error_create(int code, const char *message) {
  error_t *error = malloc(sizeof(error_t));
  if (!error) {
    return NULL;
  }

  error->code = code;
  error->message = strdup(message);
  if (!error->message) {
    free(error);
    return NULL;
  }

  return error;
}

void error_destroy(error_t *error) {
  if (!error) {
    return;
  }

  free(error->message);
  free(error);
}

int main(void) {
  // Create a distributed error handling system with multiple error handlers.

  // Create an array of error handlers.
  error_t *error_handlers[] = {
    error_create(1, "Error 1: Invalid input."),
    error_create(2, "Error 2: File not found."),
    error_create(3, "Error 3: Memory allocation failed."),
  };

  // Get the number of error handlers.
  int num_error_handlers = sizeof(error_handlers) / sizeof(error_t *);

  // Create a buffer to store the error message.
  char buffer[MAX_SIZE];

  // Generate an error.
  int error_code = 2;

  // Get the error handler for the error code.
  error_t *error_handler = NULL;
  for (int i = 0; i < num_error_handlers; i++) {
    if (error_handlers[i]->code == error_code) {
      error_handler = error_handlers[i];
      break;
    }
  }

  // If the error handler was not found, use the default error handler.
  if (!error_handler) {
    error_handler = error_create(0, "Unknown error.");
  }

  // Get the error message.
  snprintf(buffer, MAX_SIZE, "%s", error_handler->message);

  // Print the error message.
  printf("%s\n", buffer);

  // Destroy the error handler.
  error_destroy(error_handler);

  // Destroy the error handlers.
  for (int i = 0; i < num_error_handlers; i++) {
    error_destroy(error_handlers[i]);
  }

  return 0;
}