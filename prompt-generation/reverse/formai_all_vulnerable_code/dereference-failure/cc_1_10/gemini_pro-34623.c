//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Declare the sanitizer function
char *sanitize_input(char *input);

int main() {
  // Get the input from the user
  char input[MAX_BUFFER_SIZE];
  printf("Enter your input: ");
  fgets(input, MAX_BUFFER_SIZE, stdin);

  // Sanitize the input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}

// Define the sanitizer function
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Initialize the index of the sanitized input
  int i = 0;

  // Iterate over the input string
  while (input[i] != '\0') {
    // Check if the current character is a valid character
    if (isalnum(input[i]) || isspace(input[i])) {
      // If the character is valid, add it to the sanitized input
      sanitized_input[i] = input[i];
    } else {
      // If the character is not valid, replace it with a space
      sanitized_input[i] = ' ';
    }

    // Increment the index of the sanitized input
    i++;
  }

  // Terminate the sanitized input string
  sanitized_input[i] = '\0';

  // Return the sanitized input
  return sanitized_input;
}