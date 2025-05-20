//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum allowed input length
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.";

// Function to check if a string contains only allowed characters
int is_valid_input(char *input) {
  int i;
  int len = strlen(input);

  // Iterate over each character in the input string
  for (i = 0; i < len; i++) {
    // Check if the character is not in the list of allowed characters
    if (strchr(allowed_characters, input[i]) == NULL) {
      return 0;
    }
  }

  // If all characters are allowed, return 1
  return 1;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
  int i;
  int len = strlen(input);
  char *sanitized_input = (char *)malloc(len + 1);

  // Iterate over each character in the input string
  for (i = 0; i < len; i++) {
    // Check if the character is not in the list of allowed characters
    if (strchr(allowed_characters, input[i]) == NULL) {
      // If the character is not allowed, replace it with an empty character
      sanitized_input[i] = '\0';
    } else {
      // If the character is allowed, copy it to the sanitized input string
      sanitized_input[i] = input[i];
    }
  }

  // Terminate the sanitized input string
  sanitized_input[len] = '\0';

  // Return the sanitized input string
  return sanitized_input;
}

int main() {
  char input[MAX_INPUT_LENGTH];

  // Prompt the user to enter a string
  printf("Enter a string: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Check if the user input is valid
  if (is_valid_input(input)) {
    // If the user input is valid, sanitize it
    char *sanitized_input = sanitize_input(input);

    // Print the sanitized input string
    printf("Sanitized input: %s", sanitized_input);

    // Free the memory allocated for the sanitized input string
    free(sanitized_input);
  } else {
    // If the user input is not valid, print an error message
    printf("Invalid input. Please enter only alphabetic characters, numbers, underscores, and periods.\n");
  }

  return 0;
}