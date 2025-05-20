//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverseString(char *str) {
  int len = strlen(str);
  char *reversed = malloc(len + 1);
  int j = 0;
  for (int i = len - 1; i >= 0; i--) {
    reversed[j++] = str[i];
  }
  reversed[j] = '\0';
  return reversed;
}

// Function to check if a string is a palindrome
int isPalindrome(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Function to find the longest palindrome in a string
char *longestPalindrome(char *str) {
  int len = strlen(str);
  int maxLen = 0;
  char *longest = NULL;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j <= len; j++) {
      char *substring = strndup(str + i, j - i);
      if (isPalindrome(substring) && strlen(substring) > maxLen) {
        maxLen = strlen(substring);
        longest = substring;
      }
      free(substring);
    }
  }
  return longest;
}

// Function to find the shortest palindrome that can be formed by adding characters to the end of a string
char *shortestPalindrome(char *str) {
  int len = strlen(str);
  int i = 0;
  while (i < len / 2) {
    if (str[i] != str[len - i - 1]) {
      break;
    }
    i++;
  }
  if (i == len / 2) {
    return str;
  }
  char *reversed = reverseString(str + i);
  char *newStr = malloc(len + len - i + 1);
  strcpy(newStr, str);
  strcat(newStr, reversed);
  free(reversed);
  return newStr;
}

int main() {
  char *str1 = "Racecar";
  char *str2 = "anna";
  char *str3 = "banana";
  
  printf("Original String: %s\n", str1);
  printf("Reversed String: %s\n", reverseString(str1));
  printf("Is Palindrome: %d\n", isPalindrome(str1));
  
  printf("\nOriginal String: %s\n", str2);
  printf("Reversed String: %s\n", reverseString(str2));
  printf("Is Palindrome: %d\n", isPalindrome(str2));
  
  printf("\nOriginal String: %s\n", str3);
  printf("Reversed String: %s\n", reverseString(str3));
  printf("Is Palindrome: %d\n", isPalindrome(str3));
  
  printf("\nOriginal String: %s\n", str3);
  printf("Longest Palindrome: %s\n", longestPalindrome(str3));
  
  printf("\nOriginal String: %s\n", str3);
  printf("Shortest Palindrome: %s\n", shortestPalindrome(str3));
  
  return 0;
}