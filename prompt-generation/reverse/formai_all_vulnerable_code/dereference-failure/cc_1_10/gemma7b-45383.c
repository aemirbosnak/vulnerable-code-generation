//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_URL_LEN 255

int sanitize_url(char *url) {
  char *p = url;
  char *q = url;
  int len = 0;

  // Strip leading and trailing spaces
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
  for (p = q; *p; p++) {
    if (!isalnum(*p) && *p != '-' && *p != '_') {
      *p = '\0';
    }
  }

  // Normalize special characters
  while (*p) {
    switch (*p) {
      case '.':
        if (*(p-1) != '/' && *(p+1) != '/') {
          *p = '_';
        }
        break;
      case '/':
        if (*(p-1) == '/') {
          *p = '\0';
        }
        break;
      case '?':
        if (*(p+1) == '=') {
          *p = '&';
        }
        break;
    }
    p++;
  }

  // Calculate the length of the sanitized URL
  len = p - q;

  // Return the sanitized URL
  return len;
}

int main() {
  char url[MAX_URL_LEN] = "   abc!@#$%^&*()_+-=\\n";
  int len = sanitize_url(url);

  printf("Sanitized URL: %s\n", url);
  printf("Length of sanitized URL: %d\n", len);

  return 0;
}