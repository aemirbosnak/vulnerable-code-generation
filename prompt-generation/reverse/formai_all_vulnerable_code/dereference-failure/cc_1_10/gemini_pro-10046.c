//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: cheerful
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return the number of words in a string
int wordCount(char *str) {
  int count = 0;
  int inWord = 0;
  for (int i = 0; str[i]; i++) {
    if (isspace(str[i])) {
      inWord = 0;
    } else if (!inWord) {
      inWord = 1;
      count++;
    }
  }
  return count;
}

// Function to return the length of the longest word in a string
int longestWordLength(char *str) {
  int maxLen = 0;
  int curLen = 0;
  for (int i = 0; str[i]; i++) {
    if (isspace(str[i])) {
      if (curLen > maxLen) {
        maxLen = curLen;
      }
      curLen = 0;
    } else {
      curLen++;
    }
  }
  if (curLen > maxLen) {
    maxLen = curLen;
  }
  return maxLen;
}

// Function to return the most frequently occurring character in a string
char mostFrequentChar(char *str) {
  int freq[256] = {0};
  for (int i = 0; str[i]; i++) {
    freq[str[i]]++;
  }
  int maxFreq = 0;
  char maxChar;
  for (int i = 0; i < 256; i++) {
    if (freq[i] > maxFreq) {
      maxFreq = freq[i];
      maxChar = i;
    }
  }
  return maxChar;
}

// Function to return a new string that is the reverse of the given string
char *reverseString(char *str) {
  int len = strlen(str);
  char *reversed = malloc(len + 1);
  for (int i = 0; i < len; i++) {
    reversed[i] = str[len - i - 1];
  }
  reversed[len] = '\0';
  return reversed;
}

// Function to test the above functions
int main() {
  char str[] = "Hello, world! This is a test string.";

  printf("String: %s\n", str);
  printf("Number of words: %d\n", wordCount(str));
  printf("Length of longest word: %d\n", longestWordLength(str));
  printf("Most frequently occurring character: %c\n", mostFrequentChar(str));
  printf("Reversed string: %s\n", reverseString(str));

  return 0;
}