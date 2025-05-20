//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LETTERS 20

typedef struct Word {
  char **letters;
  int length;
} Word;

Word **words;

void initializeWords() {
  words = malloc(MAX_WORDS * sizeof(Word));
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i] = malloc(MAX_LETTERS * sizeof(char *));
    words[i]->letters = malloc(MAX_LETTERS * sizeof(char *));
    words[i]->length = 0;
  }
}

void addWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->letters = malloc(MAX_LETTERS * sizeof(char *));
  newWord->length = 0;

  for (int i = 0; word[i] != '\0'; i++) {
    newWord->letters[newWord->length++] = malloc(sizeof(char));
    *newWord->letters[newWord->length - 1] = word[i];
  }

  words[newWord->length - 1] = newWord;
}

int main() {
  initializeWords();

  addWord("apple");
  addWord("banana");
  addWord("orange");

  for (int i = 0; i < words[0]->length; i++) {
    printf("%c ", words[0]->letters[i]);
  }

  printf("\n");

  for (int i = 0; i < words[1]->length; i++) {
    printf("%c ", words[1]->letters[i]);
  }

  printf("\n");

  for (int i = 0; i < words[2]->length; i++) {
    printf("%c ", words[2]->letters[i]);
  }

  return 0;
}