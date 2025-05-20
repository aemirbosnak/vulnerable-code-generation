//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters.
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.,?!";

// Get a line of input from the user.
char *get_input() {
  // Allocate memory for the input string.
  char *input = malloc(MAX_INPUT_LENGTH);
  if (input == NULL) {
    fprintf(stderr, "Error allocating memory for input string.\n");
    exit(1);
  }

  // Read a line of input from the user.
  if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
    fprintf(stderr, "Error reading input string.\n");
    exit(1);
  }

  // Remove the newline character from the end of the input string.
  input[strlen(input) - 1] = '\0';

  // Return the input string.
  return input;
}

// Sanitize the input string.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized string.
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);
  if (sanitized_input == NULL) {
    fprintf(stderr, "Error allocating memory for sanitized string.\n");
    exit(1);
  }

  // Copy the input string to the sanitized string.
  strcpy(sanitized_input, input);

  // Replace all non-allowed characters with spaces.
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (strchr(allowed_chars, sanitized_input[i]) == NULL) {
      sanitized_input[i] = ' ';
    }
  }

  // Return the sanitized string.
  return sanitized_input;
}

// Print the sanitized input string.
void print_sanitized_input(char *sanitized_input) {
  // Print the sanitized input string.
  printf("%s\n", sanitized_input);
}

// Main function.
int main() {
  // Get a line of input from the user.
  char *input = get_input();

  // Sanitize the input string.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input string.
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input string.
  free(input);

  // Free the memory allocated for the sanitized string.
  free(sanitized_input);

  // Return 0 to indicate success.
  return 0;
}