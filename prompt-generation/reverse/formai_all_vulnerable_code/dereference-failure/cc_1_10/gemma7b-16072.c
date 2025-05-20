//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_NUM_WORDS 10

typedef struct Word {
  char **words;
  int num_words;
} WordList;

WordList *createWordList() {
  WordList *wordList = malloc(sizeof(WordList));
  wordList->words = malloc(sizeof(char *) * MAX_NUM_WORDS);
  wordList->num_words = 0;
  return wordList;
}

void addWordToWordList(WordList *wordList, char *word) {
  wordList->words[wordList->num_words++] = word;
}

int main() {
  WordList *wordList = createWordList();
  addWordToWordList(wordList, "apple");
  addWordToWordList(wordList, "banana");
  addWordToWordList(wordList, "orange");
  addWordToWordList(wordList, "grape");
  addWordToWordList(wordList, "mango");
  addWordToWordList(wordList, "pineapple");
  addWordToWordList(wordList, "watermelon");

  char *wordToFind = "apple";

  int found = 0;
  for (int i = 0; i < wordList->num_words; i++) {
    if (strcmp(wordList->words[i], wordToFind) == 0) {
      found = 1;
      break;
    }
  }

  if (found) {
    printf("Word found: %s\n", wordToFind);
  } else {
    printf("Word not found: %s\n", wordToFind);
  }

  return 0;
}