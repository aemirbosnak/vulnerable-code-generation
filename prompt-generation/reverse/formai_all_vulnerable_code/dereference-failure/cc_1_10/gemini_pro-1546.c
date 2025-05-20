//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: relaxed
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>

// This function sanitizes a given URL string.
// It removes any potentially dangerous characters that could be used to exploit vulnerabilities.
char *sanitize_url(char *url) {
  char *sanitized_url = malloc(strlen(url) + 1);
  if (sanitized_url == NULL) {
    return NULL;
  }
  strcpy(sanitized_url, url);

  // Replace any spaces with underscores.
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (sanitized_url[i] == ' ') {
      sanitized_url[i] = '_';
    }
  }

  // Remove any characters that are not alphanumeric or underscores.
  for (int i = 0; i < strlen(sanitized_url); i++) {
    if (!isalnum(sanitized_url[i]) && sanitized_url[i] != '_') {
      sanitized_url[i] = '\0';
    }
  }

  // Remove any leading or trailing underscores.
  if (sanitized_url[0] == '_') {
    sanitized_url = sanitized_url + 1;
  }
  if (sanitized_url[strlen(sanitized_url) - 1] == '_') {
    sanitized_url[strlen(sanitized_url) - 1] = '\0';
  }

  return sanitized_url;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error: Could not sanitize URL.\n");
    return EXIT_FAILURE;
  }

  printf("Sanitized URL: %s\n", sanitized_url);

  free(sanitized_url);

  return EXIT_SUCCESS;
}