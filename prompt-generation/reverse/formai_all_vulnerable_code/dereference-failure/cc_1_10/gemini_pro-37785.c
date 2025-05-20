//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum allowed input length
#define MAX_INPUT_LENGTH 1024

// Define the allowed characters for input
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

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
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the allowed characters from the input to the sanitized input
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (is_allowed_char(input[i])) {
      sanitized_input[j] = input[i];
      j++;
    }
  }

  // Terminate the sanitized input string
  sanitized_input[j] = '\0';

  // Return the sanitized input
  return sanitized_input;
}

// Main function
int main() {
  // Get the user input
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