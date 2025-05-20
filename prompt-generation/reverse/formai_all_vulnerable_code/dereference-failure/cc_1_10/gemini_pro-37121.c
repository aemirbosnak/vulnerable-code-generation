//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maximum length of a URL.
#define MAX_URL_LENGTH 1024

// The maximum number of characters that can be added to a URL before it becomes too long.
#define MAX_ADDITION_LENGTH 128

// The characters that are allowed in a URL.
const char *ALLOWED_CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_.~:/";

// The characters that are not allowed in a URL.
const char *DISALLOWED_CHARACTERS = "\"'\\";

// The characters that are escaped in a URL.
const char *ESCAPED_CHARACTERS = "%";

// The function to sanitize a URL.
char *sanitize_url(char *url) {
  // Check if the URL is too long.

  if (strlen(url) > MAX_URL_LENGTH) {
    fprintf(stderr, "The URL is too long.\n");
    return NULL;
  }

  // Check if the URL contains any disallowed characters.

  for (int i = 0; i < strlen(url); i++) {
    if (strchr(DISALLOWED_CHARACTERS, url[i]) != NULL) {
      fprintf(stderr, "The URL contains a disallowed character.\n");
      return NULL;
    }
  }

  // Escape any characters that need to be escaped.

  char *new_url = malloc(strlen(url) + MAX_ADDITION_LENGTH);
  int new_url_length = 0;

  for (int i = 0; i < strlen(url); i++) {
    if (strchr(ESCAPED_CHARACTERS, url[i]) != NULL) {
      new_url[new_url_length++] = '%';
      new_url[new_url_length++] = url[i];
    } else {
      new_url[new_url_length++] = url[i];
    }
  }

  new_url[new_url_length] = '\0';

  return new_url;
}

// The main function.
int main(int argc, char **argv) {
  // Check if the user has provided a URL.

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Sanitize the URL.

  char *sanitized_url = sanitize_url(argv[1]);

  // Check if the URL was sanitized successfully.

  if (sanitized_url == NULL) {
    return EXIT_FAILURE;
  }

  // Print the sanitized URL.

  printf("%s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.

  free(sanitized_url);

  return EXIT_SUCCESS;
}