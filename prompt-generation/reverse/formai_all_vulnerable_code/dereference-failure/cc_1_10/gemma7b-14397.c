//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  char key[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

struct IndexSystem {
  Node** buckets;
  int numBuckets;
  int size;
  char** searchResults;
  int searchResultsSize;
};

void initializeIndexSystem(struct IndexSystem* system) {
  system->buckets = NULL;
  system->numBuckets = 0;
  system->size = 0;
  system->searchResults = NULL;
  system->searchResultsSize = 0;
}

void insertIndexEntry(struct IndexSystem* system, char* key) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (system->buckets == NULL) {
    system->buckets = (Node**)malloc(sizeof(Node*) * system->numBuckets);
    system->numBuckets++;
  }

  system->buckets[system->size++] = newNode;
}

void searchIndex(struct IndexSystem* system, char* key) {
  for (int i = 0; i < system->size; i++) {
    if (strcmp(system->buckets[i]->key, key) == 0) {
      system->searchResultsSize++;
      system->searchResults = (char**)realloc(system->searchResults, system->searchResultsSize * sizeof(char*));
      system->searchResults[system->searchResultsSize - 1] = key;
    }
  }
}

int main() {
  struct IndexSystem* system = malloc(sizeof(struct IndexSystem));
  initializeIndexSystem(system);

  insertIndexEntry(system, "John Doe");
  insertIndexEntry(system, "Jane Doe");
  insertIndexEntry(system, "Peter Pan");

  searchIndex(system, "Jane Doe");

  for (int i = 0; i < system->searchResultsSize; i++) {
    printf("%s\n", system->searchResults[i]);
  }

  return 0;
}