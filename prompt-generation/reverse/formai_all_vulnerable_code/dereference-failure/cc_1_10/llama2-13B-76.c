//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// Retro Linked Lists v1.0
// (C) 1987-1988 Radiant Software

// Includes
#include <stdio.h>
#include <stdlib.h>

// Structs and Functions
struct Node {
  int data;
  struct Node *next;
};

struct List {
  struct Node *head;
};

void initList(struct List *list) {
  list->head = NULL;
}

void appendNode(struct List *list, int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = list->head;
  list->head = newNode;
}

int findNode(struct List *list, int data) {
  struct Node *current = list->head;
  while (current != NULL) {
    if (current->data == data) return 1;
    current = current->next;
  }
  return 0;
}

void removeNode(struct List *list, int data) {
  struct Node *current = list->head;
  struct Node *prev = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (prev == NULL) list->head = current->next;
      else prev->next = current->next;
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

void printList(struct List *list) {
  struct Node *current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct List *list = malloc(sizeof(struct List));
  initList(list);

  // Append some nodes
  appendNode(list, 1);
  appendNode(list, 2);
  appendNode(list, 3);

  // Find a node
  if (findNode(list, 2)) {
    printf("Found node with value 2\n");
  } else {
    printf("Node with value 2 not found\n");
  }

  // Remove a node
  removeNode(list, 2);

  // Print the list
  printList(list);

  return 0;
}