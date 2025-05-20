//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

typedef struct Node {
  char word[MAX_LENGTH];
  struct Node* next;
} Node;

Node* insert(Node* head, char* word) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->word, word);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

int translate(Node* head, char* query) {
  char* words[MAX_WORDS];
  int i = 0;

  for (Node* current = head; current; current = current->next) {
    words[i++] = current->word;
  }

  for (i = 0; words[i] && strcmp(words[i], query) != 0; i++) {}

  if (words[i]) {
    printf("%s\n", words[i]);
  } else {
    printf("No match\n");
  }

  return 0;
}

int main() {
  Node* head = NULL;
  insert(head, "cat");
  insert(head, "dog");
  insert(head, "fish");

  translate(head, "cat");
  translate(head, "bird");

  return 0;
}