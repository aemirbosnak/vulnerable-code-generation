//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Defines the maximum length of a user input.
#define MAX_INPUT_LENGTH 1024

// This function sanitizes a user input by removing any characters that are not allowed.
char *sanitize_input(char *input) {
  // Creates a new string to store the sanitized input.
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);
  if (sanitized_input == NULL) {
    return NULL;
  }

  // Initializes the sanitized input to an empty string.
  *sanitized_input = '\0';

  // Iterates over the input string.
  for (int i = 0; i < strlen(input); i++) {
    // Checks if the current character is allowed.
    if (input[i] >= 'a' && input[i] <= 'z') {
      // If the current character is a lowercase letter, it is added to the sanitized input.
      strncat(sanitized_input, &input[i], 1);
    } else if (input[i] >= 'A' && input[i] <= 'Z') {
      // If the current character is an uppercase letter, it is added to the sanitized input.
      strncat(sanitized_input, &input[i], 1);
    } else if (input[i] >= '0' && input[i] <= '9') {
      // If the current character is a digit, it is added to the sanitized input.
      strncat(sanitized_input, &input[i], 1);
    } else if (input[i] == ' ') {
      // If the current character is a space, it is added to the sanitized input.
      strncat(sanitized_input, &input[i], 1);
    } else if (input[i] == '.' || input[i] == '-' || input[i] == '_' || input[i] == '@') {
      // If the current character is a period, hyphen, underscore, or at sign, it is added to the sanitized input.
      strncat(sanitized_input, &input[i], 1);
    } else if (input[i] == '^') {
      // If the current character is a caret, it is replaced with the string "**".
      strncat(sanitized_input, "**", 2);
    } else if (input[i] == '&') {
      // If the current character is an ampersand, it is replaced with the string "&&".
      strncat(sanitized_input, "&&", 2);
    } else if (input[i] == '|') {
      // If the current character is a pipe, it is replaced with the string "||".
      strncat(sanitized_input, "||", 2);
    } else if (input[i] == '<') {
      // If the current character is a less than sign, it is replaced with the string "&lt;".
      strncat(sanitized_input, "&lt;", 4);
    } else if (input[i] == '>') {
      // If the current character is a greater than sign, it is replaced with the string "&gt;".
      strncat(sanitized_input, "&gt;", 4);
    } else if (input[i] == '"') {
      // If the current character is a double quote, it is replaced with the string "&quot;".
      strncat(sanitized_input, "&quot;", 6);
    } else if (input[i] == '\'') {
      // If the current character is a single quote, it is replaced with the string "&apos;".
      strncat(sanitized_input, "&apos;", 6);
    } else if (input[i] == '/') {
      // If the current character is a slash, it is replaced with the string "&#47;".
      strncat(sanitized_input, "&#47;", 5);
    } else if (input[i] == '\\') {
      // If the current character is a backslash, it is replaced with the string "&#92;".
      strncat(sanitized_input, "&#92;", 5);
    }
  }

  // Returns the sanitized input.
  return sanitized_input;
}

// This function prompts the user for input and sanitizes it.
char *get_sanitized_input(char *prompt) {
  // Prints the prompt to the user.
  printf("%s", prompt);

  // Gets the user input.
  char *input = NULL;
  size_t input_length = 0;
  getline(&input, &input_length, stdin);

  // Sanitizes the user input.
  char *sanitized_input = sanitize_input(input);

  // Frees the user input.
  free(input);

  // Returns the sanitized input.
  return sanitized_input;
}

int main() {
  // Gets the user input.
  char *input = get_sanitized_input("Enter your input: ");

  // Prints the sanitized input.
  printf("Sanitized input: %s\n", input);

  // Frees the sanitized input.
  free(input);

  return 0;
}