//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct Node {
  char data[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  int (*compare)(const void*, const void*);
  void (*insert)(const void*);
  void (*delete)(const void*);
};

void insert_index(struct Index* index, const void* data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data[0] = '\0';
  strcpy(newNode->data, (char*)data);
  newNode->next = NULL;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    index->head->next = newNode;
  }

  index->size++;
}

void delete_index(struct Index* index, const void* data) {
  Node* current = index->head;
  Node* previous = NULL;

  while (current) {
    if (strcmp(current->data, (char*)data) == 0) {
      if (previous) {
        previous->next = current->next;
      } else {
        index->head = current->next;
      }

      free(current);
      index->size--;
      return;
    }

    previous = current;
    current = current->next;
  }

  printf("Error: Data not found.\n");
}

int compare_strings(const void* a, const void* b) {
  return strcmp((char*)a, (char*)b);
}

int main() {
  struct Index* index = malloc(sizeof(struct Index));
  index->head = NULL;
  index->size = 0;
  index->compare = compare_strings;
  index->insert = insert_index;
  index->delete = delete_index;

  insert_index(index, "John Doe");
  insert_index(index, "Jane Doe");
  insert_index(index, "Peter Pan");

  delete_index(index, "Jane Doe");

  for (Node* current = index->head; current; current = current->next) {
    printf("%s\n", current->data);
  }

  return 0;
}