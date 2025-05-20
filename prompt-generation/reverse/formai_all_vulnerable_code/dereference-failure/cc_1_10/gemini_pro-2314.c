//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "curl/curl.h"

// Define the maximum length of a URL
#define MAX_URL_LEN 2048

// Define the list of allowed characters in a URL
char allowed_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.-_!~*'()";

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = (char *)malloc(MAX_URL_LEN);

  // Initialize the sanitized URL to the empty string
  sanitized_url[0] = '\0';

  // Loop through the characters in the URL
  for (int i = 0; i < strlen(url); i++) {
    // Check if the current character is allowed
    if (strchr(allowed_chars, url[i]) != NULL) {
      // If the current character is allowed, append it to the sanitized URL
      strncat(sanitized_url, &url[i], 1);
    } else {
      // If the current character is not allowed, replace it with an underscore
      strncat(sanitized_url, "_", 1);
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user has provided a URL
  if (argc < 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  // Get the URL from the user
  char *url = argv[1];

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}