//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to sanitize user input
char *sanitize_input(char *input) {
  int i, j;
  char *sanitized_input = malloc(strlen(input) + 1);

  // Allocate memory for the sanitized input string
  if (sanitized_input == NULL) {
    printf("Error allocating memory for sanitized input string.\n");
    return NULL;
  }

  // Copy the input string to the sanitized input string
  strcpy(sanitized_input, input);

  // Iterate over the sanitized input string
  for (i = 0, j = 0; sanitized_input[i] != '\0'; i++) {
    // Check if the character is a valid character
    if (isalnum(sanitized_input[i]) || sanitized_input[i] == ' ' || sanitized_input[i] == '_') {
      // If the character is valid, copy it to the sanitized input string
      sanitized_input[j++] = sanitized_input[i];
    }
  }

  // Null-terminate the sanitized input string
  sanitized_input[j] = '\0';

  // Return the sanitized input string
  return sanitized_input;
}

// Main function
int main() {
  char *input;
  char *sanitized_input;

  // Get the user input
  printf("Enter a string: ");
  input = malloc(100);  
  scanf("%s", input);

  // Sanitize the user input
  sanitized_input = sanitize_input(input);

  // Print the sanitized input string
  printf("Sanitized input: %s\n", sanitized_input);

  // Free the memory allocated for the input and sanitized input strings
  free(input);
  free(sanitized_input);

  return 0;
}