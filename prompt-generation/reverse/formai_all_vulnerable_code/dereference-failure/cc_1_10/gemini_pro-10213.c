//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a custom data type to represent a sanitized string.
typedef struct {
  char *string;
  size_t length;
} SanitizedString;

// Create a new sanitized string.
SanitizedString new_sanitized_string(const char *string) {
  SanitizedString sanitized_string;
  sanitized_string.string = strdup(string);
  sanitized_string.length = strlen(string);
  return sanitized_string;
}

// Free the memory allocated for a sanitized string.
void free_sanitized_string(SanitizedString *sanitized_string) {
  free(sanitized_string->string);
  sanitized_string->string = NULL;
  sanitized_string->length = 0;
}

// Sanitize a string by removing all non-alphanumeric characters.
SanitizedString sanitize_string(const char *string) {
  SanitizedString sanitized_string = new_sanitized_string(string);

  // Iterate over the string, removing any non-alphanumeric characters.
  for (size_t i = 0; i < sanitized_string.length; i++) {
    if (!isalnum(sanitized_string.string[i])) {
      // If the current character is not alphanumeric, replace it with a space.
      sanitized_string.string[i] = ' ';
    }
  }

  // Trim any leading or trailing whitespace from the sanitized string.
  sanitized_string.string = strtok(sanitized_string.string, " ");
  sanitized_string.length = strlen(sanitized_string.string);

  return sanitized_string;
}

// Get a sanitized string from the user.
SanitizedString get_sanitized_string(const char *prompt) {
  // Prompt the user to enter a string.
  printf("%s", prompt);

  // Get the user's input.
  char input[1024];
  fgets(input, sizeof(input), stdin);

  // Sanitize the user's input.
  SanitizedString sanitized_string = sanitize_string(input);

  // Return the sanitized string.
  return sanitized_string;
}

// Main function.
int main() {
  // Get a sanitized string from the user.
  SanitizedString sanitized_string = get_sanitized_string("Enter a string: ");

  // Print the sanitized string.
  printf("Sanitized string: %s\n", sanitized_string.string);

  // Free the memory allocated for the sanitized string.
  free_sanitized_string(&sanitized_string);

  return 0;
}