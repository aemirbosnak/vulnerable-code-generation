//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024

typedef struct Word {
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

int main()
{
  Word *head = NULL;

  insertWord(head, "hello");
  insertWord(head, "world");
  insertWord(head, "foo");
  insertWord(head, "bar");

  Word *currentWord = head;

  while (currentWord)
  {
    printf("%s ", currentWord->word);
    currentWord = currentWord->next;
  }

  printf("\n");

  return 0;
}