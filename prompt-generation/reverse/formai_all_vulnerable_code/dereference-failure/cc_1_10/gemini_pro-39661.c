//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type for a sanitized string.
typedef char *SanitizedString;

// Define a macro to check if a character is valid.
#define IS_VALID_CHAR(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ')

// Define a function to sanitize a string.
SanitizedString sanitize_string(char *input) {
  // Allocate memory for the sanitized string.
  SanitizedString sanitized = malloc(strlen(input) + 1);

  // Initialize the sanitized string to the empty string.
  sanitized[0] = '\0';

  // Iterate over the characters in the input string.
  for (int i = 0; input[i] != '\0'; i++) {
    // Check if the character is valid.
    if (IS_VALID_CHAR(input[i])) {
      // Append the character to the sanitized string.
      strcat(sanitized, &input[i]);
    }
  }

  // Return the sanitized string.
  return sanitized;
}

// Define a function to get a sanitized string from the user.
SanitizedString get_sanitized_string(char *prompt) {
  // Prompt the user for input.
  printf("%s", prompt);

  // Get the input from the user.
  char *input = malloc(1024);
  fgets(input, 1024, stdin);

  // Sanitize the input.
  SanitizedString sanitized = sanitize_string(input);

  // Free the memory allocated for the input string.
  free(input);

  // Return the sanitized string.
  return sanitized;
}

// Define a function to main program.
int main() {
  // Get a sanitized string from the user.
  SanitizedString name = get_sanitized_string("Enter your name: ");

  // Print the sanitized string.
  printf("Your name is: %s\n", name);

  // Free the memory allocated for the sanitized string.
  free(name);

  // Return 0 to indicate success.
  return 0;
}