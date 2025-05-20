//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct UrlSanitizer {
  char *url;
  int length;
  char *sanitized_url;
  int sanitized_length;
} UrlSanitizer;

UrlSanitizer *sanitize_url(char *url) {
  UrlSanitizer *sanitizer = malloc(sizeof(UrlSanitizer));
  sanitizer->url = strdup(url);
  sanitizer->length = strlen(url);
  sanitizer->sanitized_url = malloc(MAX_BUFFER_SIZE);
  sanitizer->sanitized_length = 0;

  // Remove invalid characters
  char *p = sanitizer->url;
  char *q = sanitizer->sanitized_url;
  while (*p) {
    if (isalnum(*p) || *p == '-' || *p == '_') {
      *q++ = *p;
    }
    p++;
  }

  // Normalize case
  sanitizer->sanitized_url[0] = tolower(sanitizer->sanitized_url[0]);

  // Add trailing slash if necessary
  if (sanitizer->sanitized_url[sanitizer->sanitized_length - 1] != '/') {
    sanitizer->sanitized_url[sanitizer->sanitized_length++] = '/';
  }

  return sanitizer;
}

int main() {
  char *url = "http://example.com/path?query&param#fragment";
  UrlSanitizer *sanitizer = sanitize_url(url);

  printf("Original URL: %s\n", sanitizer->url);
  printf("Sanitized URL: %s\n", sanitizer->sanitized_url);

  free(sanitizer->url);
  free(sanitizer->sanitized_url);
  free(sanitizer);

  return 0;
}