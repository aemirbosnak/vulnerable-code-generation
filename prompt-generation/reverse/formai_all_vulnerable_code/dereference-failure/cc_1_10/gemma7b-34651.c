//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
  char key[20];
  int data;
  struct IndexEntry* next;
} IndexEntry;

IndexEntry* insertIndexEntry(IndexEntry* head, char* key, int data) {
  IndexEntry* newEntry = malloc(sizeof(IndexEntry));
  strcpy(newEntry->key, key);
  newEntry->data = data;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    IndexEntry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newEntry;
  }

  return head;
}

int searchIndexEntry(IndexEntry* head, char* key) {
  IndexEntry* current = head;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      return current->data;
    }
    current = current->next;
  }

  return -1;
}

int main() {
  IndexEntry* indexHead = NULL;

  // Insert some index entries
  insertIndexEntry(indexHead, "John Doe", 12);
  insertIndexEntry(indexHead, "Jane Doe", 14);
  insertIndexEntry(indexHead, "Bill Smith", 16);
  insertIndexEntry(indexHead, "Mary Johnson", 18);

  // Search for an index entry
  int data = searchIndexEntry(indexHead, "John Doe");

  // Print the data
  if (data != -1) {
    printf("Data for key 'John Doe': %d\n", data);
  } else {
    printf("Key not found.\n");
  }

  return 0;
}