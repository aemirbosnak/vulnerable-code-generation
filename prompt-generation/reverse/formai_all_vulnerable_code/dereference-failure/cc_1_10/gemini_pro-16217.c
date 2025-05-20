//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

char *sanitize_url(char *url) {
  char *sanitized_url = malloc(BUFFER_SIZE);
  char *ptr = url;
  int i = 0;

  while (*ptr != '\0') {
    if (*ptr == ' ') {
      sanitized_url[i++] = '+';
    } else if (*ptr == '%') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '2';
      sanitized_url[i++] = '5';
    } else if (*ptr == '&') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '2';
      sanitized_url[i++] = '6';
    } else if (*ptr == '\'') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '2';
      sanitized_url[i++] = '7';
    } else if (*ptr == '"') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '2';
      sanitized_url[i++] = '2';
    } else if (*ptr == '=') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '3';
      sanitized_url[i++] = 'D';
    } else if (*ptr == '?') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '3';
      sanitized_url[i++] = 'F';
    } else if (*ptr == '#') {
      sanitized_url[i++] = '%';
      sanitized_url[i++] = '2';
      sanitized_url[i++] = '3';
    } else {
      sanitized_url[i++] = *ptr;
    }

    ptr++;
  }

  sanitized_url[i] = '\0';
  return sanitized_url;
}

int main() {
  char *url = "https://www.example.com/path/to/page?query=string#fragment";
  char *sanitized_url = sanitize_url(url);

  printf("Original URL: %s\n", url);
  printf("Sanitized URL: %s\n", sanitized_url);

  free(sanitized_url);
  return 0;
}