//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input size.
#define MAX_INPUT_SIZE 1024

// Define the list of allowed characters.
char allowed_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,?!;: ";

// Get the user input.
char *get_input() {
  // Allocate memory for the input string.
  char *input = malloc(MAX_INPUT_SIZE);

  // Get the input string from the user.
  printf("Enter your input: ");
  fgets(input, MAX_INPUT_SIZE, stdin);

  // Remove the newline character from the input string.
  input[strcspn(input, "\n")] = '\0';

  // Return the input string.
  return input;
}

// Sanitize the user input.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input string.
  char *sanitized_input = malloc(MAX_INPUT_SIZE);

  // Initialize the sanitized input string to empty.
  sanitized_input[0] = '\0';

  // Iterate over the characters in the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Check if the character is allowed.
    if (strchr(allowed_chars, input[i]) != NULL) {
      // If the character is allowed, add it to the sanitized input string.
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized input string.
  return sanitized_input;
}

// Print the sanitized user input.
void print_sanitized_input(char *sanitized_input) {
  // Print the sanitized input string.
  printf("Sanitized input: %s\n", sanitized_input);
}

// Main function.
int main() {
  // Get the user input.
  char *input = get_input();

  // Sanitize the user input.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized user input.
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input string.
  free(input);

  // Free the memory allocated for the sanitized input string.
  free(sanitized_input);

  // Return 0 to indicate success.
  return 0;
}