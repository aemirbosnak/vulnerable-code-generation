//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url) {
  char *p = url;
  char *q = url;
  int i = 0;

  // Strip leading and trailing spaces
  while (*p && isspace(*p)) {
    p++;
  }
  while (*q && isspace(*q)) {
    q--;
  }

  // Remove unnecessary characters
  while (*p) {
    if (!isalnum(*p) && *p != '-' && *p != '_') {
      p++;
    } else {
      *q = *p;
      q++;
    }
  }

  // Normalize case
  for (i = 0; i < strlen(url); i++) {
    if (islower(url[i])) {
      url[i] = toupper(url[i]);
    }
  }

  // Ensure valid length
  if (strlen(url) > MAX_URL_LENGTH) {
    url[MAX_URL_LENGTH - 1] = '\0';
  }
}

int main() {
  char url[MAX_URL_LENGTH] = "This is a sample url with special characters!?!?!";

  sanitize_url(url);

  printf("Sanitized URL: %s\n", url);

  return 0;
}