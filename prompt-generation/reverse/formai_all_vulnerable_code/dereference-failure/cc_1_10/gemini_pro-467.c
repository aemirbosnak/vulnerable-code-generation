//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program sanitizes a URL by removing any unsafe characters.
 *
 * Unsafe characters are defined as any character that is not a letter,
 * number, or underscore.
 *
 * The program takes a URL as input and prints the sanitized URL to
 * the console.
 */

int main(int argc, char **argv) {
  // Check if the user provided a URL.

  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Get the URL from the user.

  char *url = argv[1];

  // Create a buffer to store the sanitized URL.

  char *sanitized_url = malloc(strlen(url) + 1);

  // Initialize the sanitized URL to the empty string.

  sanitized_url[0] = '\0';

  // Loop through the characters in the URL.

  for (int i = 0; i < strlen(url); i++) {
    // Check if the character is safe.

    if (isalnum(url[i]) || url[i] == '_') {
      // Append the character to the sanitized URL.

      strcat(sanitized_url, &url[i]);
    }
  }

  // Print the sanitized URL to the console.

  printf("%s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.

  free(sanitized_url);

  return 0;
}