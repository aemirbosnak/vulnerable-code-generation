//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
  char *word;
  int translations;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWordHead = NULL;

void translateWord(char *word) {
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->translations = 0;
  newWord->next = alienWordHead;
  alienWordHead = newWord;
}

void translateWordTranslation(char *translation) {
  AlienWord *currentWord = alienWordHead;
  while (currentWord) {
    if (strcmp(currentWord->word, translation) == 0) {
      currentWord->translations++;
    }
    currentWord = currentWord->next;
  }
}

int main() {
  translateWord("Zoo");
  translateWord("Bar");
  translateWord("Foo");
  translateWord("Buzz");

  translateWordTranslation("Bar");
  translateWordTranslation("Foo");

  AlienWord *currentWord = alienWordHead;
  while (currentWord) {
    printf("%s has %d translations.\n", currentWord->word, currentWord->translations);
    currentWord = currentWord->next;
  }

  return 0;
}