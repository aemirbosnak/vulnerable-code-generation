//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

// Function to capitalize the first letter of each word
void capitalize(char *str) {
  char *ptr = str;
  while (*ptr != '\0') {
    if (*ptr >= 'a' && *ptr <= 'z') {
      *ptr = (*ptr - 'a') + 'A';
    }
    ptr++;
  }
}

// Function to reverse a string
void reverse(char *str) {
  char *ptr = str;
  char *end = ptr + strlen(str) - 1;
  while (ptr < end) {
    char temp = *ptr;
    *ptr = *end;
    *end = temp;
    ptr++;
    end--;
  }
}

// Function to count the number of vowels in a string
int count_vowels(char *str) {
  int count = 0;
  char *ptr = str;
  while (*ptr != '\0') {
    if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
      count++;
    }
    ptr++;
  }
  return count;
}

// Function to replace all occurrences of a word with a magic number
void replace_word(char *str, char *word, int magic) {
  char *ptr = str;
  char *end = ptr + strlen(str) - 1;
  while (ptr < end) {
    if (strncmp(ptr, word, strlen(word)) == 0) {
      *ptr = (char)magic;
    }
    ptr++;
  }
}

int main() {
  char str[MAX_LENGTH];
  char word[MAX_LENGTH];
  int magic = MAGIC_NUMBER;

  // Ask the user for a string and capitalize it
  printf("Enter a string: ");
  fgets(str, MAX_LENGTH, stdin);
  capitalize(str);

  // Ask the user for a word and reverse it
  printf("Enter a word: ");
  fgets(word, MAX_LENGTH, stdin);
  reverse(word);

  // Count the number of vowels in the string
  int vowel_count = count_vowels(str);
  printf("The string contains %d vowels.\n", vowel_count);

  // Replace all occurrences of the word with the magic number
  replace_word(str, word, magic);

  // Print the modified string
  printf("The modified string is: %s\n", str);

  return 0;
}