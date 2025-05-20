//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length.
#define MAX_INPUT_LENGTH 100

// Define the allowed characters.
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_";

// Define the error message.
char error_message[] = "Invalid input. Please enter only alphanumeric characters, dashes, underscores, or periods.\n";

// Function to sanitize user input.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input.
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the sanitized input into the allocated memory.
  strcpy(sanitized_input, "");

  // Iterate over the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is allowed.
    if (strchr(allowed_chars, input[i]) != NULL) {
      // If the current character is allowed, add it to the sanitized input.
      strcat(sanitized_input, &input[i]);
    }
  }

  // Return the sanitized input.
  return sanitized_input;
}

// Main function.
int main() {
  // Prompt the user for input.
  printf("Please enter your input: ");

  // Get the user input.
  char input[MAX_INPUT_LENGTH];
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the user input.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input.
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized input.
  free(sanitized_input);

  return 0;
}