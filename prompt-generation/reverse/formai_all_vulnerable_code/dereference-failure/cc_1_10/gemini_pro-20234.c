//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// A function to encode a string into a URL-safe format.
char *url_encode(const char *str) {
  char *encoded = curl_escape(str, strlen(str));
  if (encoded == NULL) {
    return NULL;
  }

  // Replace '+' with "%2B" and '*' with "%2A".
  char *new_encoded = malloc(strlen(encoded) + 6);
  if (new_encoded == NULL) {
    free(encoded);
    return NULL;
  }

  char *p = encoded;
  char *q = new_encoded;
  while (*p) {
    if (*p == '+') {
      strcpy(q, "%2B");
      q += 3;
    } else if (*p == '*') {
      strcpy(q, "%2A");
      q += 3;
    } else {
      *q++ = *p;
    }
    p++;
  }
  *q = '\0';

  free(encoded);
  return new_encoded;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  char *encoded = url_encode(argv[1]);
  if (encoded == NULL) {
    printf("Error: Unable to encode URL.\n");
    return 1;
  }

  printf("Encoded URL: %s\n", encoded);
  free(encoded);

  return 0;
}