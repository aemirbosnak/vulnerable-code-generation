//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR 20

typedef struct Word {
  char **words;
  int size;
} WordList;

WordList *createWordList(int size) {
  WordList *list = malloc(sizeof(WordList));
  list->words = malloc(sizeof(char *) * size);
  list->size = size;
  return list;
}

void addWordToList(WordList *list, char *word) {
  list->words[list->size++] = strdup(word);
}

int main() {
  WordList *words = createWordList(MAX_WORDS);
  addWordToList(words, "Hello");
  addWordToList(words, "World");
  addWordToList(words, "Test");
  addWordToList(words, "Speed");

  time_t start, end;
  char input[MAX_CHAR];

  start = time(NULL);

  printf("Type a word from the list below:\n");
  for (int i = 0; i < words->size; i++) {
    printf("%d. %s\n", i + 1, words->words[i]);
  }

  scanf("%s", input);

  end = time(NULL);

  int timeTaken = end - start;

  printf("Time taken to type the word: %d seconds\n", timeTaken);

  for (int i = 0; i < words->size; i++) {
    if (strcmp(input, words->words[i]) == 0) {
      printf("Word found: %s\n", words->words[i]);
    }
  }

  free(words->words);
  free(words);

  return 0;
}