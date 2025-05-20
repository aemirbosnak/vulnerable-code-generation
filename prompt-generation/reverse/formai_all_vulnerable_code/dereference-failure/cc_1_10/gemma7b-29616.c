//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  char name[256];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  int (*compare)(char*, char*);
  void (*insert)(char*);
  void (*search)(char*);
};

struct Index* createIndex(int (*compare)(char*, char*), void (*insert)(char*), void (*search)(char*)) {
  struct Index* index = malloc(sizeof(struct Index));
  index->head = NULL;
  index->size = 0;
  index->compare = compare;
  index->insert = insert;
  index->search = search;
  return index;
}

void insertIndex(struct Index* index, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

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

void searchIndex(struct Index* index, char* name) {
  Node* current = index->head;
  while (current) {
    if (index->compare(name, current->name) == 0) {
      printf("%s found!\n", current->name);
      return;
    }
    current = current->next;
  }

  printf("%s not found.\n", name);
}

int main() {
  struct Index* index = createIndex(strcmp, insertIndex, searchIndex);

  insertIndex(index, "John Doe");
  insertIndex(index, "Jane Doe");
  insertIndex(index, "Peter Pan");

  searchIndex(index, "John Doe");
  searchIndex(index, "Peter Pan");

  return 0;
}