//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
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

  if (head == NULL) {
    head = newWord;
  } else {
    head->next = insertWord(head->next, word);
  }

  return head;
}

void translate(Word *head)
{
  char **translations = malloc(MAX_WORDS * sizeof(char *));
  int i = 0;

  for (Word *word = head; word; word = word->next) {
    translations[i++] = word->word;
  }

  translations[i] = NULL;

  printf("Translations:");

  for (char **t = translations; *t; t++) {
    printf(" %s", *t);
  }

  printf("\n");

  free(translations);
}

int main()
{
  Word *head = insertWord(NULL, "cat");
  insertWord(head, "dog");
  insertWord(head, "fish");

  translate(head);

  return 0;
}