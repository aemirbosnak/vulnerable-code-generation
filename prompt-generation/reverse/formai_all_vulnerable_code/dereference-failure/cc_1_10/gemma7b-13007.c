//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct AlienWord
{
  char **translations;
  int numTranslations;
} AlienWord;

AlienWord *alienWord_create()
{
  AlienWord *word = malloc(sizeof(AlienWord));
  word->translations = malloc(MAX_WORDS * sizeof(char *));
  word->numTranslations = 0;
  return word;
}

void alienWord_addTranslation(AlienWord *word, char *translation)
{
  word->translations[word->numTranslations++] = translation;
}

int alienWord_translate(AlienWord *word, char *language)
{
  for (int i = 0; i < word->numTranslations; i++)
  {
    if (strcmp(language, word->translations[i]) == 0)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  AlienWord *alienWord = alienWord_create();
  alienWord_addTranslation(alienWord, "Greetings from Earth.");
  alienWord_addTranslation(alienWord, "May the Force be with you.");
  alienWord_addTranslation(alienWord, "Have a nice day.");

  char *language = "Alien";
  int translationIndex = alienWord_translate(alienWord, language);

  if (translationIndex != -1)
  {
    printf("%s", alienWord->translations[translationIndex]);
  }
  else
  {
    printf("Translation not found.");
  }

  return 0;
}