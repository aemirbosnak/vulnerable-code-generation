//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
  int len = strlen(str);
  char *reversed = malloc(len + 1);
  int i;
  for (i = 0; i < len; i++) {
    reversed[i] = str[len - i - 1];
  }
  reversed[len] = '\0';
  return reversed;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);
  int i;
  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to count the number of occurrences of a character in a string
int count_char(char *str, char c) {
  int count = 0;
  int len = strlen(str);
  int i;
  for (i = 0; i < len; i++) {
    if (str[i] == c) {
      count++;
    }
  }
  return count;
}

// Function to remove all occurrences of a character from a string
char *remove_char(char *str, char c) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  int i, j;
  j = 0;
  for (i = 0; i < len; i++) {
    if (str[i] != c) {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to replace all occurrences of a character with another character in a string
char *replace_char(char *str, char c1, char c2) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  int i;
  for (i = 0; i < len; i++) {
    if (str[i] == c1) {
      new_str[i] = c2;
    } else {
      new_str[i] = str[i];
    }
  }
  new_str[len] = '\0';
  return new_str;
}

int main() {
  char *str = "Hello, world!";

  // Reverse the string
  char *reversed = reverse(str);
  printf("Reversed: %s\n", reversed);

  // Check if the string is a palindrome
  int is_palindrome_result = is_palindrome(str);
  printf("Is palindrome: %d\n", is_palindrome_result);

  // Count the number of occurrences of a character
  int count_char_result = count_char(str, 'l');
  printf("Count of 'l': %d\n", count_char_result);

  // Remove all occurrences of a character
  char *removed_char = remove_char(str, 'l');
  printf("Removed 'l': %s\n", removed_char);

  // Replace all occurrences of a character with another character
  char *replaced_char = replace_char(str, 'l', 'x');
  printf("Replaced 'l' with 'x': %s\n", replaced_char);

  return 0;
}