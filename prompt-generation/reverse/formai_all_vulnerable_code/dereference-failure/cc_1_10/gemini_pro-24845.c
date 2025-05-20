//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to swap two characters
void swap(char *a, char *b) {
  char temp = *a;
  *a = *b;
  *b = temp;
}

// Function to reverse a string in place
void reverse(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    swap(&str[i], &str[len - i - 1]);
  }
}

// Function to find the longest palindrome in a string
char *longestPalindrome(char *str) {
  int len = strlen(str);
  char *max_palindrome = NULL;
  int max_length = 0;

  // Iterate over all possible starting points
  for (int i = 0; i < len; i++) {
    // Iterate over all possible ending points
    for (int j = i + 1; j < len; j++) {
      // Check if the substring from i to j is a palindrome
      int is_palindrome = 1;
      for (int k = i; k <= (i + j) / 2; k++) {
        if (str[k] != str[i + j - k]) {
          is_palindrome = 0;
          break;
        }
      }

      // If the substring is a palindrome, update the max palindrome and max length
      if (is_palindrome && (j - i + 1) > max_length) {
        max_palindrome = &str[i];
        max_length = j - i + 1;
      }
    }
  }

  // Return the max palindrome
  char *result = malloc(max_length + 1);
  memcpy(result, max_palindrome, max_length);
  result[max_length] = '\0';
  return result;
}

int main() {
  // Array of test strings
  char *test_strings[] = {
    "kayak",
    "racecar",
    "level",
    "12321",
    "abccba",
    "a",
    "hello world"
  };

  // Iterate over the test strings and print the longest palindrome for each string
  for (int i = 0; i < 7; i++) {
    printf("Longest palindrome in \"%s\": %s\n", test_strings[i], longestPalindrome(test_strings[i]));
  }

  return 0;
}