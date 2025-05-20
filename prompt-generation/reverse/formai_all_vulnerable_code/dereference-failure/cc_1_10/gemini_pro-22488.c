//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

// Function to sanitize the input string
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized string
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the first character of the input string to the sanitized string
  sanitized_input[0] = input[0];

  // Iterate over the remaining characters in the input string
  for (int i = 1; i < strlen(input); i++) {
    // Check if the character is allowed
    if (strchr(allowed_chars, input[i]) != NULL) {
      // If the character is allowed, copy it to the sanitized string
      sanitized_input[i] = input[i];
    } else {
      // If the character is not allowed, replace it with an underscore
      sanitized_input[i] = '_';
    }
  }

  // Add the null terminator to the end of the sanitized string
  sanitized_input[strlen(input)] = '\0';

  // Return the sanitized string
  return sanitized_input;
}

// Main function
int main() {
  // Get the input string from the user
  char input[MAX_INPUT_LENGTH];
  printf("Enter the input string: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the input string
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized string
  printf("The sanitized string is: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized string
  free(sanitized_input);

  return 0;
}