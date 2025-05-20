//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

struct CatWord
{
  char word[MAX_WORD_LENGTH];
  int frequency;
  struct CatWord* next;
};

typedef struct CatWord CatWord;

CatWord* insertWord(CatWord* head, char* word)
{
  CatWord* newNode = malloc(sizeof(CatWord));
  strcpy(newNode->word, word);
  newNode->frequency = 1;
  newNode->next = NULL;

  if (head == NULL)
  {
    return newNode;
  }

  CatWord* traverse = head;
  while (traverse->next != NULL)
  {
    traverse = traverse->next;
  }

  traverse->next = newNode;

  return head;
}

void printWordList(CatWord* head)
{
  CatWord* traverse = head;
  while (traverse)
  {
    printf("%s (%d) ", traverse->word, traverse->frequency);
    traverse = traverse->next;
  }
  printf("\n");
}

int main()
{
  CatWord* head = NULL;

  insertWord(head, "Meow");
  insertWord(head, "Woof");
  insertWord(head, "Meow");
  insertWord(head, "Bark");

  printWordList(head);

  return 0;
}