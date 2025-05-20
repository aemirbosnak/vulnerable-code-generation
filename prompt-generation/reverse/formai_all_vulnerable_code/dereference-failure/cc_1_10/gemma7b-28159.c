//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX_SIZE 100

typedef struct Node {
  char name[MAX_SIZE];
  struct Node* next;
} Node;

typedef struct Index {
  char key[MAX_SIZE];
  struct Index* next;
  Node* node;
} Index;

Index* insertIndex(Index* head, char* key, Node* node) {
  Index* newNode = (Index*)malloc(sizeof(Index));
  strcpy(newNode->key, key);
  newNode->node = node;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Index* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  return head;
}

void searchIndex(Index* head, char* key) {
  Index* current = head;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      printf("Node name: %s\n", current->node->name);
    }
    current = current->next;
  }
}

int main() {
  Index* head = NULL;
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->name, "John Doe");
  head = insertIndex(head, "John Doe", node);

  node = (Node*)malloc(sizeof(Node));
  strcpy(node->name, "Jane Doe");
  head = insertIndex(head, "Jane Doe", node);

  node = (Node*)malloc(sizeof(Node));
  strcpy(node->name, "Peter Pan");
  head = insertIndex(head, "Peter Pan", node);

  searchIndex(head, "Jane Doe");

  return 0;
}