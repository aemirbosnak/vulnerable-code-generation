//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define the maximum length of a URL.
#define MAX_URL_LENGTH 2048

// Define the characters that are allowed in a URL.
#define ALLOWED_URL_CHARACTERS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_"

// Define the characters that are not allowed in a URL.
#define DISALLOWED_URL_CHARACTERS "!\"#$%&'()*+,/:;<=>?@[\\]^`{|}~"

// Function to sanitize a URL.
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL.
  char *sanitized_url = malloc(MAX_URL_LENGTH);
  if (sanitized_url == NULL) {
    return NULL;
  }

  // Initialize the sanitized URL to an empty string.
  sanitized_url[0] = '\0';

  // Loop through the characters in the URL.
  for (int i = 0; i < strlen(url); i++) {
    // Check if the character is allowed in a URL.
    if (strchr(ALLOWED_URL_CHARACTERS, url[i]) != NULL) {
      // If the character is allowed, append it to the sanitized URL.
      strncat(sanitized_url, &url[i], 1);
    } else {
      // If the character is not allowed, replace it with an underscore.
      strncat(sanitized_url, "_", 1);
    }
  }

  // Return the sanitized URL.
  return sanitized_url;
}

// Function to main.
int main(int argc, char *argv[]) {
  // Check if the user has provided a URL.
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the URL from the user.
  char *url = argv[1];

  // Sanitize the URL.
  char *sanitized_url = sanitize_url(url);
  if (sanitized_url == NULL) {
    printf("Error: Could not sanitize URL.\n");
    return EXIT_FAILURE;
  }

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  return EXIT_SUCCESS;
}