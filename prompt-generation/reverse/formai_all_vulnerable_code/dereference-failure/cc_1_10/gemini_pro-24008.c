//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_SIZE 2048

char *sanitize_url(const char *url) {
  char *sanitized_url = malloc(MAX_URL_SIZE);
  if (!sanitized_url) {
    fprintf(stderr, "Error: Could not allocate memory for sanitized URL.\n");
    return NULL;
  }

  // Copy the URL into the sanitized buffer.
  strncpy(sanitized_url, url, MAX_URL_SIZE - 1);
  sanitized_url[MAX_URL_SIZE - 1] = '\0';

  // Replace any non-alphanumeric characters with underscores.
  for (char *p = sanitized_url; *p != '\0'; p++) {
    if (!isalnum(*p)) {
      *p = '_';
    }
  }

  // Remove any leading or trailing underscores.
  while (*sanitized_url == '_' && sanitized_url[strlen(sanitized_url) - 1] == '_') {
    if (*sanitized_url == '_') {
      sanitized_url++;
    } else {
      sanitized_url[strlen(sanitized_url) - 1] = '\0';
    }
  }

  return sanitized_url;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Sanitize the URL.
  char *sanitized_url = sanitize_url(argv[1]);
  if (!sanitized_url) {
    return EXIT_FAILURE;
  }

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  return EXIT_SUCCESS;
}