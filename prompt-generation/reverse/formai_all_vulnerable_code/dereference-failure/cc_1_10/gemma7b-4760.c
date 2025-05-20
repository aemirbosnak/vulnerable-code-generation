//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  struct Node* next;
  char key[MAX_INDEX_SIZE];
  void* data;
} Node;

typedef struct Index {
  Node* head;
  int size;
} Index;

Index* createIndex(int size) {
  Index* index = (Index*)malloc(sizeof(Index));
  index->head = NULL;
  index->size = size;
  return index;
}

void insertIndex(Index* index, char* key, void* data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->next = NULL;
  strcpy(newNode->key, key);
  newNode->data = data;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    Node* current = index->head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  index->size++;
}

void searchIndex(Index* index, char* key) {
  Node* current = index->head;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      printf("Data: %p\n", current->data);
      return;
    }
    current = current->next;
  }

  printf("Key not found.\n");
}

int main() {
  Index* index = createIndex(10);
  insertIndex(index, "a", (void*)10);
  insertIndex(index, "b", (void*)20);
  insertIndex(index, "c", (void*)30);
  searchIndex(index, "b");

  return 0;
}