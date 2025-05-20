//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct Index {
  int key;
  Node* head;
  Node* tail;
  struct Index* next;
};

void insertIndex(struct Index** head, int key, int data) {
  struct Index* newNode = malloc(sizeof(struct Index));
  newNode->key = key;
  newNode->head = NULL;
  newNode->tail = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->tail)->next = newNode;
    (*head)->tail = newNode;
  }
}

void searchIndex(struct Index* head, int key) {
  struct Index* current = head;
  while (current) {
    if (current->key == key) {
      printf("Data: %d\n", current->head->data);
    }
    current = current->next;
  }
}

int main() {
  struct Index* indexHead = NULL;
  insertIndex(&indexHead, 10, 20);
  insertIndex(&indexHead, 20, 30);
  insertIndex(&indexHead, 30, 40);
  insertIndex(&indexHead, 40, 50);

  searchIndex(indexHead, 20);

  return 0;
}