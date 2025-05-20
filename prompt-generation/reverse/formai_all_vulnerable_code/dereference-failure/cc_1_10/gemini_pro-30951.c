//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: irregular
#include <regex.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Make sure the URL is properly encoded.
static char *sanitize_url(const char *url) {
  char *encoded_url = curl_easy_escape(NULL, url, 0);
  if (!encoded_url) return NULL;

  // Now, make sure the encoded URL is safe.
  char *safe_url = malloc(strlen(encoded_url) + 1);
  if (!safe_url) {
    free(encoded_url);
    return NULL;
  }

  strcpy(safe_url, encoded_url);
  free(encoded_url);

  // Replace all instances of "&" with "%26".
  while ((safe_url = strstr(safe_url, "&"))) *safe_url++ = '%';
  *safe_url = '\0';

  // Replace all instances of "+" with "%2B".
  while ((safe_url = strstr(safe_url, "+"))) *safe_url++ = '%';
  *safe_url = '\0';

  // Replace all instances of "=" with "%3D".
  while ((safe_url = strstr(safe_url, "="))) *safe_url++ = '%';
  *safe_url = '\0';

  return safe_url;
}

// Retrieve the URL from the command line.
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *safe_url = sanitize_url(argv[1]);
  if (!safe_url) {
    fprintf(stderr, "Error: Could not sanitize URL.\n");
    return EXIT_FAILURE;
  }

  printf("Safe URL: %s\n", safe_url);
  free(safe_url);

  return EXIT_SUCCESS;
}