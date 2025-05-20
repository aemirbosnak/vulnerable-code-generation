//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void sanitize_user_input(char *buffer) {
  char *p = buffer;
  char *end = buffer + MAX_BUFFER_SIZE;

  // Remove all leading and trailing whitespace
  while (p < end && *p == ' ') {
    *p++ = '\0';
  }

  // Convert all non-alphanumeric characters to ASCII code 0
  while (p < end && !isalnum(*p)) {
    *p++ = '\0';
  }

  // Normalize case
  char *lower = malloc(MAX_BUFFER_SIZE);
  strcpy(lower, buffer);
  free(buffer);
  buffer = lower;

  // Convert all uppercase letters to lowercase
  for (p = buffer; p < end; p++) {
    if (isupper(*p)) {
      *p = tolower(*p);
    }
  }

  // Remove all duplicated characters
  p = buffer;
  char last_char = '\0';
  while (p < end) {
    if (*p == last_char) {
      *p = '\0';
    } else {
      last_char = *p;
    }
    p++;
  }

  return;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];

  printf("Enter a message: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  sanitize_user_input(buffer);

  printf("Sanitized message: %s\n", buffer);

  return 0;
}