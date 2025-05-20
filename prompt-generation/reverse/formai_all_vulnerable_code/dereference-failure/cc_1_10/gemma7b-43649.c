//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

typedef struct AlienWord
{
  char **word;
  int length;
  struct AlienWord *next;
} AlienWord;

AlienWord *alienWordCreate(char **word, int length)
{
  AlienWord *newWord = malloc(sizeof(AlienWord));
  newWord->word = malloc(sizeof(char *) * MAX_WORDS);
  newWord->length = length;
  newWord->next = NULL;

  for (int i = 0; i < MAX_WORDS; i++)
  {
    newWord->word[i] = NULL;
  }

  newWord->word[0] = word;

  return newWord;
}

void alienWordTranslate(AlienWord *word)
{
  for (int i = 0; i < word->length; i++)
  {
    printf("%s ", word->word[i]);
  }

  printf("\n");
}

int main()
{
  char **words = malloc(sizeof(char *) * MAX_WORDS);
  words[0] = "G'bl'zt!";
  words[1] = "Zork!";
  words[2] = "Blorg!";

  AlienWord *alienWordList = alienWordCreate(words, 3);

  alienWordTranslate(alienWordList);

  free(words);
  free(alienWordList);

  return 0;
}