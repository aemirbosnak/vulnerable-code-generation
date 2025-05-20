//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of words in a string
int countWords(char *str) {
  int count = 0;
  int i = 0;
  int inWord = 0;

  while (str[i] != '\0') {
    if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
      inWord = 0;
    } else if (inWord == 0) {
      count++;
      inWord = 1;
    }
    i++;
  }

  return count;
}

// Function to get the word at a given index in a string
char *getWord(char *str, int index) {
  int count = 0;
  int i = 0;
  int start = -1;
  int end = -1;

  while (str[i] != '\0') {
    if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
      if (count == index) {
        end = i - 1;
        break;
      }
      count++;
    } else if (start == -1) {
      start = i;
    }
    i++;
  }

  if (count == index) {
    end = i - 1;
  }

  if (start == -1) {
    return NULL;
  }

  char *word = malloc(end - start + 2);
  strncpy(word, str + start, end - start + 1);
  word[end - start + 1] = '\0';

  return word;
}

// Function to print the words in a string
void printWords(char *str) {
  int count = countWords(str);
  int i;

  for (i = 0; i < count; i++) {
    char *word = getWord(str, i);
    printf("%s\n", word);
    free(word);
  }
}

int main() {
  char *str = "This is a sample string with multiple words.";

  int wordCount = countWords(str);
  printf("The number of words in the string is: %d\n", wordCount);

  printWords(str);

  return 0;
}