//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_INDEX_SIZE 1024
#define MAX_DATA_SIZE 1024

typedef struct Node {
  char data[MAX_DATA_SIZE];
  struct Node* next;
} Node;

typedef struct Index {
  char key[MAX_INDEX_SIZE];
  int offset;
  struct Index* next;
} Index;

Index* insertIndex(Index* head, char* key, int offset) {
  Index* newIndex = malloc(sizeof(Index));
  strcpy(newIndex->key, key);
  newIndex->offset = offset;
  newIndex->next = NULL;

  if (head == NULL) {
    head = newIndex;
  } else {
    Index* lastIndex = head;
    while (lastIndex->next) {
      lastIndex = lastIndex->next;
    }
    lastIndex->next = newIndex;
  }

  return head;
}

void searchIndex(Index* head, char* key) {
  Index* currentIndex = head;
  while (currentIndex) {
    if (strcmp(currentIndex->key, key) == 0) {
      printf("Offset: %d\n", currentIndex->offset);
      return;
    }
    currentIndex = currentIndex->next;
  }

  printf("Key not found.\n");
}

int main() {
  Index* head = NULL;
  head = insertIndex(head, "abc", 10);
  head = insertIndex(head, "def", 20);
  head = insertIndex(head, "ghi", 30);

  searchIndex(head, "abc");
  searchIndex(head, "def");
  searchIndex(head, "xyz");

  return 0;
}