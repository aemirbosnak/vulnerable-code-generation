//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
  int len = strlen(str);
  char *reversed = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    reversed[i] = str[len - i - 1];
  }
  reversed[len] = '\0';
  return reversed;
}

// Function to capitalize the first letter of a string
char *capitalize(char *str) {
  int len = strlen(str);
  char *capitalized = malloc(len + 1);
  capitalized[0] = toupper(str[0]);
  for (int i = 1; i < len; i++) {
    capitalized[i] = str[i];
  }
  capitalized[len] = '\0';
  return capitalized;
}

// Function to remove spaces from a string
char *remove_spaces(char *str) {
  int len = strlen(str);
  char *new_str = malloc(len + 1);
  int j = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] != ' ') {
      new_str[j++] = str[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
  int len = strlen(str);
  int count = 0;
  for (int i = 0; i < len; i++) {
    char c = str[i];
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    }
  }
  return count;
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

// Function to test the string manipulation functions
void test_functions() {
  char *str1 = "Hello World";
  char *reversed_str = reverse(str1);
  char *capitalized_str = capitalize(str1);
  char *removed_spaces_str = remove_spaces(str1);
  int vowel_count = count_vowels(str1);
  int is_palindrome_result = is_palindrome(str1);

  printf("Original string: %s\n", str1);
  printf("Reversed string: %s\n", reversed_str);
  printf("Capitalized string: %s\n", capitalized_str);
  printf("String with spaces removed: %s\n", removed_spaces_str);
  printf("Vowel count: %d\n", vowel_count);
  printf("Is palindrome: %s\n", is_palindrome_result ? "Yes" : "No");

  free(reversed_str);
  free(capitalized_str);
  free(removed_spaces_str);
}

int main() {
  test_functions();
  return 0;
}