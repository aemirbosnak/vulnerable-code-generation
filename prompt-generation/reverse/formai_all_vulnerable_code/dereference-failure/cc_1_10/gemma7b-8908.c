//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: creative
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

Index* createIndex(int size) {
  Index* index = (Index*)malloc(sizeof(Index));
  index->head = NULL;
  index->size = size;
  return index;
}

void insertIndex(Index* index, char data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->data, &data);
  newNode->next = index->head;
  index->head = newNode;
  index->size++;
}

char searchIndex(Index* index, char data) {
  Node* current = index->head;
  while (current) {
    if (strcmp(current->data, &data) == 0) {
      return current->data[0];
    }
    current = current->next;
  }
  return '\0';
}

int main() {
  Index* index = createIndex(10);
  insertIndex(index, 'a');
  insertIndex(index, 'b');
  insertIndex(index, 'c');
  insertIndex(index, 'd');
  insertIndex(index, 'e');

  char result = searchIndex(index, 'c');
  if (result) {
    printf("%c", result);
  } else {
    printf("Data not found");
  }

  return 0;
}