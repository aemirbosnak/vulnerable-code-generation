//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
  int len = strlen(str);
  char *rev = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    rev[len - i - 1] = str[i];
  }
  rev[len] = '\0';
  return rev;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest substring that is a palindrome
char *longest_palindrome(char *str) {
  int len = strlen(str);
  int max_len = 0;
  int start = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (is_palindrome(str + i) && j - i + 1 > max_len) {
        max_len = j - i + 1;
        start = i;
      }
    }
  }
  char *longest = malloc(max_len + 1);
  strncpy(longest, str + start, max_len);
  longest[max_len] = '\0';
  return longest;
}

// Function to find the longest common substring of two strings
char *longest_common_substring(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int max_len = 0;
  int start = 0;
  for (int i = 0; i < len1; i++) {
    for (int j = 0; j < len2; j++) {
      int k = 0;
      while (str1[i + k] == str2[j + k] && i + k < len1 && j + k < len2) {
        k++;
      }
      if (k > max_len) {
        max_len = k;
        start = i;
      }
    }
  }
  char *longest = malloc(max_len + 1);
  strncpy(longest, str1 + start, max_len);
  longest[max_len] = '\0';
  return longest;
}

// Function to find the longest repeating substring of a string
char *longest_repeating_substring(char *str) {
  int len = strlen(str);
  int max_len = 0;
  int start = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      int k = 0;
      while (str[i + k] == str[j + k] && i + k < len && j + k < len) {
        k++;
      }
      if (k > max_len) {
        max_len = k;
        start = i;
      }
    }
  }
  char *longest = malloc(max_len + 1);
  strncpy(longest, str + start, max_len);
  longest[max_len] = '\0';
  return longest;
}

int main() {
  char *str1 = "Hello";
  char *str2 = "World";

  printf("Reversed string: %s\n", reverse(str1));
  printf("Is palindrome: %d\n", is_palindrome(str1));
  printf("Longest palindrome: %s\n", longest_palindrome(str1));
  printf("Longest common substring: %s\n", longest_common_substring(str1, str2));
  printf("Longest repeating substring: %s\n", longest_repeating_substring(str1));

  return 0;
}