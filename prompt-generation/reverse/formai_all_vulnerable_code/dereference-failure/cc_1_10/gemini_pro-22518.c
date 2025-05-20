//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input buffer
#define MAX_BUFFER_SIZE 1024

// Define the function to sanitize the input
char* sanitize_input(char* input) {
  // Allocate memory for the sanitized input
  char* sanitized_input = (char*)malloc(MAX_BUFFER_SIZE);

  // Copy the input into the sanitized input
  strcpy(sanitized_input, input);

  // Replace all occurrences of the characters '<', '>', and '&' with HTML entities
  for (int i = 0; i < strlen(sanitized_input); i++) {
    if (sanitized_input[i] == '<') {
      sanitized_input[i] = '&';
      sanitized_input[i+1] = 'l';
      sanitized_input[i+2] = 't';
      sanitized_input[i+3] = ';';
      i += 3;
    } else if (sanitized_input[i] == '>') {
      sanitized_input[i] = '&';
      sanitized_input[i+1] = 'g';
      sanitized_input[i+2] = 't';
      sanitized_input[i+3] = ';';
      i += 3;
    } else if (sanitized_input[i] == '&') {
      sanitized_input[i] = '&';
      sanitized_input[i+1] = 'a';
      sanitized_input[i+2] = 'm';
      sanitized_input[i+3] = 'p';
      sanitized_input[i+4] = ';';
      i += 4;
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

// Define the main function
int main() {
  // Get the input from the user
  char input[MAX_BUFFER_SIZE];
  printf("Enter your input: ");
  scanf("%s", input);

  // Sanitize the input
  char* sanitized_input = sanitize_input(input);

  // Print the sanitized input
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the sanitized input
  free(sanitized_input);

  return 0;
}