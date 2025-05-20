//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

// A mind-bending C URL sanitizer
// This program takes a URL as input and sanitizes it according to the following rules:
// - All spaces are replaced with underscores.
// - All non-alphanumeric characters are replaced with dashes.
// - All URLs are converted to lowercase.
// - All URLs are prefixed with "http://" if they do not already start with a scheme.

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s URL\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Allocate memory for the sanitized URL.
  char *sanitized_url = malloc(strlen(argv[1]) + 1);
  if (sanitized_url == NULL) {
    perror("malloc");
    return EXIT_FAILURE;
  }

  // Copy the input URL to the sanitized URL.
  strcpy(sanitized_url, argv[1]);

  // Convert the sanitized URL to lowercase.
  for (char *c = sanitized_url; *c != '\0'; c++) {
    *c = tolower(*c);
  }

  // Replace all spaces with underscores.
  for (char *c = sanitized_url; *c != '\0'; c++) {
    if (*c == ' ') {
      *c = '_';
    }
  }

  // Replace all non-alphanumeric characters with dashes.
  regex_t regex;
  if (regcomp(&regex, "[^a-zA-Z0-9]", REG_EXTENDED) != 0) {
    perror("regcomp");
    return EXIT_FAILURE;
  }

  for (char *c = sanitized_url; *c != '\0'; c++) {
    if (regexec(&regex, c, 0, NULL, 0) == 0) {
      *c = '-';
    }
  }

  regfree(&regex);

  // Add "http://" to the beginning of the sanitized URL if it does not already start with a scheme.
  if (strncmp(sanitized_url, "http://", 7) != 0) {
    memmove(sanitized_url + 7, sanitized_url, strlen(sanitized_url) + 1);
    memcpy(sanitized_url, "http://", 7);
  }

  // Print the sanitized URL to stdout.
  printf("%s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  return EXIT_SUCCESS;
}