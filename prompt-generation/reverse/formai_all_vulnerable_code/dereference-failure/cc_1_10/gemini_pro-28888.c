//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size
#define MAX_INPUT_SIZE 1024

// Create a function to sanitize user input
char *sanitize_input(char *input, int size) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(size);

  // Initialize the sanitized input to an empty string
  memset(sanitized_input, 0, size);

  // Loop through the input and remove any invalid characters
  int i = 0;
  while (input[i] != '\0') {
    if (input[i] >= 'a' && input[i] <= 'z') {
      sanitized_input[i] = input[i];
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      sanitized_input[i] = input[i];
    } else if (input[i] >= '0' && input[i] <= '9') {
      sanitized_input[i] = input[i];
    } else if (input[i] == ' ') {
      sanitized_input[i] = input[i];
    } else {
      // Ignore the invalid character
    }
    i++;
  }

  // Return the sanitized input
  return sanitized_input;
}

// Create a function to get user input
char *get_user_input(char *prompt) {
  // Allocate memory for the user input
  char *input = malloc(MAX_INPUT_SIZE);

  // Initialize the user input to an empty string
  memset(input, 0, MAX_INPUT_SIZE);

  // Prompt the user for input
  printf("%s", prompt);

  // Get the user input
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Remove the newline character from the user input
  input[strlen(input) - 1] = '\0';

  // Return the user input
  return input;
}

// Create a function to validate user input
int validate_user_input(char *input, char *expected) {
  // Check if the user input matches the expected input
  if (strcmp(input, expected) == 0) {
    return 1;
  } else {
    return 0;
  }
}

// Create a function to display an error message
void display_error_message(char *message) {
  // Print the error message
  printf("%s\n", message);
}

// Create a function to run the program
int main() {
  // Get the user input
  char *input = get_user_input("Enter your name: ");

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input, strlen(input) + 1);

  // Validate the user input
  int valid = validate_user_input(sanitized_input, "John Doe");

  // Display an error message if the user input is invalid
  if (!valid) {
    display_error_message("Invalid input");
    return 1;
  }

  // Print the sanitized user input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the user input and sanitized input
  free(input);
  free(sanitized_input);

  // Return 0 to indicate success
  return 0;
}