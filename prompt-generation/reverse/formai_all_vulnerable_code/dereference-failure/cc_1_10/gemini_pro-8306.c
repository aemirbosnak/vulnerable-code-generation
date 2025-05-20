//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters.
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 .,?!:;";

// Define the list of disallowed characters.
char disallowed_chars[] = "~`#$%^&*_+-=<>/";

// Function to sanitize the input string.
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized string.
  char* sanitized_string = malloc(MAX_INPUT_LENGTH);

  // Copy the input string to the sanitized string.
  strcpy(sanitized_string, input);

  // Iterate over the sanitized string and replace any disallowed characters with a space.
  for (int i = 0; i < strlen(sanitized_string); i++) {
    if (strchr(disallowed_chars, sanitized_string[i]) != NULL) {
      sanitized_string[i] = ' ';
    }
  }

  // Return the sanitized string.
  return sanitized_string;
}

// Function to get the user input.
char* get_user_input() {
  // Allocate memory for the input string.
  char* input_string = malloc(MAX_INPUT_LENGTH);

  // Get the user input.
  printf("Enter your input: ");
  fgets(input_string, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the input string.
  input_string[strlen(input_string) - 1] = '\0';

  // Return the input string.
  return input_string;
}

// Function to print the sanitized input.
void print_sanitized_input(char* input) {
  // Print the sanitized input.
  printf("Sanitized input: %s\n", input);
}

// Main function.
int main() {
  // Get the user input.
  char* input = get_user_input();

  // Sanitize the input.
  char* sanitized_input = sanitize_input(input);

  // Print the sanitized input.
  print_sanitized_input(sanitized_input);

  // Free the memory allocated for the input and sanitized input strings.
  free(input);
  free(sanitized_input);

  return 0;
}