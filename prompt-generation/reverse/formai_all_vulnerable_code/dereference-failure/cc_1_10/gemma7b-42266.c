//Gemma-7B DATASET v1.0 Category: User Input Sanitizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

char* sanitize_user_input(char* str) {
  // Remove all non-ASCII characters.
  char* ptr = str;
  while (*ptr) {
    if (!isascii(*ptr)) {
      *ptr = '\0';
    } else {
      ptr++;
    }
  }

  // Normalize whitespace.
  ptr = str;
  while (*ptr) {
    if (*ptr == ' ') {
      while (*(ptr - 1) == ' ') {
        *ptr = '\0';
      }
    } else {
      ptr++;
    }
  }

  // Lowercase all letters.
  ptr = str;
  while (*ptr) {
    if (isupper(*ptr)) {
      *ptr = tolower(*ptr);
    } else {
      ptr++;
    }
  }

  return str;
}

int main() {
  char* str = "This is a string with non-ASCII characters, lots of whitespace, and UPPERCASE letters.";

  str = sanitize_user_input(str);

  printf("Sanitized string: %s", str);

  return 0;
}