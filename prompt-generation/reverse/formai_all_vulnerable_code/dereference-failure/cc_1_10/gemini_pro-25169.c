//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <stdbool.h>

// Function to check if a character is valid in a URL
bool is_valid_url_char(char c) {
  // Valid characters in a URL
  const char *valid_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~";

  // Check if the character is in the valid characters list
  for (int i = 0; i < strlen(valid_chars); i++) {
    if (c == valid_chars[i]) {
      return true;
    }
  }

  // Not a valid character
  return false;
}

// Function to sanitize a URL
char *sanitize_url(char *url) {
  // Allocate memory for the sanitized URL
  char *sanitized_url = malloc(strlen(url) + 1);
  if (sanitized_url == NULL) {
    perror("malloc");
    return NULL;
  }

  // Iterate over the characters in the URL
  int sanitized_url_index = 0;
  for (int i = 0; i < strlen(url); i++) {
    char c = url[i];

    // If the character is valid, add it to the sanitized URL
    if (is_valid_url_char(c)) {
      sanitized_url[sanitized_url_index++] = c;
    } else {
      // If the character is not valid, replace it with an underscore
      sanitized_url[sanitized_url_index++] = '_';
    }
  }

  // Terminate the sanitized URL with a null character
  sanitized_url[sanitized_url_index] = '\0';

  // Return the sanitized URL
  return sanitized_url;
}

int main(int argc, char **argv) {
  // Check if a URL was provided as an argument
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Sanitize the URL
  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    perror("sanitize_url");
    return EXIT_FAILURE;
  }

  // Print the sanitized URL
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL
  free(sanitized_url);

  return EXIT_SUCCESS;
}