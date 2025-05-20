//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 1024

typedef struct IndexEntry {
  char *key;
  struct IndexEntry *next;
} IndexEntry;

IndexEntry **createIndex(void) {
  IndexEntry **head = (IndexEntry **)malloc(sizeof(IndexEntry *) * MAX_INDEX_ENTRIES);
  *head = NULL;
  return head;
}

void addToIndex(IndexEntry **head, char *key) {
  IndexEntry *newEntry = (IndexEntry *)malloc(sizeof(IndexEntry));
  newEntry->key = strdup(key);
  newEntry->next = NULL;

  if (*head == NULL) {
    *head = newEntry;
  } else {
    (*head)->next = newEntry;
  }
}

int searchIndex(IndexEntry **head, char *key) {
  for (IndexEntry *currentEntry = *head; currentEntry; currentEntry = currentEntry->next) {
    if (strcmp(currentEntry->key, key) == 0) {
      return 1;
    }
  }

  return 0;
}

int main() {
  IndexEntry **index = createIndex();

  addToIndex(index, "John Doe");
  addToIndex(index, "Jane Doe");
  addToIndex(index, "Bill Smith");

  if (searchIndex(index, "John Doe")) {
    printf("John Doe is in the index.\n");
  }

  if (searchIndex(index, "Bob White")) {
    printf("Bob White is in the index.\n");
  }

  return 0;
}