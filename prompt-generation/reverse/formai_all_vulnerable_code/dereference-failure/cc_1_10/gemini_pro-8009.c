//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: paranoid
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

// Define a macro for checking if a character is valid in a URL.
#define IS_VALID_URL_CHAR(c) ((isalnum(c)) || (strchr(".-_", c) != NULL))

// Define a macro for checking if a string is a valid URL.
#define IS_VALID_URL(str) ((strlen(str) > 0) && (strchr(str, ' ') == NULL) && (strchr(str, '\n') == NULL) && (strchr(str, '\r') == NULL))

// Define a function to sanitize a URL.
char *sanitize_url(const char *url) {
  // Allocate memory for the sanitized URL.
  char *sanitized_url = malloc(strlen(url) + 1);

  // Copy the URL to the sanitized URL.
  strcpy(sanitized_url, url);

  // Iterate over the characters in the sanitized URL.
  for (char *c = sanitized_url; *c != '\0'; c++) {
    // If the character is not valid in a URL, replace it with an underscore.
    if (!IS_VALID_URL_CHAR(*c)) {
      *c = '_';
    }
  }

  // Return the sanitized URL.
  return sanitized_url;
}

int main(int argc, char **argv) {
  // Check if the user has provided a URL.
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Check if the URL is valid.
  if (!IS_VALID_URL(argv[1])) {
    printf("Error: Invalid URL.\n");
    return 1;
  }

  // Sanitize the URL.
  char *sanitized_url = sanitize_url(argv[1]);

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  return 0;
}