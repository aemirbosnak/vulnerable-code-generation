//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the maximum length of the input string.
#define MAX_INPUT_LENGTH 1024

// Define the characters that are allowed in the input string.
#define ALLOWED_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_."

// Get a valid input string from the user.
char *get_valid_input_string(void) {
  // Allocate memory for the input string.
  char *input_string = malloc(MAX_INPUT_LENGTH);

  // Get the input string from the user.
  printf("Enter a string: ");
  fgets(input_string, MAX_INPUT_LENGTH, stdin);

  // Remove the newline character from the input string.
  input_string[strlen(input_string) - 1] = '\0';

  // Check if the input string is valid.
  if (!is_valid_input_string(input_string)) {
    // The input string is not valid. Print an error message and get a new input string from the user.
    printf("Invalid input string. Please enter a string that contains only the following characters: %s\n", ALLOWED_CHARACTERS);
    free(input_string);
    return get_valid_input_string();
  }

  // The input string is valid. Return the input string.
  return input_string;
}

// Check if the given string is a valid input string.
int is_valid_input_string(char *input_string) {
  // Check if the input string is empty.
  if (strlen(input_string) == 0) {
    return 0;
  }

  // Check if the input string contains any characters that are not allowed.
  for (int i = 0; i < strlen(input_string); i++) {
    if (strchr(ALLOWED_CHARACTERS, input_string[i]) == NULL) {
      return 0;
    }
  }

  // The input string is valid. Return 1.
  return 1;
}

// Main function.
int main(void) {
  // Get a valid input string from the user.
  char *input_string = get_valid_input_string();

  // Print the input string.
  printf("The input string is: %s\n", input_string);

  // Free the memory allocated for the input string.
  free(input_string);

  return 0;
}