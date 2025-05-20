//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 10

typedef struct IndexEntry {
  char name[MAX_INDEX_SIZE];
  struct IndexEntry* next;
} IndexEntry;

IndexEntry* createIndexEntry(char* name) {
  IndexEntry* newEntry = (IndexEntry*)malloc(sizeof(IndexEntry));
  strcpy(newEntry->name, name);
  newEntry->next = NULL;
  return newEntry;
}

void addToIndex(IndexEntry* indexHead, char* name) {
  IndexEntry* newEntry = createIndexEntry(name);
  if (indexHead == NULL) {
    indexHead = newEntry;
  } else {
    indexHead->next = newEntry;
  }
}

int searchIndex(IndexEntry* indexHead, char* name) {
  IndexEntry* currentEntry = indexHead;
  while (currentEntry) {
    if (strcmp(currentEntry->name, name) == 0) {
      return 1;
    }
    currentEntry = currentEntry->next;
  }
  return 0;
}

int main() {
  IndexEntry* indexHead = NULL;
  addToIndex(indexHead, "Alice");
  addToIndex(indexHead, "Bob");
  addToIndex(indexHead, "Charlie");
  addToIndex(indexHead, "Diana");

  if (searchIndex(indexHead, "Bob") == 1) {
    printf("Bob is in the index.\n");
  }

  if (searchIndex(indexHead, "Foo") == 0) {
    printf("Foo is not in the index.\n");
  }

  return 0;
}