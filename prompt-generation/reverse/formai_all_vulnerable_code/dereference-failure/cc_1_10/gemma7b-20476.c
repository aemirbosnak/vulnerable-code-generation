//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
  char *name;
  int frequency;
} Word;

Word *words;

void initializeWords() {
  words = malloc(MAX_WORDS * sizeof(Word));
  for (int i = 0; i < MAX_WORDS; i++) {
    words[i].name = NULL;
    words[i].frequency = 0;
  }
}

void addWord(char *word) {
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].name == NULL) {
      words[i].name = strdup(word);
      words[i].frequency = 1;
      return;
    } else if (strcmp(words[i].name, word) == 0) {
      words[i].frequency++;
      return;
    }
  }
  initializeWords();
  addWord(word);
}

void printWordFrequencies() {
  printf("Word frequencies:\n");
  for (int i = 0; i < MAX_WORDS; i++) {
    if (words[i].name) {
      printf("%s: %d\n", words[i].name, words[i].frequency);
    }
  }
}

int main() {
  initializeWords();
  addWord("sword");
  addWord("shield");
  addWord("horse");
  addWord("knight");
  addWord("dragon");
  addWord("treasure");
  addWord("gold");
  printWordFrequencies();

  return 0;
}