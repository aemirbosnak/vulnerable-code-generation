//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.?! ";

// Define the function to sanitize the input string
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized string
  char* sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Initialize the sanitized string to the empty string
  sanitized_input[0] = '\0';

  // Iterate over the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is allowed
    if (strchr(allowed_chars, input[i]) != NULL) {
      // If the character is allowed, append it to the sanitized string
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized string
  return sanitized_input;
}

// Define the main function
int main() {
  // Declare the input string
  char input[MAX_INPUT_LENGTH];

  // Prompt the user for input
  printf("Enter a string: ");

  // Read the input string from the user
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the input string
  char* sanitized_input = sanitize_input(input);

  // Print the sanitized string
  printf("Sanitized string: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized string
  free(sanitized_input);

  // Return 0 to indicate success
  return 0;
}