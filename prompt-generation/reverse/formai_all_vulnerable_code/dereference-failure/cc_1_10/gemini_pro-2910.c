//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 1024

// Define the allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-";

// Function to sanitize the user input
char *sanitize_input(char *input) {
  // Check if the input is NULL
  if (input == NULL) {
    return NULL;
  }

  // Check if the input is empty
  if (strlen(input) == 0) {
    return NULL;
  }

  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Initialize the sanitized input
  strcpy(sanitized_input, "");

  // Iterate over the input
  for (int i = 0; i < strlen(input); i++) {
    // Check if the character is allowed
    if (strchr(allowed_chars, input[i]) != NULL) {
      // Append the character to the sanitized input
      strcat(sanitized_input, input[i]);
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

// Main function
int main() {
  // Get the user input
  char *input = malloc(MAX_INPUT_LENGTH + 1);
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the input and the sanitized input
  free(input);
  free(sanitized_input);

  return 0;
}