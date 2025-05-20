//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a string
#define MAX_STR_LEN 100

// Declare a function to reverse a string
void reverse_string(char *str) {
  int len = strlen(str);
  for (int i = 0; i < len / 2; i++) {
    char temp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = temp;
  }
}

// Declare a function to count the number of vowels in a string
int count_vowels(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    char ch = str[i];
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
        ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
      count++;
    }
  }
  return count;
}

// Declare a function to find the longest word in a string
char *find_longest_word(char *str) {
  char *longest_word = NULL;
  int max_len = 0;
  char *start = str;
  while (*str != '\0') {
    if (*str == ' ' || *str == '\t' || *str == '\n') {
      if (str - start > max_len) {
        max_len = str - start;
        longest_word = start;
      }
      start = str + 1;
    }
    str++;
  }
  if (str - start > max_len) {
    max_len = str - start;
    longest_word = start;
  }
  return longest_word;
}

// Declare a function to print a string in a centered format
void print_centered(char *str) {
  int len = strlen(str);
  int spaces = (MAX_STR_LEN - len) / 2;
  for (int i = 0; i < spaces; i++) {
    printf(" ");
  }
  printf("%s", str);
  for (int i = 0; i < spaces; i++) {
    printf(" ");
  }
  printf("\n");
}

// Declare a function to test the string manipulation functions
void test_string_manipulation() {
  // Define a test string
  char str[] = "Hello World! This is a test string.";

  // Reverse the string
  reverse_string(str);
  printf("Reversed string: %s\n", str);

  // Count the number of vowels in the string
  int vowel_count = count_vowels(str);
  printf("Number of vowels: %d\n", vowel_count);

  // Find the longest word in the string
  char *longest_word = find_longest_word(str);
  printf("Longest word: %s\n", longest_word);

  // Print the string in a centered format
  print_centered(str);
}

// Declare a function to generate a random string
char *generate_random_string(int len) {
  char *str = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    str[i] = (rand() % 26) + 'a';
  }
  str[len] = '\0';
  return str;
}

// Declare a function to test the random string generator
void test_random_string_generator() {
  // Generate a random string of length 10
  char *str = generate_random_string(10);
  printf("Random string: %s\n", str);

  // Free the allocated memory
  free(str);
}

// Declare the main function
int main() {
  // Test the string manipulation functions
  test_string_manipulation();

  // Test the random string generator
  test_random_string_generator();

  return 0;
}