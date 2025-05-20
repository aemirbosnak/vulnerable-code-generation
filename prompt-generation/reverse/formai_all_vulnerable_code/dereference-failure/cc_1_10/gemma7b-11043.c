//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord {
  char *word;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWordHead = NULL;

void addAlienWord(char *word) {
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (alienWordHead == NULL) {
    alienWordHead = newWord;
  } else {
    AlienWord *temp = alienWordHead;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newWord;
  }
}

char *translateAlien(char *alienWord) {
  AlienWord *word = alienWordHead;
  while (word) {
    if (strcmp(alienWord, word->word) == 0) {
      return word->word;
    }
    word = word->next;
  }

  return NULL;
}

int main() {
  addAlienWord("Blorg");
  addAlienWord("Zork");
  addAlienWord("Narf");

  char *translatedWord = translateAlien("Blorg");

  if (translatedWord) {
    printf("Translated word: %s\n", translatedWord);
  } else {
    printf("Word not found.\n");
  }

  return 0;
}