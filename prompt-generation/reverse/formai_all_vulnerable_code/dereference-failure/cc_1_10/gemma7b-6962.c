//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define WORDS_PER_LINE 20

typedef struct Word {
  char **words;
  int index;
} Word;

Word *createWordList() {
  Word *wordList = malloc(sizeof(Word));
  wordList->words = malloc(MAX_WORDS * sizeof(char *));
  wordList->index = 0;
  return wordList;
}

void addWordToWordList(Word *wordList, char *word) {
  wordList->words[wordList->index++] = word;
}

void freeWordList(Word *wordList) {
  free(wordList->words);
  free(wordList);
}

int main() {
  Word *wordList = createWordList();
  addWordToWordList(wordList, "Hello");
  addWordToWordList(wordList, "World");
  addWordToWordList(wordList, "And");
  addWordToWordList(wordList, "How");
  addWordToWordList(wordList, "Are");
  addWordToWordList(wordList, "You?");

  time_t start = time(NULL);
  int i = 0;
  for (i = 0; i < MAX_WORDS; i++) {
    printf("%s ", wordList->words[i]);
  }
  printf("\n");

  time_t end = time(NULL);
  double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("Time taken: %.2f seconds\n", timeTaken);

  freeWordList(wordList);

  return 0;
}