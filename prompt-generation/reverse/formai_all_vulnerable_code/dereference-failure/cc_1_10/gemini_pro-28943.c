//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <string.h>

int main() {
  // Declare and initialize a string.
  char str1[] = "Hello, world!";

  // Print the length of the string.
  printf("The length of the string is: %d\n", strlen(str1));

  // Print the string in reverse order.
  for (int i = strlen(str1) - 1; i >= 0; i--) {
    printf("%c", str1[i]);
  }
  printf("\n");

  // Convert the string to uppercase.
  for (int i = 0; i < strlen(str1); i++) {
    str1[i] = toupper(str1[i]);
  }
  printf("The string in uppercase is: %s\n", str1);

  // Convert the string to lowercase.
  for (int i = 0; i < strlen(str1); i++) {
    str1[i] = tolower(str1[i]);
  }
  printf("The string in lowercase is: %s\n", str1);

  // Find the first occurrence of a character in the string.
  char ch = 'l';
  int index = strchr(str1, ch) - str1;
  printf("The first occurrence of '%c' in the string is at index: %d\n", ch, index);

  // Find the last occurrence of a character in the string.
  index = strrchr(str1, ch) - str1;
  printf("The last occurrence of '%c' in the string is at index: %d\n", ch, index);

  // Find the first occurrence of a substring in the string.
  char *substr = "world";
  char *ptr = strstr(str1, substr);
  if (ptr != NULL) {
    printf("The substring '%s' was found in the string at index: %d\n", substr, ptr - str1);
  } else {
    printf("The substring '%s' was not found in the string.\n", substr);
  }

  // Find the last occurrence of a substring in the string.
  ptr = strstr(str1, substr);
  while (ptr != NULL) {
    printf("The substring '%s' was found in the string at index: %d\n", substr, ptr - str1);
    ptr = strstr(ptr + 1, substr);
  }

  // Concatenate two strings.
  char str2[] = "Goodbye, world!";
  char str3[strlen(str1) + strlen(str2) + 1];
  strcpy(str3, str1);
  strcat(str3, " ");
  strcat(str3, str2);
  printf("The concatenated string is: %s\n", str3);

  // Compare two strings.
  int result = strcmp(str1, str2);
  if (result == 0) {
    printf("The two strings are equal.\n");
  } else if (result < 0) {
    printf("The first string is less than the second string.\n");
  } else {
    printf("The first string is greater than the second string.\n");
  }

  // Copy a string.
  char str4[strlen(str1) + 1];
  strcpy(str4, str1);
  printf("The copied string is: %s\n", str4);

  // Move a string.
  memmove(str4, str4 + 1, strlen(str4));
  printf("The moved string is: %s\n", str4);

  // Set a string to a specified value.
  memset(str4, 'x', strlen(str4));
  printf("The set string is: %s\n", str4);

  return 0;
}