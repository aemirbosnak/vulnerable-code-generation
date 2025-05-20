//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters.
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Get a line of input from the user.
char *get_input(void) {
  // Allocate memory for the input string.
  char *input = malloc(MAX_INPUT_LENGTH);
  if (input == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for input string.\n");
    exit(1);
  }

  // Get a line of input from the user.
  printf("Enter a line of input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the input string.
  input[strcspn(input, "\n")] = '\0';

  // Return the input string.
  return input;
}

// Sanitize the input string.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized string.
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);
  if (sanitized_input == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for sanitized string.\n");
    exit(1);
  }

  // Sanitize the input string.
  int i = 0;
  int j = 0;
  while (input[i] != '\0') {
    if (strchr(allowed_chars, input[i]) != NULL) {
      sanitized_input[j++] = input[i];
    }
    i++;
  }
  sanitized_input[j] = '\0';

  // Return the sanitized string.
  return sanitized_input;
}

// Print the sanitized input string.
void print_sanitized_input(char *sanitized_input) {
  // Print the sanitized input string.
  printf("Sanitized input: %s\n", sanitized_input);
}

// Main function.
int main(void) {
  // Get a line of input from the user.
  char *input = get_input();

  // Sanitize the input string.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input string.
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input and sanitized strings.
  free(input);
  free(sanitized_input);

  return 0;
}