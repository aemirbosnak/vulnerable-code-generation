//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  char name[256];
  struct Node* next;
} Node;

struct Index {
  Node* head;
  int size;
  time_t timestamp;
};

void insertIndex(struct Index* index, char* name) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->next = NULL;

  if (index->head == NULL) {
    index->head = newNode;
  } else {
    index->head->next = newNode;
  }

  index->size++;
  index->timestamp = time(NULL);
}

void searchIndex(struct Index* index, char* name) {
  Node* current = index->head;

  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Found name: %s\n", current->name);
      return;
    }

    current = current->next;
  }

  printf("Name not found.\n");
}

int main() {
  struct Index* index = malloc(sizeof(struct Index));
  index->head = NULL;
  index->size = 0;
  index->timestamp = time(NULL);

  insertIndex(index, "John Doe");
  insertIndex(index, "Jane Doe");
  insertIndex(index, "Jack Doe");

  searchIndex(index, "Jane Doe");

  return 0;
}