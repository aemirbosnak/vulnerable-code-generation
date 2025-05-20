//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  char data[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

typedef struct Index {
  Node* head;
  int size;
} Index;

Index* createIndex() {
  Index* index = (Index*)malloc(sizeof(Index));
  index->head = NULL;
  index->size = 0;
  return index;
}

void insertIndex(Index* index, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data[0] = data;
  newNode->next = NULL;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    index->head->next = newNode;
  }

  index->size++;
}

void searchIndex(Index* index, char data) {
  Node* current = index->head;
  while (current) {
    if (current->data[0] == data) {
      printf("Data found: %c\n", data);
      return;
    }
    current = current->next;
  }

  printf("Data not found: %c\n", data);
}

int main() {
  Index* index = createIndex();

  insertIndex(index, 'a');
  insertIndex(index, 'b');
  insertIndex(index, 'c');
  insertIndex(index, 'd');

  searchIndex(index, 'b');
  searchIndex(index, 'e');

  return 0;
}