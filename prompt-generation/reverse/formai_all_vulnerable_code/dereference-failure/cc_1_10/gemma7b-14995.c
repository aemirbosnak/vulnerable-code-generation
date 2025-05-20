//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct AlienWord {
  char *word;
  int translations;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWord_create(char *word) {
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->translations = 0;
  newWord->next = NULL;
  return newWord;
}

void alienWord_addTranslation(AlienWord *word, char *translation) {
  word->translations++;
  word->next = alienWord_create(translation);
}

void alienWord_printTranslations(AlienWord *word) {
  printf("%s: ", word->word);
  for (AlienWord *translation = word->next; translation; translation = translation->next) {
    printf("%s, ", translation->word);
  }
  printf("\n");
}

int main() {
  AlienWord *alienWords = NULL;

  // Create some alien words
  alienWords = alienWord_create("Blorg");
  alienWord_addTranslation(alienWords, "Stupid");
  alienWord_addTranslation(alienWords, "Novice");
  alienWord_addTranslation(alienWords, "Weak");

  alienWord_printTranslations(alienWords);

  alienWords = alienWord_create("Moo");
  alienWord_addTranslation(alienWords, "Powerful");
  alienWord_addTranslation(alienWords, "Strong");
  alienWord_addTranslation(alienWords, "Brave");

  alienWord_printTranslations(alienWords);

  return 0;
}