//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
  char **words;
  int numWords;
} AlienWord;

AlienWord *createAlienWord(int numWords) {
  AlienWord *alienWord = malloc(sizeof(AlienWord));
  alienWord->words = malloc(sizeof(char *) * numWords);
  alienWord->numWords = numWords;
  return alienWord;
}

void addAlienWord(AlienWord *alienWord, char *word) {
  int i = alienWord->numWords;
  alienWord->words = realloc(alienWord->words, sizeof(char *) * (i + 1));
  alienWord->words[i] = strdup(word);
  alienWord->numWords++;
}

char *translateAlienWord(AlienWord *alienWord, char *word) {
  for (int i = 0; i < alienWord->numWords; i++) {
    if (strcmp(word, alienWord->words[i]) == 0) {
      return alienWord->words[i + 1];
    }
  }
  return NULL;
}

int main() {
  AlienWord *alienWord = createAlienWord(5);
  addAlienWord(alienWord, "Blorg");
  addAlienWord(alienWord, "Zork");
  addAlienWord(alienWord, "Korb");
  addAlienWord(alienWord, "Quork");
  addAlienWord(alienWord, "Barg");

  char *translatedWord = translateAlienWord(alienWord, "Blorg");
  if (translatedWord) {
    printf("%s", translatedWord);
  } else {
    printf("Word not found");
  }

  return 0;
}