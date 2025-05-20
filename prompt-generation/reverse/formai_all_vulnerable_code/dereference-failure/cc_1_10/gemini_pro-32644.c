//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 2048

// Function to check if a character is allowed in a URL
static bool is_valid_url_character(char c) {
  return isalnum(c) || c == '_' || c == '-' || c == '.' || c == '/' || c == ':';
}

// Function to sanitize a URL
static char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  if (sanitized_url == NULL) {
    return NULL;
  }

  // Initialize the sanitized URL to empty
  sanitized_url[0] = '\0';

  // Loop through the characters in the URL
  for (int i = 0; i < strlen(url); i++) {
    // Check if the character is allowed in a URL
    if (is_valid_url_character(url[i])) {
      // Append the character to the sanitized URL
      strncat(sanitized_url, &url[i], 1);
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a URL
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    printf("Error: Could not allocate memory for sanitized URL.\n");
    return 1;
  }

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}