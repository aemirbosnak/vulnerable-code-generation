//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_url(char *url) {
  int length = strlen(url);
  int i;

  if (length <= 7 || strcmp(url + length - 4, ".com")!= 0) {
    return 0;
  }

  for (i = 0; i < length - 4; i++) {
    if (!isalpha(url[i]) &&!isdigit(url[i]) && url[i]!= '-') {
      return 0;
    }
  }

  return 1;
}

char *sanitize_url(char *url) {
  int length = strlen(url);
  char *sanitized_url;
  int i;

  sanitized_url = malloc(length + 1);
  if (sanitized_url == NULL) {
    printf("Error: Could not allocate memory for sanitized URL.\n");
    exit(1);
  }

  for (i = 0; i < length; i++) {
    if (isalpha(url[i]) || isdigit(url[i]) || url[i] == '-') {
      sanitized_url[i] = url[i];
    } else {
      sanitized_url[i] = '-';
    }
  }

  sanitized_url[length] = '\0';
  return sanitized_url;
}

int main() {
  char url[100];
  char *sanitized_url;

  printf("Enter a URL to sanitize: ");
  scanf("%s", url);

  if (is_valid_url(url)) {
    sanitized_url = sanitize_url(url);
    printf("Sanitized URL: %s\n", sanitized_url);
  } else {
    printf("Invalid URL.\n");
  }

  free(sanitized_url);
  return 0;
}