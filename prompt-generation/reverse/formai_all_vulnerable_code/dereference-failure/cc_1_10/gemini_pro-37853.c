//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to hold our error codes and messages
typedef struct {
  int code;
  char *message;
} Error;

// A function to create a new error
Error *new_error(int code, char *message) {
  Error *error = malloc(sizeof(Error));
  error->code = code;
  error->message = strdup(message);
  return error;
}

// A function to free an error
void free_error(Error *error) {
  free(error->message);
  free(error);
}

// A function to print an error
void print_error(Error *error) {
  printf("Error: %d - %s\n", error->code, error->message);
}

// A function to handle an error
void handle_error(Error *error) {
  switch (error->code) {
    case 1:
      printf("Error: File not found.\n");
      break;
    case 2:
      printf("Error: Invalid input.\n");
      break;
    case 3:
      printf("Error: Memory allocation error.\n");
      break;
    default:
      printf("Error: Unknown error.\n");
      break;
  }
}

// A function to test our error handling
int main() {
  // Create an error
  Error *error = new_error(1, "File not found.");

  // Print the error
  print_error(error);

  // Handle the error
  handle_error(error);

  // Free the error
  free_error(error);

  return 0;
}