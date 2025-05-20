//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct Word {
  char **words;
  int size;
} WordList;

WordList *createWordList() {
  WordList *list = malloc(sizeof(WordList));
  list->words = malloc(MAX_WORDS * sizeof(char *));
  list->size = 0;
  return list;
}

void addWordToWordList(WordList *list, char *word) {
  list->words[list->size++] = strdup(word);
}

char **translateAlienLanguage(char *alienText) {
  WordList *list = createWordList();
  char **translation = malloc(MAX_WORD_LENGTH * MAX_WORDS);
  char *word = strtok(alienText, " ");
  while (word) {
    addWordToWordList(list, word);
    word = strtok(NULL, " ");
  }

  int i = 0;
  for (WordList *l = list; l; l++) {
    for (int j = 0; j < l->size; j++) {
      translation[i++] = l->words[j];
    }
  }

  return translation;
}

int main() {
  char *alienText = "Tr'bl'zt x'zt w'lf g'lb'zt z'xzt cz'xzt";
  char **translation = translateAlienLanguage(alienText);
  printf("%s", translation[0]);
  printf(" ");
  printf("%s", translation[1]);
  printf("\n");
  return 0;
}