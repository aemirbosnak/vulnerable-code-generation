//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the user input
#define MAX_INPUT_LENGTH 1024

// Define the characters that are allowed in the user input
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-_ "

// Define the error message that is displayed when the user input is invalid
#define ERROR_MESSAGE "Invalid input. Please try again."

// Get the user input
char *get_user_input() {
  // Allocate memory for the user input
  char *input = malloc(MAX_INPUT_LENGTH);

  // If the memory allocation failed, display an error message and exit the program
  if (input == NULL) {
    printf("Error: Could not allocate memory for the user input.");
    exit(1);
  }

  // Get the user input
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the user input
  input[strcspn(input, "\n")] = '\0';

  // Return the user input
  return input;
}

// Sanitize the user input
char *sanitize_user_input(char *input) {
  // Allocate memory for the sanitized user input
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // If the memory allocation failed, display an error message and exit the program
  if (sanitized_input == NULL) {
    printf("Error: Could not allocate memory for the sanitized user input.");
    exit(1);
  }

  // Initialize the sanitized user input
  sanitized_input[0] = '\0';

  // Iterate over the characters in the user input
  for (int i = 0; i < strlen(input); i++) {
    // If the character is allowed, append it to the sanitized user input
    if (strchr(ALLOWED_CHARACTERS, input[i]) != NULL) {
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized user input
  return sanitized_input;
}

// Validate the user input
int validate_user_input(char *input) {
  // Check if the user input is empty
  if (strlen(input) == 0) {
    printf(ERROR_MESSAGE);
    return 0;
  }

  // Check if the user input contains any invalid characters
  for (int i = 0; i < strlen(input); i++) {
    if (strchr(ALLOWED_CHARACTERS, input[i]) == NULL) {
      printf(ERROR_MESSAGE);
      return 0;
    }
  }

  // The user input is valid
  return 1;
}

// Main function
int main() {
  // Get the user input
  char *input = get_user_input();

  // Sanitize the user input
  char *sanitized_input = sanitize_user_input(input);

  // Validate the user input
  int valid = validate_user_input(sanitized_input);

  // If the user input is valid, print it
  if (valid) {
    printf("Sanitized input: %s\n", sanitized_input);
  }

  // Free the memory allocated for the user input and the sanitized user input
  free(input);
  free(sanitized_input);

  return 0;
}