//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: light-weight
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

char sanitize_url(char *url) {
  char *p = url;
  char *q = NULL;
  char *r = NULL;
  int i = 0;
  int length = 0;

  // Calculate the length of the URL
  for (i = 0; p[i] != '\0'; i++) {
    length++;
  }

  // Allocate memory for the sanitized URL
  r = malloc(length + 1);

  // Copy the original URL to the sanitized URL
  for (i = 0; p[i] != '\0'; i++) {
    r[i] = p[i];
  }

  // Remove all special characters
  for (p = r; *p != '\0'; p++) {
    if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z') || (*p >= '0' && *p <= '9') || (*p == '_') || (*p == '-') || (*p == '.')) {
      *p = '_';
    }
  }

  // Remove all consecutive special characters
  for (p = r; *p != '\0'; p++) {
    if (*p == '_') {
      if (q && *(q - 1) == '_') {
        *p = '\0';
      } else {
        q = p;
      }
    }
  }

  // Return the sanitized URL
  return r;
}

int main() {
  char *url = "This is a URL with special characters!$$%^&*()";
  char *sanitized_url = sanitize_url(url);

  printf("Original URL: %s\n", url);
  printf("Sanitized URL: %s\n", sanitized_url);

  free(sanitized_url);

  return 0;
}