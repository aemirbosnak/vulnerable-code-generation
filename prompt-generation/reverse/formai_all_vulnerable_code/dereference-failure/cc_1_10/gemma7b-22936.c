//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1024
#define MAX_WORD_LENGTH 256

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
    return newWord;
  }

  head->next = insertWord(head->next, word);
  return head;
}

int translateCCat(Word *head)
{
  int i = 0;
  for (Word *word = head; word; word = word->next)
  {
    char *translatedWord = malloc(MAX_WORD_LENGTH);
    translatedWord[0] = 'a' + i;
    translatedWord[1] = '\0';
    printf("%s ", translatedWord);
    i++;
  }
  printf("\n");
  return 0;
}

int main()
{
  Word *head = insertWord(NULL, "Cat");
  insertWord(head, "Dog");
  insertWord(head, "Lion");

  translateCCat(head);

  return 0;
}