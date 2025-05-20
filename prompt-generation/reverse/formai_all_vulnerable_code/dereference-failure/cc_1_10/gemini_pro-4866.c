//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: safe
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the characters that are allowed in the input string.
const char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ,.";

// Get a line of input from the user.
char *get_input(void) {
  // Allocate memory for the input string.
  char *input = malloc(MAX_INPUT_LENGTH * sizeof(char));
  if (input == NULL) {
    fprintf(stderr, "Error: malloc() failed.\n");
    exit(1);
  }

  // Get a line of input from the user.
  printf("Enter a line of text: ");
  if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL) {
    fprintf(stderr, "Error: fgets() failed.\n");
    exit(1);
  }

  // Remove the newline character from the end of the input string.
  input[strcspn(input, "\n")] = '\0';

  // Return the input string.
  return input;
}

// Sanitize the input string.
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized input string.
  char *sanitized_input = malloc(MAX_INPUT_LENGTH * sizeof(char));
  if (sanitized_input == NULL) {
    fprintf(stderr, "Error: malloc() failed.\n");
    exit(1);
  }

  // Copy the allowed characters from the input string to the sanitized input string.
  int j = 0;
  for (int i = 0; i < strlen(input); i++) {
    if (strchr(allowed_chars, input[i]) != NULL) {
      sanitized_input[j] = input[i];
      j++;
    }
  }

  // Add the null terminator to the end of the sanitized input string.
  sanitized_input[j] = '\0';

  // Return the sanitized input string.
  return sanitized_input;
}

// Print the sanitized input string.
void print_sanitized_input(char *sanitized_input) {
  printf("Sanitized input: %s\n", sanitized_input);
}

// Free the memory allocated for the input string and the sanitized input string.
void free_memory(char *input, char *sanitized_input) {
  free(input);
  free(sanitized_input);
}

// Main function.
int main(void) {
  // Get a line of input from the user.
  char *input = get_input();

  // Sanitize the input string.
  char *sanitized_input = sanitize_input(input);

  // Print the sanitized input string.
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input string and the sanitized input string.
  free_memory(input, sanitized_input);

  return 0;
}