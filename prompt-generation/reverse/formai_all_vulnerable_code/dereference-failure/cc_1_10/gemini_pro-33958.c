//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

// Declare the global variables
char *input_buffer;
int input_buffer_size;
int input_buffer_length;

// Define the function to sanitize the user input
void sanitize_input(char *input) {
  // Initialize the variables
  int i = 0;
  int j = 0;
  char *sanitized_input = malloc(MAX_INPUT_LENGTH);

  // Loop through the input string
  while (input[i] != '\0') {
    // Check if the character is allowed
    if ((input[i] >= 'a' && input[i] <= 'z') ||
        (input[i] >= 'A' && input[i] <= 'Z') ||
        (input[i] >= '0' && input[i] <= '9') ||
        input[i] == ' ' || input[i] == '.' || input[i] == ',') {
      // Add the character to the sanitized input string
      sanitized_input[j] = input[i];
      j++;
    }
    // Increment the index of the input string
    i++;
  }

  // Terminate the sanitized input string
  sanitized_input[j] = '\0';

  // Copy the sanitized input string to the input buffer
  strcpy(input_buffer, sanitized_input);
  input_buffer_length = strlen(input_buffer);

  // Free the memory allocated for the sanitized input string
  free(sanitized_input);
}

// Define the main function
int main() {
  // Allocate memory for the input buffer
  input_buffer = malloc(MAX_INPUT_LENGTH);
  input_buffer_size = MAX_INPUT_LENGTH;
  input_buffer_length = 0;

  // Get the user input
  printf("Enter your input: ");
  fgets(input_buffer, input_buffer_size, stdin);

  // Sanitize the user input
  sanitize_input(input_buffer);

  // Print the sanitized input
  printf("Sanitized input: %s", input_buffer);

  // Free the memory allocated for the input buffer
  free(input_buffer);

  return 0;
}