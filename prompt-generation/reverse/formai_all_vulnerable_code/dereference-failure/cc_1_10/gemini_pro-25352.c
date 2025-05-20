//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main() {
  // Declare a string
  char str[] = "Hello World!";

  // Print the original string
  printf("Original string: %s\n", str);

  // Get the length of the string
  int len = strlen(str);

  // Reverse the string
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

  // Find the first occurrence of a character in the string
  char ch = 'W';
  int index = strchr(str, ch) - str;

  // Print the index of the first occurrence of the character
  printf("Index of the first occurrence of '%c': %d\n", ch, index);

  // Find the last occurrence of a character in the string
  index = strrchr(str, ch) - str;

  // Print the index of the last occurrence of the character
  printf("Index of the last occurrence of '%c': %d\n", ch, index);

  // Find the first occurrence of a substring in the string
  char substr[] = "World";
  char *ptr = strstr(str, substr);

  // Print the pointer to the first occurrence of the substring
  printf("Pointer to the first occurrence of '%s': %p\n", substr, ptr);

  // Find the last occurrence of a substring in the string
  ptr = strstr(str, substr);
  while (*ptr) {
    ptr++;
  }
  ptr--;

  // Print the pointer to the last occurrence of the substring
  printf("Pointer to the last occurrence of '%s': %p\n", substr, ptr);

  // Copy a substring from the string
  char newstr[len];
  strncpy(newstr, str + index, len - index);

  // Print the copied substring
  printf("Copied substring: %s\n", newstr);

  // Concatenate two strings
  char str2[] = "Goodbye World!";
  strcat(str, str2);

  // Print the concatenated string
  printf("Concatenated string: %s\n", str);

  // Compare two strings
  int result = strcmp(str, str2);

  // Print the result of the comparison
  if (result == 0) {
    printf("Strings are equal\n");
  } else if (result < 0) {
    printf("String '%s' is less than string '%s'\n", str, str2);
  } else {
    printf("String '%s' is greater than string '%s'\n", str, str2);
  }

  return 0;
}