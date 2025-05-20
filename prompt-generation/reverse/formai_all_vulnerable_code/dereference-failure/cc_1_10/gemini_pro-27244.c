//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the input buffer size.
#define INPUT_BUFFER_SIZE 1024

// Function to sanitize user input.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input.
  char *sanitized_input = malloc(INPUT_BUFFER_SIZE);
  if (sanitized_input == NULL) {
    perror("malloc");
    return NULL;
  }

  // Initialize the sanitized input string.
  memset(sanitized_input, 0, INPUT_BUFFER_SIZE);

  // Loop through the input string and replace any non-alphanumeric characters
  // with spaces.
  for (int i = 0; input[i] != '\0'; i++) {
    if (!isalnum(input[i])) {
      sanitized_input[i] = ' ';
    } else {
      sanitized_input[i] = input[i];
    }
  }

  // Return the sanitized input string.
  return sanitized_input;
}

// Main function.
int main(int argc, char **argv) {
  // Check if the user has provided an input string.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input string>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the user input string.
  char *input = argv[1];

  // Sanitize the user input string.
  char *sanitized_input = sanitize_input(input);
  if (sanitized_input == NULL) {
    perror("sanitize_input");
    return EXIT_FAILURE;
  }

  // Print the sanitized input string.
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized input string.
  free(sanitized_input);

  return EXIT_SUCCESS;
}