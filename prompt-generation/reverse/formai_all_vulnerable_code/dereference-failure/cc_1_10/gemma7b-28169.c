//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct Node {
  char *name;
  struct Node *next;
} Node;

typedef struct ListManager {
  Node **head;
  int size;
  int (*compare)(char *, char *);
} ListManager;

ListManager *createListManager(int (*compare)(char *, char *)) {
  ListManager *listManager = malloc(sizeof(ListManager));
  listManager->head = NULL;
  listManager->size = 0;
  listManager->compare = compare;
  return listManager;
}

void addToListManager(ListManager *listManager, char *name) {
  Node *newNode = malloc(sizeof(Node));
  newNode->name = strdup(name);
  newNode->next = NULL;

  if (listManager->head == NULL) {
    listManager->head = newNode;
  } else {
    newNode->next = listManager->head;
    listManager->head = newNode;
  }

  listManager->size++;
}

void printListManager(ListManager *listManager) {
  Node *currentNode = listManager->head;
  while (currentNode) {
    printf("%s ", currentNode->name);
    currentNode = currentNode->next;
  }

  printf("\n");
}

int main() {
  ListManager *listManager = createListManager(strcmp);
  addToListManager(listManager, "Alice");
  addToListManager(listManager, "Bob");
  addToListManager(listManager, "Charlie");
  addToListManager(listManager, "Dave");

  printListManager(listManager);

  return 0;
}