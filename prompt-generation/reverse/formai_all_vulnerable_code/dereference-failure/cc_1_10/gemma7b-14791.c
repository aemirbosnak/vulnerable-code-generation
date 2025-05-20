//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 255

typedef struct Node {
  char **words;
  struct Node* next;
} Node;

Node* insertNode(Node* head, char* word)
{
  Node* newNode = malloc(sizeof(struct Node));
  newNode->words = malloc(MAX_WORD_LENGTH * sizeof(char*));
  newNode->next = NULL;

  int i = 0;
  for ( ; newNode->words[i] != NULL; i++) {
    newNode->words[i] = word;
  }

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void translate(Node* head, char* source, char* target)
{
  char** words = head->words;

  int i = 0;
  for ( ; words[i] != NULL; i++) {
    if (strcmp(words[i], source) == 0) {
      strcpy(target, words[i+1]);
    }
  }
}

int main()
{
  Node* head = NULL;
  insertNode(head, "apple");
  insertNode(head, "banana");
  insertNode(head, "cherry");

  char* source = "apple";
  char* target = malloc(MAX_WORD_LENGTH * sizeof(char));

  translate(head, source, target);

  printf("%s", target);

  free(target);
  return 0;
}