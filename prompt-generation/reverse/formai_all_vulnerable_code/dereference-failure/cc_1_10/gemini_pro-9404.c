//GEMINI-pro DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to hold the palindrome
typedef struct palindrome {
  char *value;
  int length;
} palindrome;

// Create a function to check if a string is a palindrome
int is_palindrome(char *string) {
  int length = strlen(string);
  for (int i = 0; i < length / 2; i++) {
    if (string[i] != string[length - i - 1]) {
      return 0;
    }
  }
  return 1;
}

// Create a function to find the longest palindrome in a string
palindrome find_longest_palindrome(char *string) {
  int length = strlen(string);
  palindrome longest_palindrome = {NULL, 0};
  for (int i = 0; i < length; i++) {
    for (int j = i + 1; j <= length; j++) {
      char *substring = strndup(string + i, j - i);
      if (is_palindrome(substring) && j - i > longest_palindrome.length) {
        longest_palindrome.value = substring;
        longest_palindrome.length = j - i;
      }
    }
  }
  return longest_palindrome;
}

// Print the longest palindrome
void print_longest_palindrome(palindrome palindrome) {
  if (palindrome.length == 0) {
    printf("No palindrome found.\n");
  } else {
    printf("The longest palindrome is: %s\n", palindrome.value);
  }
}

// Get the input string from the user
char *get_input_string() {
  char *string = NULL;
  size_t length = 0;
  getline(&string, &length, stdin);
  return string;
}

// Main function
int main() {
  char *input_string = get_input_string();
  palindrome longest_palindrome = find_longest_palindrome(input_string);
  print_longest_palindrome(longest_palindrome);
  free(input_string);
  free(longest_palindrome.value);
  return 0;
}