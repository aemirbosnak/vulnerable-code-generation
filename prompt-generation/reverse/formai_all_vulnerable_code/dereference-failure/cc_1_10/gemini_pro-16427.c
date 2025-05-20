//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Define the maximum allowed input length.
#define MAX_INPUT_LENGTH 1024

// Define the allowed input characters.
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_-"

// Function to sanitize user input.
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized input.
  char* sanitized_input = malloc(strlen(input) + 1);

  // Loop through each character in the input.
  int i;
  for (i = 0; i < strlen(input); i++) {
    // Check if the character is allowed.
    if (strchr(ALLOWED_CHARACTERS, input[i]) != NULL) {
      // If the character is allowed, copy it to the sanitized input.
      sanitized_input[i] = input[i];
    } else {
      // If the character is not allowed, replace it with a space.
      sanitized_input[i] = ' ';
    }
  }

  // Null-terminate the sanitized input.
  sanitized_input[strlen(input)] = '\0';

  // Return the sanitized input.
  return sanitized_input;
}

// Main function.
int main() {
  // Prompt the user for input.
  printf("Enter your input: ");

  // Read the user input.
  char input[MAX_INPUT_LENGTH];
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the user input.
  char* sanitized_input = sanitize_input(input);

  // Print the sanitized input.
  printf("Sanitized input: %s", sanitized_input);

  // Free the memory allocated for the sanitized input.
  free(sanitized_input);

  return 0;
}