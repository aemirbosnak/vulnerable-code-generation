//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

void sanitize_user_input(char *buffer) {
  // Remove all non-ASCII characters
  char *p = buffer;
  while (*p) {
    if (*p < 32 || *p > 126) {
      *p = '\0';
    }
    p++;
  }

  // Normalize whitespace
  char *q = buffer;
  char *r = buffer;
  while (*q) {
    if (*q == ' ' && *(q - 1) == ' ') {
      *q = '\0';
    } else {
      *r = *q;
      r++;
    }
    q++;
  }

  // Trim leading and trailing whitespace
  while (buffer[0] == ' ' && buffer[0] != '\0') {
    memmove(buffer, buffer + 1, strlen(buffer) - 1);
  }
  while (buffer[strlen(buffer) - 1] == ' ' && buffer[strlen(buffer) - 1] != '\0') {
    buffer[strlen(buffer) - 1] = '\0';
  }

  // Return the sanitized buffer
  return;
}

int main() {
  char buffer[MAX_BUFFER_SIZE];

  // Get user input
  printf("Enter a string: ");
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  // Sanitize the user input
  sanitize_user_input(buffer);

  // Print the sanitized string
  printf("Sanitized string: %s", buffer);

  return 0;
}