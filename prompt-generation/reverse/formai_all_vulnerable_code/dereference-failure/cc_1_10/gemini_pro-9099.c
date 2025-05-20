//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Donald Knuth
#include "curl/curl.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Forward declarations
char *escape_url(const char *url);
char *unescape_url(const char *url);

// Main function
int main(int argc, char **argv) {
  // Check if the user provided a URL
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return 1;
  }

  // Escape the URL
  char *escaped_url = escape_url(argv[1]);
  if (escaped_url == NULL) {
    fprintf(stderr, "Error escaping URL\n");
    return 1;
  }

  // Print the escaped URL
  printf("Escaped URL: %s\n", escaped_url);

  // Unescape the URL
  char *unescaped_url = unescape_url(escaped_url);
  if (unescaped_url == NULL) {
    fprintf(stderr, "Error unescaping URL\n");
    return 1;
  }

  // Print the unescaped URL
  printf("Unescaped URL: %s\n", unescaped_url);

  // Free the allocated memory
  free(escaped_url);
  free(unescaped_url);

  return 0;
}

// Escape a URL
char *escape_url(const char *url) {
  // Allocate memory for the escaped URL
  char *escaped_url = malloc(strlen(url) * 3 + 1);
  if (escaped_url == NULL) {
    return NULL;
  }

  // Escape the URL
  int length = curl_easy_escape(NULL, url, 0);
  if (length < 0) {
    free(escaped_url);
    return NULL;
  }
  curl_easy_escape(escaped_url, url, length);

  // Return the escaped URL
  return escaped_url;
}

// Unescape a URL
char *unescape_url(const char *url) {
  // Allocate memory for the unescaped URL
  char *unescaped_url = malloc(strlen(url) + 1);
  if (unescaped_url == NULL) {
    return NULL;
  }

  // Unescape the URL
  int length = curl_easy_unescape(NULL, url, 0, NULL);
  if (length < 0) {
    free(unescaped_url);
    return NULL;
  }
  curl_easy_unescape(unescaped_url, url, length, NULL);

  // Return the unescaped URL
  return unescaped_url;
}