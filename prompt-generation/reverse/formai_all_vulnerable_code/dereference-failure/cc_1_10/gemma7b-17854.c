//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *word;
  int frequency;
} Word;

Word **words = NULL;

void addWord(char *word) {
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->frequency = 1;

  if (words == NULL) {
    words = malloc(sizeof(Word *) * MAX_WORDS);
  }

  words = realloc(words, sizeof(Word *) * (MAX_WORDS + 1));
  words[MAX_WORDS] = newWord;
}

void countWords() {
  int i = 0;
  for (i = 0; words[i] != NULL; i++) {
    words[i]->frequency++;
  }
}

void printWords() {
  int i = 0;
  for (i = 0; words[i] != NULL; i++) {
    printf("%s: %d\n", words[i]->word, words[i]->frequency);
  }
}

int main() {
  addWord("apple");
  addWord("banana");
  addWord("cherry");
  addWord("apple");
  addWord("orange");
  addWord("banana");

  countWords();

  printWords();

  return 0;
}