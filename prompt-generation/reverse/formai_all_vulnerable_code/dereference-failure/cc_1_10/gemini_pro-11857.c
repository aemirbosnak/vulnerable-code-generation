//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>

#define MAX_URL_LEN 2048

int main(int argc, char **argv) {
  // Get the URL from the command line.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *url = argv[1];
  if (*url != 'h') {
    fprintf(stderr, "Error: URL must start with 'h'.\n");
    return EXIT_FAILURE;
  }

  // Allocate memory for the sanitized URL.
  char *sanitized_url = malloc(MAX_URL_LEN);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error: Could not allocate memory for sanitized URL.\n");
    return EXIT_FAILURE;
  }

  // Sanitize the URL.
  int i = 0;
  int j = 0;
  while (url[i] != '\0') {
    // Convert non-ASCII characters to escape sequences.
    if ((unsigned char)url[i] >= 0x80) {
      sprintf(sanitized_url + j, "%%%02X", (unsigned char)url[i]);
      j += 3;
    } else {
      // Convert spaces to '+' characters.
      if (isspace(url[i])) {
        sanitized_url[j] = '+';
      } else {
        sanitized_url[j] = url[i];
      }
      j++;
    }
    i++;
  }

  // Null-terminate the sanitized URL.
  sanitized_url[j] = '\0';

  // Print the sanitized URL.
  printf("Sanitized URL: %s\n", sanitized_url);

  // Free the memory allocated for the sanitized URL.
  free(sanitized_url);

  return EXIT_SUCCESS;
}