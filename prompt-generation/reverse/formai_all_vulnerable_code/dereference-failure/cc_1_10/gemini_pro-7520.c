//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

// Romeo's input
char *romeo_input = "Wherefore art thou, Juliet?";

// Juliet's input
char *juliet_input = "On the balcony, my lord.";

// Juliet's sanitizer
char *juliet_sanitize(char *input) {
  // Juliet's input sanitizer
  // The input is considered safe if it contains only lowercase letters and spaces.

  // Allocate memory for the sanitized input
  char *sanitized_input = malloc(strlen(input) + 1);

  // Initialize the sanitized input
  strcpy(sanitized_input, "");

  // Iterate over the input
  for (int i = 0; i < strlen(input); i++) {
    // Check if the current character is valid
    if (input[i] >= 'a' && input[i] <= 'z' || input[i] == ' ') {
      // Append the character to the sanitized input
      strncat(sanitized_input, &input[i], 1);
    }
  }

  // Return the sanitized input
  return sanitized_input;
}

int main() {
  // Romeo's input sanitizer
  // The input is considered safe if it contains only lowercase letters and spaces.

  // Allocate memory for the sanitized input
  char *romeo_sanitized_input = malloc(strlen(romeo_input) + 1);

  // Initialize the sanitized input
  strcpy(romeo_sanitized_input, "");

  // Iterate over the input
  for (int i = 0; i < strlen(romeo_input); i++) {
    // Check if the current character is valid
    if (romeo_input[i] >= 'a' && romeo_input[i] <= 'z' || romeo_input[i] == ' ') {
      // Append the character to the sanitized input
      strncat(romeo_sanitized_input, &romeo_input[i], 1);
    }
  }

  // Print Romeo's sanitized input
  printf("Romeo's sanitized input: %s\n", romeo_sanitized_input);

  // Juliet's sanitized input
  char *juliet_sanitized_input = juliet_sanitize(juliet_input);

  // Print Juliet's sanitized input
  printf("Juliet's sanitized input: %s\n", juliet_sanitized_input);

  // Free the memory allocated for the sanitized inputs
  free(romeo_sanitized_input);
  free(juliet_sanitized_input);

  return 0;
}