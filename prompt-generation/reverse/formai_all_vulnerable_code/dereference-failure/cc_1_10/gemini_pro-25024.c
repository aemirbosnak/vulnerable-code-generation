//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum input length
#define MAX_INPUT_LENGTH 100

// Get a valid integer from the user
int get_valid_integer(char *prompt) {
  int input;
  char buffer[MAX_INPUT_LENGTH];

  // Keep prompting the user for a valid integer
  while (1) {
    // Print the prompt
    printf("%s", prompt);

    // Get the user's input
    fgets(buffer, MAX_INPUT_LENGTH, stdin);

    // Convert the input to an integer
    input = atoi(buffer);

    // Check if the input is valid
    if (input != 0) {
      return input;
    } else {
      printf("Invalid input. Please enter an integer.\n");
    }
  }
}

// Get a valid string from the user
char *get_valid_string(char *prompt) {
  char *input;
  char buffer[MAX_INPUT_LENGTH];

  // Keep prompting the user for a valid string
  while (1) {
    // Print the prompt
    printf("%s", prompt);

    // Get the user's input
    fgets(buffer, MAX_INPUT_LENGTH, stdin);

    // Check if the input is valid
    if (strlen(buffer) > 0) {
      // Allocate memory for the input string
      input = malloc(strlen(buffer) + 1);

      // Copy the input string into the allocated memory
      strcpy(input, buffer);

      // Remove the newline character from the end of the input string
      input[strlen(input) - 1] = '\0';

      return input;
    } else {
      printf("Invalid input. Please enter a string.\n");
    }
  }
}

// Main function
int main() {
  // Get a valid integer from the user
  int number = get_valid_integer("Enter an integer: ");

  // Get a valid string from the user
  char *name = get_valid_string("Enter your name: ");

  // Print the user's input
  printf("You entered the integer %d and the string %s.\n", number, name);

  // Free the memory allocated for the input string
  free(name);

  return 0;
}