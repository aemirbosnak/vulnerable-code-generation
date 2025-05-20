//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
  int len = strlen(str);
  char *reversedString = (char *)malloc(len + 1);
  int i;
  for (i = 0; i < len; i++) {
    reversedString[len - i - 1] = str[i];
  }
  reversedString[len] = '\0';
  return reversedString;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);
  int i;
  for (i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest substring without repeating characters
char *longestSubstringWithoutRepeatingCharacters(char *str) {
  int len = strlen(str);
  int i, j, maxLen = 0, start = 0, end = 0;
  int charMap[256] = {0};
  for (i = 0; i < len; i++) {
    if (charMap[str[i]] == 0) {
      charMap[str[i]] = 1;
      if (i - start + 1 > maxLen) {
        maxLen = i - start + 1;
        end = i;
      }
    } else {
      while (charMap[str[i]] != 0) {
        charMap[str[start]] = 0;
        start++;
      }
      charMap[str[i]] = 1;
    }
  }
  char *substring = (char *)malloc(maxLen + 1);
  for (i = start; i <= end; i++) {
    substring[i - start] = str[i];
  }
  substring[maxLen] = '\0';
  return substring;
}

// Function to find the first non-repeating character in a string
char firstNonRepeatingCharacter(char *str) {
  int len = strlen(str);
  int charMap[256] = {0};
  int i;
  for (i = 0; i < len; i++) {
    charMap[str[i]]++;
  }
  for (i = 0; i < len; i++) {
    if (charMap[str[i]] == 1) {
      return str[i];
    }
  }
  return '\0';
}

// Function to find the longest palindromic substring in a string
char *longestPalindromicSubstring(char *str) {
  int len = strlen(str);
  int maxLen = 0, start = 0, end = 0;
  int i, j, k;
  for (i = 0; i < len; i++) {
    for (j = i + 1; j < len; j++) {
      if (str[i] == str[j]) {
        for (k = 0; k <= (j - i) / 2; k++) {
          if (str[i + k] != str[j - k]) {
            break;
          }
        }
        if (k > maxLen) {
          maxLen = k;
          start = i;
          end = j;
        }
      }
    }
  }
  char *substring = (char *)malloc(maxLen + 1);
  for (i = start; i <= end; i++) {
    substring[i - start] = str[i];
  }
  substring[maxLen] = '\0';
  return substring;
}

int main() {
  char str[] = "Hello world";
  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", reverseString(str));
  if (isPalindrome(str)) {
    printf("The string is a palindrome\n");
  } else {
    printf("The string is not a palindrome\n");
  }
  printf("Longest substring without repeating characters: %s\n", longestSubstringWithoutRepeatingCharacters(str));
  printf("First non-repeating character: %c\n", firstNonRepeatingCharacter(str));
  printf("Longest palindromic substring: %s\n", longestPalindromicSubstring(str));
  return 0;
}