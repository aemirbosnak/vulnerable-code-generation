//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word {
  char **words;
  int size;
} Word;

Word *createWordList(int size) {
  Word *wordList = malloc(sizeof(Word));
  wordList->words = malloc(sizeof(char *) * size);
  wordList->size = size;
  return wordList;
}

void addWordToList(Word *wordList, char *word) {
  wordList->words[wordList->size++] = word;
}

int main() {
  time_t start, end;
  char **words;
  Word *wordList = createWordList(MAX_WORDS);

  // Fill the word list with some words
  addWordToList(wordList, "C");
  addWordToList(wordList, "Typing");
  addWordToList(wordList, "Speed");
  addWordToList(wordList, "Test");

  start = time(NULL);

  // Start the timer and ask the user to type the words
  printf("Please type the words below as quickly as possible:\n");
  for (int i = 0; i < wordList->size; i++) {
    printf("%s ", wordList->words[i]);
  }

  end = time(NULL);

  // Stop the timer and calculate the time taken
  int timeTaken = end - start;

  // Print the time taken
  printf("\nTime taken: %d seconds\n", timeTaken);

  // Free the memory allocated for the word list
  free(wordList->words);
  free(wordList);

  return 0;
}