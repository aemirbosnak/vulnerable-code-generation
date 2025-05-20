//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 1024

// Define the list of allowed characters
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

// Define the list of disallowed characters
char disallowed_chars[] = "!@#$%^&*()_+=-`~";

// Function to sanitize the input string
void sanitize_input(char *input) {
  // Loop through the input string
  for (int i = 0; input[i] != '\0'; i++) {
    // Check if the current character is allowed
    if (strchr(allowed_chars, input[i]) == NULL) {
      // If the character is not allowed, replace it with a space
      input[i] = ' ';
    }
  }
}

// Function to get the user's input
char *get_user_input() {
  // Allocate memory for the input string
  char *input = malloc(MAX_INPUT_LENGTH);

  // Prompt the user for input
  printf("Enter your input: ");

  // Read the input from the user
  fgets(input, MAX_INPUT_LENGTH, stdin);

  // Sanitize the input string
  sanitize_input(input);

  // Return the input string
  return input;
}

// Function to print the sanitized input string
void print_sanitized_input(char *input) {
  // Print the sanitized input string
  printf("Sanitized input: %s\n", input);
}

// Main function
int main() {
  // Get the user's input
  char *input = get_user_input();

  // Print the sanitized input string
  print_sanitized_input(input);

  // Free the memory allocated for the input string
  free(input);

  return 0;
}