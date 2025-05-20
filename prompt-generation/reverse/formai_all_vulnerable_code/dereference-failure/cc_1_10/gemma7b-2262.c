//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

void sanitize_url(char *url) {
  char *p = url;
  char *q = url;

  // Remove leading and trailing spaces
  while (*p && isspace(*p)) {
    p++;
  }
  while (*q && isspace(*q)) {
    q--;
  }

  // Convert to lowercase
  for (p = q; *p; p++) {
    *p = tolower(*p);
  }

  // Remove invalid characters
  p = q;
  while (*p) {
    if (!isalnum(*p) && *p != '-' && *p != '_') {
      *p = '\0';
    } else {
      p++;
    }
  }

  // Remove duplicate slashes
  p = q;
  while (*p && *(p + 1) && *p == '/' && *(p + 1) == '/') {
    p++;
  }

  // Return sanitized URL
  strcpy(url, q);
}

int main() {
  char url[MAX_URL_LENGTH] = "   /a/b c/ d?q=r&s=t#f";

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}