//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *s = "Hello, world!";
  int i, j, k;

  // Reverse the string
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    char c = s[i];
    s[i] = s[j];
    s[j] = c;
  }

  // Print the reversed string
  printf("%s\n", s);

  // Convert the string to uppercase
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] -= 32;
    }
  }

  // Print the uppercase string
  printf("%s\n", s);

  // Convert the string to lowercase
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] += 32;
    }
  }

  // Print the lowercase string
  printf("%s\n", s);

  // Remove all spaces from the string
  for (i = 0, j = 0; s[i] != '\0'; i++) {
    if (s[i] != ' ') {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';

  // Print the string without spaces
  printf("%s\n", s);

  // Remove all vowels from the string
  for (i = 0, j = 0; s[i] != '\0'; i++) {
    if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') {
      s[j++] = s[i];
    }
  }
  s[j] = '\0';

  // Print the string without vowels
  printf("%s\n", s);

  // Replace all spaces with underscores
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ' ') {
      s[i] = '_';
    }
  }

  // Print the string with underscores
  printf("%s\n", s);

  // Replace all commas with semicolons
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == ',') {
      s[i] = ';';
    }
  }

  // Print the string with semicolons
  printf("%s\n", s);

  // Replace all periods with exclamation marks
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == '.') {
      s[i] = '!';
    }
  }

  // Print the string with exclamation marks
  printf("%s\n", s);

  return 0;
}