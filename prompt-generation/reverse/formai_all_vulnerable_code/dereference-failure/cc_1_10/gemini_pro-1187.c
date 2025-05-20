//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Define the list of allowed characters
const char *allowed_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

// Get a line of input from the user
char *get_input() {
  // Allocate memory for the input buffer
  char *input = malloc(MAX_BUFFER_SIZE);

  // Read a line of input from the user
  fgets(input, MAX_BUFFER_SIZE, stdin);

  // Remove the newline character from the end of the input
  input[strlen(input) - 1] = '\0';

  // Return the input
  return input;
}

// Sanitize the input string
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the allowed characters from the input to the sanitized input
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (strchr(allowed_chars, input[i])) {
      sanitized_input[j++] = input[i];
    }
  }

  // Add the null terminator to the sanitized input
  sanitized_input[j] = '\0';

  // Return the sanitized input
  return sanitized_input;
}

// Print the sanitized input
void print_sanitized_input(char *sanitized_input) {
  // Print the sanitized input to the screen
  printf("Sanitized input: %s", sanitized_input);
}

// Free the memory allocated for the input and sanitized input
void free_input(char *input, char *sanitized_input) {
  // Free the memory allocated for the input
  free(input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);
}

// Main function
int main() {
  // Get a line of input from the user
  char *input = get_input();

  // Sanitize the input string
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input and sanitized input
  free_input(input, sanitized_input);

  return 0;
}