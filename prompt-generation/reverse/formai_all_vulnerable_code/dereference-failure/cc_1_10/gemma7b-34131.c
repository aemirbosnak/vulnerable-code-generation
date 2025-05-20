//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define NUM_LANGUAGES 3

typedef struct AlienLanguage {
  char **words;
  int numWords;
  char **translations;
} AlienLanguage;

AlienLanguage *createAlienLanguage(int numWords) {
  AlienLanguage *language = malloc(sizeof(AlienLanguage));
  language->words = malloc(numWords * sizeof(char *));
  language->numWords = numWords;
  language->translations = malloc(numWords * sizeof(char *));
  return language;
}

void translateAlienLanguage(AlienLanguage *language, char *word) {
  for (int i = 0; i < language->numWords; i++) {
    if (strcmp(word, language->words[i]) == 0) {
      printf("%s", language->translations[i]);
      return;
    }
  }
  printf("Word not found.");
}

int main() {
  AlienLanguage *language = createAlienLanguage(5);
  language->words[0] = "Zork";
  language->words[1] = "Blork";
  language->words[2] = "Flork";
  language->words[3] = "Zlor";
  language->words[4] = "Barg";
  language->translations[0] = "Hello, world!";
  language->translations[1] = "Goodbye, cruel world!";
  language->translations[2] = "I am a robot";
  language->translations[3] = "What is the meaning of life?";
  language->translations[4] = "Pizza is delicious!";

  translateAlienLanguage(language, "Zork");
  printf("\n");
  translateAlienLanguage(language, "Blork");
  printf("\n");
  translateAlienLanguage(language, "Flork");
  printf("\n");
  translateAlienLanguage(language, "Zlor");
  printf("\n");
  translateAlienLanguage(language, "Barg");
  printf("\n");

  return 0;
}