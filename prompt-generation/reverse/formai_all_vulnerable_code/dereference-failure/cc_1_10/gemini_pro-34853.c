//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style C string manipulation example program

// This program demonstrates some of the string manipulation functions
// available in the C standard library.

int main(int argc, char *argv[])
{
  // Declare a string variable.
  char *str = "Hello, world!";

  // Print the string.
  printf("The string is: %s\n", str);

  // Get the length of the string.
  int len = strlen(str);

  // Print the length of the string.
  printf("The length of the string is: %d\n", len);

  // Copy the string to a new variable.
  char *new_str = strdup(str);

  // Print the new string.
  printf("The new string is: %s\n", new_str);

  // Concatenate two strings.
  char *concat_str = strcat(str, "!");

  // Print the concatenated string.
  printf("The concatenated string is: %s\n", concat_str);

  // Compare two strings.
  int cmp = strcmp(str, "Hello, world!");

  // Print the result of the comparison.
  printf("The result of the comparison is: %d\n", cmp);

  // Find the first occurrence of a character in a string.
  char *find_char = strchr(str, 'w');

  // Print the position of the first occurrence of the character.
  printf("The position of the first occurrence of the character is: %d\n", find_char - str);

  // Find the last occurrence of a character in a string.
  char *find_last_char = strrchr(str, 'l');

  // Print the position of the last occurrence of the character.
  printf("The position of the last occurrence of the character is: %d\n", find_last_char - str);

  // Return 0 to indicate success.
  return 0;
}