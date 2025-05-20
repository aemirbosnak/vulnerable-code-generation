//GEMINI-pro DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 1024

int main(int argc, char **argv) {
  char *url;
  char *sanitized_url;
  int url_len;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  url = argv[1];
  url_len = strlen(url);

  if (url_len > MAX_URL_LEN) {
    fprintf(stderr, "URL too long: %s\n", url);
    exit(EXIT_FAILURE);
  }

  sanitized_url = malloc(url_len + 1);
  if (sanitized_url == NULL) {
    fprintf(stderr, "malloc failed\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < url_len; i++) {
    char c = url[i];
    if (c == '%') {
      if (i + 2 < url_len) {
        char hex1 = url[i + 1];
        char hex2 = url[i + 2];
        int value;
        if (sscanf(&hex1, "%x", &value) != 1 || sscanf(&hex2, "%x", &value) != 1) {
          fprintf(stderr, "Invalid URL: %s\n", url);
          exit(EXIT_FAILURE);
        }
        sanitized_url[i] = (char)value;
        i += 2;
      } else {
        fprintf(stderr, "Invalid URL: %s\n", url);
        exit(EXIT_FAILURE);
      }
    } else {
      sanitized_url[i] = c;
    }
  }

  sanitized_url[url_len] = '\0';

  printf("%s\n", sanitized_url);

  free(sanitized_url);

  return EXIT_SUCCESS;
}