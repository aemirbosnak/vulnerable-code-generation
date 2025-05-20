//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: decentralized
#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20

struct Word {
  char data[MAX_WORD_LEN];
  struct Word* next;
};

void insertWord(struct Word** head, char* word)
{
  struct Word* newNode = malloc(sizeof(struct Word));
  strcpy(newNode->data, word);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int spellCheck(struct Word* head, char* word)
{
  struct Word* current = head;

  while (current) {
    if (strcmp(word, current->data) == 0) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main()
{
  struct Word* head = NULL;
  insertWord(&head, "apple");
  insertWord(&head, "banana");
  insertWord(&head, "orange");
  insertWord(&head, "grape");

  char* wordToSearch = "banana";

  if (spellCheck(head, wordToSearch) == 1) {
    printf("Word found: %s\n", wordToSearch);
  } else {
    printf("Word not found: %s\n", wordToSearch);
  }

  return 0;
}