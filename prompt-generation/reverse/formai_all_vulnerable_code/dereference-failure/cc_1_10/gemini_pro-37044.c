//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Function to sanitize the input string
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized string
  char* sanitized_input = malloc(strlen(input) + 1);

  // Copy the input string to the sanitized string
  strcpy(sanitized_input, input);

  // Replace all non-alphanumeric characters with spaces
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (!isalnum(sanitized_input[i])) {
      sanitized_input[i] = ' ';
    }
  }

  // Remove all leading and trailing spaces
  while (isspace(sanitized_input[0])) {
    memmove(sanitized_input, sanitized_input + 1, strlen(sanitized_input));
  }
  while (isspace(sanitized_input[strlen(sanitized_input) - 1])) {
    sanitized_input[strlen(sanitized_input) - 1] = '\0';
  }

  // Return the sanitized string
  return sanitized_input;
}

// Main function
int main() {
  // Declare the input buffer
  char input_buffer[MAX_BUFFER_SIZE];

  // Prompt the user for input
  printf("Enter your input: ");

  // Read the input from the user
  fgets(input_buffer, MAX_BUFFER_SIZE, stdin);

  // Sanitize the input
  char* sanitized_input = sanitize_input(input_buffer);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized string
  free(sanitized_input);

  return 0;
}