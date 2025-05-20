//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* next;
  struct Node* prev;
};

struct Index {
  struct Node* head;
  struct Index* next;
  struct Index* prev;
  int level;
  char key;
};

void insertIndex(struct Index* index, char key, int level) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = key;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (index == NULL) {
    index = (struct Index*)malloc(sizeof(struct Index));
    index->head = newNode;
    index->next = NULL;
    index->prev = NULL;
    index->level = level;
    index->key = key;
  } else {
    insertIndex(index->next, key, level + 1);
  }
}

void traverseIndex(struct Index* index) {
  struct Node* node = index->head;
  while (node) {
    printf("%c ", node->data);
    traverseIndex(index->next);
  }
}

int main() {
  struct Index* index = NULL;
  insertIndex(index, 'a', 0);
  insertIndex(index, 'b', 1);
  insertIndex(index, 'c', 2);
  insertIndex(index, 'd', 3);
  insertIndex(index, 'e', 4);

  traverseIndex(index);

  return 0;
}