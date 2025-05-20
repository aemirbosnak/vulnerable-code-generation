//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char str1[] = "Hello, world!";
  char str2[] = "How are you?";
  char str3[100];

  // Concatenate str1 and str2
  strcat(str1, " ");
  strcat(str1, str2);

  // Copy str1 to str3
  strcpy(str3, str1);

  // Print the concatenated string
  printf("Concatenated string: %s\n", str1);

  // Print the copied string
  printf("Copied string: %s\n", str3);

  // Reverse the order of the characters in str1
  int len = strlen(str1);
  for (int i = 0; i < len / 2; i++) {
    char temp = str1[i];
    str1[i] = str1[len - i - 1];
    str1[len - i - 1] = temp;
  }

  // Print the reversed string
  printf("Reversed string: %s\n", str1);

  // Find the first occurrence of the letter 'a' in str1
  char *ptr = strchr(str1, 'a');

  // Print the position of the first occurrence of the letter 'a'
  if (ptr != NULL) {
    printf("First occurrence of the letter 'a': %ld\n", ptr - str1);
  } else {
    printf("Letter 'a' not found\n");
  }

  // Convert str1 to uppercase
  for (int i = 0; i < len; i++) {
    str1[i] = toupper(str1[i]);
  }

  // Print the uppercase string
  printf("Uppercase string: %s\n", str1);

  // Convert str1 to lowercase
  for (int i = 0; i < len; i++) {
    str1[i] = tolower(str1[i]);
  }

  // Print the lowercase string
  printf("Lowercase string: %s\n", str1);

  return 0;
}