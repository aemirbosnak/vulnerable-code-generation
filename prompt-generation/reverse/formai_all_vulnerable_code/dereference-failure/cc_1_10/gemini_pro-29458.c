//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 100

// Define a function to sanitize the input string.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized string.
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Initialize the sanitized string to an empty string.
  strcpy(sanitized_input, "");

  // Iterate over the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is a valid character.
    if ((input[i] >= 'a' && input[i] <= 'z') ||
        (input[i] >= 'A' && input[i] <= 'Z') ||
        (input[i] >= '0' && input[i] <= '9') ||
        (input[i] == ' ')) {
      // If the current character is a valid character, append it to the sanitized string.
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized string.
  return sanitized_input;
}

// Define a function to get the input from the user.
char *get_input() {
  // Allocate memory for the input string.
  char *input = malloc(MAX_INPUT_LENGTH);

  // Get the input from the user.
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the input string.
  input[strcspn(input, "\n")] = 0;

  // Return the input string.
  return input;
}

// Define the main function.
int main() {
  // Get the input from the user.
  char *input = get_input();

  // Sanitize the input.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input.
  printf("The sanitized input is: %s\n", sanitized_input);

  // Free the memory allocated for the input and sanitized input strings.
  free(input);
  free(sanitized_input);

  // Return 0 to indicate success.
  return 0;
}