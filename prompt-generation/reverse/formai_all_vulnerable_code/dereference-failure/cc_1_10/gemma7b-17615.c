//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  char data[255];
  struct Node* next;
} Node;

typedef struct Index {
  Node* head;
  int size;
  char key[MAX_INDEX_SIZE];
} Index;

Index* createIndex() {
  Index* index = malloc(sizeof(Index));
  index->head = NULL;
  index->size = 0;
  return index;
}

void addToIndex(Index* index, char* data) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    index->head->next = newNode;
  }

  index->size++;
}

void searchIndex(Index* index, char* key) {
  for (Node* node = index->head; node; node = node->next) {
    if (strcmp(node->data, key) == 0) {
      printf("Data: %s\n", node->data);
    }
  }
}

int main() {
  Index* index = createIndex();

  addToIndex(index, "Water");
  addToIndex(index, "Food");
  addToIndex(index, "Weapons");
  addToIndex(index, "Ammunition");

  searchIndex(index, "Food");

  return 0;
}