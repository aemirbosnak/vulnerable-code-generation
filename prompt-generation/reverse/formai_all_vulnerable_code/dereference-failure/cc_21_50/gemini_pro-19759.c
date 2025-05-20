//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *s = "Hello, world!";
  int i, j, k;

  // Print the string in reverse order
  for (i = strlen(s) - 1; i >= 0; i--) {
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string in alternating upper and lower case
  for (i = 0, j = 1; s[i] != '\0'; i++, j++) {
    if (j % 2 == 0) {
      putchar(toupper(s[i]));
    } else {
      putchar(tolower(s[i]));
    }
  }
  putchar('\n');

  // Print the string with every other character removed
  for (i = 0; s[i] != '\0'; i += 2) {
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all repeated characters removed
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i + 1; s[j] != '\0'; j++) {
      if (s[i] == s[j]) {
        break;
      }
    }
    if (s[j] == '\0') {
      putchar(s[i]);
    }
  }
  putchar('\n');

  // Print the string with all vowels removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all consonants removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
      putchar(s[i]);
    }
  }
  putchar('\n');

  // Print the string with all numbers removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all punctuation removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == '.' || s[i] == ',' || s[i] == '!' || s[i] == '?' || s[i] == ';' || s[i] == ':') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all whitespace removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all uppercase characters removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  // Print the string with all lowercase characters removed
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      continue;
    }
    putchar(s[i]);
  }
  putchar('\n');

  return 0;
}