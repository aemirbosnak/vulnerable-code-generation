//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX 10

typedef struct Node {
  char name[20];
  struct Node* next;
} Node;

struct Index {
  Node** buckets;
  int size;
  int max_size;
  int (*compare)(const void*, const void*);
  void (*print)(const void*);
};

void insert(struct Index* index, char* name) {
  int hash = index->compare(name, NULL) % index->max_size;
  Node* node = malloc(sizeof(Node));
  strcpy(node->name, name);
  node->next = NULL;

  if (index->buckets[hash] == NULL) {
    index->buckets[hash] = node;
  } else {
    Node* temp = index->buckets[hash];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = node;
  }
}

void print_index(struct Index* index) {
  for (int i = 0; i < index->max_size; i++) {
    if (index->buckets[i] != NULL) {
      Node* temp = index->buckets[i];
      while (temp) {
        printf("%s ", temp->name);
        temp = temp->next;
      }
      printf("\n");
    }
  }
}

int main() {
  struct Index* index = malloc(sizeof(struct Index));
  index->size = 0;
  index->max_size = MAX_INDEX;
  index->compare = strcmp;
  index->print = print_index;

  insert(index, "John Doe");
  insert(index, "Jane Doe");
  insert(index, "Peter Pan");

  print_index(index);

  return 0;
}