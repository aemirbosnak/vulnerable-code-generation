//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the input to the sanitized input
  strcpy(sanitized_input, input);

  // Convert all characters to lowercase
  for (int i = 0; i < strlen(sanitized_input); i++) {
    sanitized_input[i] = tolower(sanitized_input[i]);
  }

  // Remove all non-alphanumeric characters
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (!isalnum(sanitized_input[i])) {
      sanitized_input[i] = '_';
    }
  }

  // Remove all leading and trailing underscores
  while (sanitized_input[0] == '_') {
    sanitized_input++;
  }
  while (sanitized_input[strlen(sanitized_input) - 1] == '_') {
    sanitized_input[strlen(sanitized_input) - 1] = '\0';
  }

  // Return the sanitized input
  return sanitized_input;
}

// Function to get user input
char *get_user_input(char *prompt) {
  // Allocate memory for the user input
  char *user_input = malloc(1024);

  // Get the user input
  printf("%s", prompt);
  fgets(user_input, 1024, stdin);

  // Remove the newline character from the end of the input
  user_input[strlen(user_input) - 1] = '\0';

  // Return the user input
  return user_input;
}

// Main function
int main() {
  // Get the user input
  char *user_input = get_user_input("Enter your input: ");

  // Sanitize the user input
  char *sanitized_input = sanitize_input(user_input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the user input and the sanitized input
  free(user_input);
  free(sanitized_input);

  return 0;
}