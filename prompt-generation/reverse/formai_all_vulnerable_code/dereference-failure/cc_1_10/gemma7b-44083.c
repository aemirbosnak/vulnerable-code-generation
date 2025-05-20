//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 255

void sanitize_url(char *url) {
  char *p = url;
  char *q = url;

  // Remove leading and trailing spaces
  while (isspace(*p)) {
    p++;
  }
  while (isspace(*(q - 1))) {
    *(q - 1) = '\0';
  }

  // Normalize case
  for (p = url; *p; p++) {
    *p = tolower(*p);
  }

  // Remove invalid characters
  for (p = url; *p; p++) {
    if (!isalnum(*p) && *p != '-' && *p != '_') {
      *p = '\0';
    }
  }

  // Remove repeated characters
  char prev = '\0';
  for (p = url; *p; p++) {
    if (*p == prev) {
      *p = '\0';
    }
    prev = *p;
  }

  // Return sanitized URL
  return;
}

int main() {
  char url[MAX_URL_LEN] = "This is a sample URL with lots of special characters!?!?";

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}