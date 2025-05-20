//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
  int i, j;
  char temp;
  for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
  return str;
}

// Function to check if a string is a palindrome
int is_palindrome(char *str) {
  char *reversed = reverse(str);
  int palindrome = !strcmp(str, reversed);
  free(reversed);
  return palindrome;
}

// Function to find the longest palindrome in a string
char *longest_palindrome(char *str) {
  int i, j, k, l, max_length = 1, start = 0;
  for (i = 0; str[i]; i++) {
    for (j = i + 1; str[j]; j++) {
      for (k = i, l = j; str[k] == str[l] && k < l; k++, l--)
        ;
      if (k >= l && j - i + 1 > max_length) {
        max_length = j - i + 1;
        start = i;
      }
    }
  }
  char *longest = malloc(max_length + 1);
  strncpy(longest, str + start, max_length);
  longest[max_length] = '\0';
  return longest;
}

// Function to test the string manipulation functions
int main() {
  char *str = "abracadabra";
  printf("Original string: %s\n", str);
  printf("Reversed string: %s\n", reverse(str));
  printf("Is the string a palindrome? %d\n", is_palindrome(str));
  char *longest = longest_palindrome(str);
  printf("Longest palindrome in the string: %s\n", longest);
  free(longest);
  return 0;
}