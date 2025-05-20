//FormAI DATASET v1.0 Category: Spell checking ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 50000

bool isWordChar(char c) {
  return (isalpha(c) || c == '-' || c == '_' || c == '\'');
}

void toLowerCase(char *str) {
  for (int i = 0; str[i]; i++) {
    str[i] = tolower(str[i]);
  }
}

int binarySearch(char **wordList, int left, int right, char *target) {
  while (left <= right) {
    int mid = (left + right) / 2;
    if (strcmp(wordList[mid], target) == 0) {
      return mid;
    }
    else if (strcmp(wordList[mid], target) < 0) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  return -1;
}

int main() {
  char word[MAX_WORD_LENGTH+1];
  char *wordList[MAX_NUM_WORDS];
  int numWords = 0;

  // Read in the word list
  FILE *wordFile = fopen("words.txt", "r");
  while (fgets(word, MAX_WORD_LENGTH+1, wordFile) != NULL) {
    word[strcspn(word, "\r\n")] = '\0'; // remove trailing newline
    toLowerCase(word);
    wordList[numWords++] = strdup(word); // add a copy of the word to array
  }
  fclose(wordFile);

  // Sort the word list
  qsort(wordList, numWords, sizeof(char*), strcmp);

  // Prompt user to enter a sentence
  printf("Enter a sentence: ");
  fgets(word, MAX_NUM_WORDS*MAX_WORD_LENGTH+1, stdin);

  // Replace all non-word characters (except spaces) with null characters
  for (int i = 0; word[i]; i++) {
    if (!isWordChar(word[i]) && word[i] != ' ') {
      word[i] = '\0';
    }
  }

  // Tokenize the sentence
  char *runningStart = word; // pointer to the start of the current word substring
  char *runningEnd = word;   // pointer to the end of the current word substring
  char *tokenList[MAX_NUM_WORDS];
  int numTokens = 0;
  while (*runningStart != '\0') {
    // scan ahead to the start of the next word
    while (*runningStart != '\0' && !isWordChar(*runningStart)) {
      runningStart++;
    }
    runningEnd = runningStart;
    // scan ahead to the end of the current word
    while (*runningEnd != '\0' && isWordChar(*runningEnd)) {
      runningEnd++;
    }
    if (runningEnd > runningStart) {
      // add the current word substring to the token list
      *runningEnd = '\0'; // temporarily replace the terminator with null character
      tokenList[numTokens++] = runningStart;
      runningStart = runningEnd+1; // move the start of the next word substring forward
    }
  }

  // Check spelling of each token
  for (int i = 0; i < numTokens; i++) {
    // check if the token is in the word list
    int index = binarySearch(wordList, 0, numWords-1, tokenList[i]);
    if (index == -1) {
      printf("%s is a misspelled word.\n", tokenList[i]);
    }
  }

  // Free memory allocated for word list and token list
  for (int i = 0; i < numWords; i++) {
    free(wordList[i]);
  }
  
  return 0;
}