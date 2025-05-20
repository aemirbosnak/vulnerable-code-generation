//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char str[] = "Hello, world!";

  // Print the original string.
  printf("Original string: %s\n", str);

  // Reverse the string.
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  // Print the reversed string.
  printf("Reversed string: %s\n", str);

  // Convert the string to uppercase.
  for (int i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }

  // Print the uppercase string.
  printf("Uppercase string: %s\n", str);

  // Convert the string to lowercase.
  for (int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  // Print the lowercase string.
  printf("Lowercase string: %s\n", str);

  // Remove all spaces from the string.
  char *new_str = malloc(len - count_spaces(str) + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ') {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';

  // Print the string with spaces removed.
  printf("String with spaces removed: %s\n", new_str);

  // Free the allocated memory.
  free(new_str);

  return 0;
}

int count_spaces(char *str) {
  int count = 0;
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == ' ') {
      count++;
    }
  }
  return count;
}