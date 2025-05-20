//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the allowed characters in the input string
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890,.!@#$%^&*()_+-=<>?/"

// Define the error message to be printed if the input string contains invalid characters
#define INVALID_CHARACTERS_ERROR "Error: The input string contains invalid characters.\n"

// Define the success message to be printed if the input string is valid
#define VALID_INPUT_MESSAGE "Success: The input string is valid.\n"

// Define the function to sanitize the input string
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input string
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the input string to the sanitized input string
  strcpy(sanitized_input, input);

  // Iterate over the characters in the sanitized input string
  for (int i = 0; sanitized_input[i] != '\0'; i++) {
    // Check if the character is not allowed
    if (strchr(ALLOWED_CHARACTERS, sanitized_input[i]) == NULL) {
      // Replace the invalid character with a space
      sanitized_input[i] = ' ';
    }
  }

  // Return the sanitized input string
  return sanitized_input;
}

// Define the main function
int main() {
  // Get the input string from the user
  char input[MAX_INPUT_LENGTH];
  printf("Enter the input string: ");
  scanf("%s", input);

  // Sanitize the input string
  char *sanitized_input = sanitize_input(input);

  // Check if the input string is valid
  if (strcmp(sanitized_input, input) == 0) {
    // Print the success message
    printf(VALID_INPUT_MESSAGE);
  } else {
    // Print the error message
    printf(INVALID_CHARACTERS_ERROR);
  }

  // Free the memory allocated for the sanitized input string
  free(sanitized_input);

  return 0;
}