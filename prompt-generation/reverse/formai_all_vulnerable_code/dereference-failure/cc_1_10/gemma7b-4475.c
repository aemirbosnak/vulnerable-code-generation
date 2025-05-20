//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 255

int sanitize_url(char *url) {
  int i, length, valid = 1;
  char *new_url = NULL;

  length = strlen(url);

  if (length > MAX_URL_LENGTH) {
    valid = 0;
  }

  new_url = malloc(length + 1);

  if (new_url == NULL) {
    valid = 0;
  }

  for (i = 0; i < length; i++) {
    if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z')) {
      new_url[i] = url[i];
    } else if (url[i] == '.' || url[i] == '/' || url[i] == '-') {
      new_url[i] = url[i];
    } else {
      valid = 0;
    }
  }

  new_url[length] = '\0';

  if (valid) {
    return strcpy(url, new_url);
  } else {
    return -1;
  }
}

int main() {
  char url[MAX_URL_LENGTH] = "This is an example URL with special characters!";

  if (sanitize_url(url) == -1) {
    printf("Error sanitizing URL.\n");
  } else {
    printf("Sanitized URL: %s\n", url);
  }

  return 0;
}