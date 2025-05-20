//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Define the maximum length of a URL
#define MAX_URL_LENGTH 2048

// Define the list of allowed characters in a URL
const char *allowed_characters = "abcdefghijklmnopqrstuvwxyz"
                                  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "0123456789"
                                  "-._~:/?#[]@!$&'()*+,;=";

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(MAX_URL_LENGTH);

  // Initialize the sanitized URL
  sanitized_url[0] = '\0';

  // Loop through the characters in the URL
  for (int i = 0; i < strlen(url); i++) {
    // If the character is allowed, append it to the sanitized URL
    if (strchr(allowed_characters, url[i]) != NULL) {
      strncat(sanitized_url, &url[i], 1);
    }
  }

  // Return the sanitized URL
  return sanitized_url;
}

// Function to test the sanitize_url function
int main() {
  // Define a test URL
  char *url = "http://www.example.com/path/to/file.html?query=string#fragment";

  // Sanitize the URL
  char *sanitized_url = sanitize_url(url);

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return 0;
}