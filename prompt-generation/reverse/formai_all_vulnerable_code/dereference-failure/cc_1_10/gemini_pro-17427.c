//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/* The following function sanitizes a URL by removing any potentially dangerous characters. */
char *sanitize_url(const char *url) {
  char *sanitized_url = malloc(strlen(url) + 1);
  if (sanitized_url == NULL) {
    return NULL;
  }

  char *dest = sanitized_url;
  const char *src = url;

  while (*src != '\0') {
    switch (*src) {
      case '<':
        *dest++ = '&';
        *dest++ = 'l';
        *dest++ = 't';
        *dest++ = ';';
        break;
      case '>':
        *dest++ = '&';
        *dest++ = 'g';
        *dest++ = 't';
        *dest++ = ';';
        break;
      case '&':
        *dest++ = '&';
        *dest++ = 'a';
        *dest++ = 'm';
        *dest++ = 'p';
        *dest++ = ';';
        break;
      case '"':
        *dest++ = '&';
        *dest++ = 'q';
        *dest++ = 'u';
        *dest++ = 'o';
        *dest++ = 't';
        *dest++ = ';';
        break;
      default:
        *dest++ = *src;
        break;
    }

    src++;
  }

  *dest = '\0';

  return sanitized_url;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *sanitized_url = sanitize_url(argv[1]);
  if (sanitized_url == NULL) {
    fprintf(stderr, "Error: Could not sanitize URL.\n");
    return EXIT_FAILURE;
  }

  printf("Sanitized URL: %s\n", sanitized_url);

  free(sanitized_url);

  return EXIT_SUCCESS;
}