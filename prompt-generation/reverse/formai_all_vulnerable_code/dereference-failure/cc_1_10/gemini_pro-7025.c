//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
char *reverse(char *str) {
  int length = strlen(str);
  char *reversed = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    reversed[length - i - 1] = str[i];
  }
  reversed[length] = '\0';
  return reversed;
}

// Function to capitalize the first letter of each word in a string
char *capitalizeWords(char *str) {
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (i == 0 || str[i - 1] == ' ') {
      str[i] = toupper(str[i]);
    }
  }
  return str;
}

// Function to count the number of vowels in a string
int countVowels(char *str) {
  int count = 0;
  int length = strlen(str);
  for (int i = 0; i < length; i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      count++;
    }
  }
  return count;
}

// Function to remove all punctuation from a string
char *removePunctuation(char *str) {
  int length = strlen(str);
  char *filtered = malloc(length + 1);
  int filteredIndex = 0;
  for (int i = 0; i < length; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      filtered[filteredIndex++] = str[i];
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      filtered[filteredIndex++] = str[i];
    } else if (str[i] == ' ') {
      filtered[filteredIndex++] = str[i];
    }
  }
  filtered[filteredIndex] = '\0';
  return filtered;
}

// Function to find the longest word in a string
char *longestWord(char *str) {
  int length = strlen(str);
  int maxLength = 0;
  char *longest = NULL;
  int start = 0;
  for (int i = 0; i < length; i++) {
    if (str[i] == ' ') {
      if (i - start > maxLength) {
        maxLength = i - start;
        longest = str + start;
      }
      start = i + 1;
    }
  }
  if (length - start > maxLength) {
    maxLength = length - start;
    longest = str + start;
  }
  return longest;
}

int main() {
  char *str = "Hello, world! This is a test string.";

  printf("Original string: %s\n", str);

  printf("Reversed string: %s\n", reverse(str));

  printf("Capitalized string: %s\n", capitalizeWords(str));

  printf("Number of vowels: %d\n", countVowels(str));

  printf("String without punctuation: %s\n", removePunctuation(str));

  printf("Longest word: %s\n", longestWord(str));

  return 0;
}