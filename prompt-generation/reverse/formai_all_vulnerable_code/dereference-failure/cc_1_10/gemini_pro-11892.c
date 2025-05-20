//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of input allowed
#define MAX_INPUT_LENGTH 1024

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Copy the input to the sanitized input
  strcpy(sanitized_input, input);

  // Remove any leading or trailing whitespace
  while (*sanitized_input == ' ') {
    sanitized_input++;
  }
  while (sanitized_input[strlen(sanitized_input) - 1] == ' ') {
    sanitized_input[strlen(sanitized_input) - 1] = '\0';
  }

  // Replace any special characters with underscores
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (!isalnum(sanitized_input[i])) {
      sanitized_input[i] = '_';
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

// Main function
int main() {
  // Get user input
  char input[MAX_INPUT_LENGTH];
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}