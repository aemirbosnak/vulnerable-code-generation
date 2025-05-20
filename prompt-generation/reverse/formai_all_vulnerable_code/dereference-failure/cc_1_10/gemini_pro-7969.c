//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Declare a string
  char str[] = "Hello, world!";

  // Print the original string
  printf("Original string: %s\n", str);

  // Reverse the string
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }

  // Print the reversed string
  printf("Reversed string: %s\n", str);

  // Convert the string to uppercase
  for (int i = 0; i < len; i++) {
    str[i] = toupper(str[i]);
  }

  // Print the uppercase string
  printf("Uppercase string: %s\n", str);

  // Convert the string to lowercase
  for (int i = 0; i < len; i++) {
    str[i] = tolower(str[i]);
  }

  // Print the lowercase string
  printf("Lowercase string: %s\n", str);

  // Remove all spaces from the string
  char *newStr = malloc(len);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ') {
      newStr[j++] = str[i];
    }
  }
  newStr[j] = '\0';

  // Print the string with no spaces
  printf("String with no spaces: %s\n", newStr);

  // Free the allocated memory
  free(newStr);

  return 0;
}