//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 256

void sanitize_url(char *url) {
  char *p = url;
  char *start = NULL;
  char *end = NULL;

  // Strip leading and trailing spaces
  while (*p && isspace(*p)) {
    p++;
  }

  // Find the start of the valid URL
  while (*p && !isspace(*p)) {
    start = p;
    p++;
  }

  // Find the end of the valid URL
  end = strchr(start, ';');
  if (end) {
    end = strchr(start, '?');
    if (end) {
      end = NULL;
    }
  }

  // Replace invalid characters with underscores
  while (start && *start) {
    if (!isalnum(*start) && *start != '-') {
      *start = '_';
    }
    start++;
  }

  // Copy the sanitized URL to the original buffer
  if (start) {
    memcpy(url, start, end - start);
  }
}

int main() {
  char url[MAX_URL_LENGTH] = "This is an example URL with some invalid characters!#";
  sanitize_url(url);
  printf("%s\n", url);

  return 0;
}