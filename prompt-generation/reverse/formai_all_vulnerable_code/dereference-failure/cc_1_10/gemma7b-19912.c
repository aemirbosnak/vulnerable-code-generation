//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10

typedef struct AlienWord
{
  char *word;
  int translations;
  struct AlienWord *next;
} AlienWord;

AlienWord *head = NULL;

void translateWord(char *word)
{
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = strdup(word);
  newWord->translations = 0;
  newWord->next = NULL;

  if (head == NULL)
  {
    head = newWord;
  }
  else
  {
    AlienWord *currentWord = head;
    while (currentWord->next)
    {
      currentWord = currentWord->next;
    }
    currentWord->next = newWord;
  }
}

int translate(char * alienWord)
{
  AlienWord *word = head;
  while (word)
  {
    if (strcmp(alienWord, word->word) == 0)
    {
      return word->translations;
    }
    word = word->next;
  }

  return -1;
}

int main()
{
  translateWord("Blorg");
  translateWord("Zork");
  translateWord("Flub");

  int translations = translate("Blorg");
  printf("Translations: %d\n", translations);

  return 0;
}