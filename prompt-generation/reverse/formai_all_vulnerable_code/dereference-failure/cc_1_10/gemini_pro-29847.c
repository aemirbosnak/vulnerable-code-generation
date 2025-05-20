//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1024

// Declare the sanitize_input function
char* sanitize_input(char* input);

int main() {
  // Declare a variable to store the user's input
  char input[MAX_INPUT_LENGTH];

  // Prompt the user for input
  printf("Enter some input: ");

  // Read the user's input
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the user's input
  char* sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}

// Define the sanitize_input function
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized input
  char* sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Initialize the sanitized input to an empty string
  sanitized_input[0] = '\0';

  // Iterate over the characters in the input string
  for (int i = 0; i < strlen(input); i++) {
    // Check if the character is an ASCII letter or digit
    if (isalnum(input[i])) {
      // Append the character to the sanitized input
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized input
  return sanitized_input;
}