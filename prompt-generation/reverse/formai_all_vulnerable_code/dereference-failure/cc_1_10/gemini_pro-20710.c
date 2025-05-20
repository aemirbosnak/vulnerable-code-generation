//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

// Define a function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Copy the input to the sanitized input
  strcpy(sanitized_input, input);

  // Replace all instances of the following characters with spaces:
  // - '<'
  // - '>'
  // - '&'
  // - '"'
  // - '\''
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (sanitized_input[i] == '<' || sanitized_input[i] == '>' || sanitized_input[i] == '&' || sanitized_input[i] == '"' || sanitized_input[i] == '\'') {
      sanitized_input[i] = ' ';
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

// Define a function to get user input
char *get_user_input(char *prompt) {
  // Allocate memory for the user input
  char *input = malloc(MAX_INPUT_LENGTH);

  // Get the user input
  printf("%s", prompt);
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the input
  input[strlen(input) - 1] = '\0';

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Return the sanitized user input
  return sanitized_input;
}

// Define a function to main function
int main() {
  // Get the user input
  char *input = get_user_input("Enter your input: ");

  // Print the sanitized user input
  printf("Sanitized input: %s\n", input);

  // Free the allocated memory
  free(input);

  return 0;
}