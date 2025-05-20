//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url) {
  char *p = url;
  char *q = url;

  // Remove leading and trailing spaces
  while (isspace(*p)) {
    p++;
  }

  // Normalize case
  for (q = p; *q; q++) {
    *q = tolower(*q);
  }

  // Remove invalid characters
  for (p = q; *p; p++) {
    if (!isalnum(*p) && *p != '-' && *p != '_') {
      *p = '_';
    }
  }

  // Remove consecutive underscores
  while (q - p >= 0 && *(q - 1) == '_') {
    *(q - 1) = '_';
    q--;
  }

  // Trim trailing spaces
  while (isspace(*p)) {
    p--;
  }

  // Null-terminate the sanitized URL
  *p = '\0';
}

int main() {
  char url[MAX_URL_LENGTH];

  printf("Enter a URL: ");
  fgets(url, MAX_URL_LENGTH, stdin);

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}