//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input buffer size
#define MAX_INPUT_SIZE 1024

// Define the characters that are allowed in the input
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";

// Function to check if a character is allowed
int is_allowed_char(char c) {
  int i;
  for (i = 0; i < strlen(allowed_chars); i++) {
    if (c == allowed_chars[i]) {
      return 1;
    }
  }
  return 0;
}

// Function to sanitize the input
char *sanitize_input(char *input) {
  int i;
  char *sanitized_input = malloc(MAX_INPUT_SIZE);
  for (i = 0; i < strlen(input); i++) {
    if (is_allowed_char(input[i])) {
      sanitized_input[i] = input[i];
    }
  }
  sanitized_input[i] = '\0';
  return sanitized_input;
}

int main() {
  char input[MAX_INPUT_SIZE];
  char *sanitized_input;

  // Get the input from the user
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Sanitize the input
  sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}