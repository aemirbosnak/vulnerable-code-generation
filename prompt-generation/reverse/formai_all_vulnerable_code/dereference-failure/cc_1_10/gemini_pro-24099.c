//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

// Function to check if a character is allowed
int is_allowed_char(char c) {
  for (int i = 0; i < strlen(allowed_chars); i++) {
    if (c == allowed_chars[i]) {
      return 1;
    }
  }
  return 0;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Initialize the index of the sanitized input
  int sanitized_index = 0;

  // Iterate over the user input
  for (int i = 0; i < strlen(input); i++) {
    // Check if the character is allowed
    if (is_allowed_char(input[i])) {
      // Add the character to the sanitized input
      sanitized_input[sanitized_index++] = input[i];
    }
  }

  // Terminate the sanitized input
  sanitized_input[sanitized_index] = '\0';

  // Return the sanitized input
  return sanitized_input;
}

int main() {
  // Get user input
  char input[MAX_INPUT_LENGTH];
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}