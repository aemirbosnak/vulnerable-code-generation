//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Define the maximum length of input
#define MAX_INPUT_LENGTH 100

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Function to check if a string contains only allowed characters
int check_valid_input(char *input) {
  int i;
  int len = strlen(input);

  for (i = 0; i < len; i++) {
    if (!strchr(allowed_chars, input[i])) {
      return 0;
    }
  }

  return 1;
}

// Function to sanitize user input
char *sanitize_input(char *input) {
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);
  int i;
  int j = 0;

  int len = strlen(input);

  for (i = 0; i < len; i++) {
    if (strchr(allowed_chars, input[i])) {
      sanitized_input[j++] = input[i];
    }
  }

  sanitized_input[j] = '\0';

  return sanitized_input;
}

// Main function
int main() {
  char input[MAX_INPUT_LENGTH];

  printf("Enter your input: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Check if the input is valid
  if (!check_valid_input(input)) {
    printf("Invalid input. Please enter only allowed characters.\n");
    return 1;
  }

  // Sanitize the input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  free(sanitized_input);

  return 0;
}