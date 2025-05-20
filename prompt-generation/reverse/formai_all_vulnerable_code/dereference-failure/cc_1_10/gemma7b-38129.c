//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10

typedef struct Word
{
  char *word;
  struct Word *next;
} Word;

Word *insertWord(Word *head, char *word)
{
  Word *newWord = malloc(sizeof(Word));
  newWord->word = strdup(word);
  newWord->next = NULL;

  if (head == NULL)
  {
    head = newWord;
  }
  else
  {
    head->next = insertWord(head->next, word);
  }

  return head;
}

int translateCat(Word *head, char *phrase)
{
  char *words[MAX_WORDS];
  int numWords = 0;

  for (Word *word = head; word; word = word->next)
  {
    words[numWords++] = word->word;
  }

  int i = 0;
  for (char *word = phrase; *word; word++)
  {
    if (strcmp(word, words[i]) == 0)
    {
      printf("%s ", words[i + 1]);
      i++;
    }
    else
    {
      printf("%c ", *word);
    }
  }

  printf("\n");

  return 0;
}

int main()
{
  Word *head = insertWord(NULL, "Meow");
  insertWord(head, "Purr");
  insertWord(head, "Meow");
  insertWord(head, "Happy");

  translateCat(head, "The cat is happy.");

  return 0;
}