//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Sanitizes user input by stripping out any non-alphanumeric characters.
 *
 * Args:
 *   input: The input string to be sanitized.
 *
 * Returns:
 *   A pointer to the sanitized string.
 */
char *sanitize_input(char *input) {
  // Allocate memory for the sanitized string.
  char *sanitized = malloc(strlen(input) + 1);
  if (sanitized == NULL) {
    fprintf(stderr, "Error: malloc() failed.\n");
    exit(EXIT_FAILURE);
  }

  // Initialize the sanitized string to empty.
  sanitized[0] = '\0';

  // Iterate over the input string, copying only alphanumeric characters to the sanitized string.
  for (int i = 0; i < strlen(input); i++) {
    if (isalnum(input[i])) {
      strncat(sanitized, &input[i], 1);
    }
  }

  // Return the sanitized string.
  return sanitized;
}

int main(int argc, char **argv) {
  // Get the user input.
  char *input = argv[1];

  // Sanitize the user input.
  char *sanitized = sanitize_input(input);

  // Print the sanitized input.
  printf("%s\n", sanitized);

  // Free the memory allocated for the sanitized string.
  free(sanitized);

  return EXIT_SUCCESS;
}