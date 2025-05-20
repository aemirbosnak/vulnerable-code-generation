//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Reverse a string using recursion
char *reverse(char *str) {
  if (*str == '\0') {
    return str;
  } else {
    reverse(str + 1);
    char temp = *str;
    *str = *(str + 1);
    *(str + 1) = temp;
    return str;
  }
}

// Check if a string is a palindrome using recursion
int is_palindrome(char *str) {
  if (*str == '\0') {
    return 1;
  } else if (*str != *(str + strlen(str) - 1)) {
    return 0;
  } else {
    return is_palindrome(str + 1);
  }
}

// Find the longest common substring of two strings using dynamic programming
char *longest_common_substring(char *str1, char *str2) {
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int dp[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++) {
    for (int j = 0; j <= len2; j++) {
      dp[i][j] = 0;
    }
  }
  int max_len = 0;
  int end_index = 0;
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > max_len) {
          max_len = dp[i][j];
          end_index = i;
        }
      }
    }
  }
  char *lcs = malloc(max_len + 1);
  for (int i = end_index - max_len; i < end_index; i++) {
    lcs[i - (end_index - max_len)] = str1[i];
  }
  lcs[max_len] = '\0';
  return lcs;
}

int main() {
  // Reverse a string
  char str[] = "Hello, world!";
  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", reverse(str));

  // Check if a string is a palindrome
  char str2[] = "racecar";
  printf("Original string: %s\n", str2);
  printf("Is palindrome: %d\n", is_palindrome(str2));

  // Find the longest common substring of two strings
  char str3[] = "ABCDEFGHI";
  char str4[] = "BCDEFGHIJ";
  printf("Original strings: %s, %s\n", str3, str4);
  printf("Longest common substring: %s\n", longest_common_substring(str3, str4));

  return 0;
}