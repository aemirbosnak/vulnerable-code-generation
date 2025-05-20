//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Copy the input to the sanitized input string
  strcpy(sanitized_input, input);

  // Convert all non-alphanumeric characters to spaces
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (!isalnum(sanitized_input[i])) {
      sanitized_input[i] = ' ';
    }
  }

  // Remove any leading or trailing spaces
  while (isspace(*sanitized_input)) {
    sanitized_input++;
  }
  while (isspace(sanitized_input[strlen(sanitized_input) - 1])) {
    sanitized_input[strlen(sanitized_input) - 1] = '\0';
  }

  // Return the sanitized input string
  return sanitized_input;
}

// Main function
int main() {
  // Get the user input
  char input[100];
  printf("Enter your input: ");
  fgets(input, sizeof(input), stdin);

  // Sanitize the user input
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s", sanitized_input);

  // Free the allocated memory
  free(sanitized_input);

  return 0;
}