//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1024

typedef struct Entry {
  char name[256];
  int data;
  struct Entry* next;
} Entry;

Entry** hashTable = NULL;

void insertEntry(char* name, int data) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->data = data;
  newEntry->next = NULL;

  if (hashTable == NULL) {
    hashTable = malloc(sizeof(Entry**));
    *hashTable = NULL;
  }

  Entry** currentEntry = &(*hashTable);

  while (*currentEntry) {
    if (strcmp((*currentEntry)->name, name) == 0) {
      (*currentEntry)->data = data;
      return;
    }

    currentEntry = &((*currentEntry)->next);
  }

  *currentEntry = newEntry;
}

int getEntryData(char* name) {
  Entry* currentEntry = (*hashTable);

  while (currentEntry) {
    if (strcmp(currentEntry->name, name) == 0) {
      return currentEntry->data;
    }

    currentEntry = currentEntry->next;
  }

  return -1;
}

int main() {
  insertEntry("John Doe", 12);
  insertEntry("Jane Doe", 16);
  insertEntry("Bill Smith", 20);

  printf("Data for John Doe: %d\n", getEntryData("John Doe"));
  printf("Data for Jane Doe: %d\n", getEntryData("Jane Doe"));
  printf("Data for Bill Smith: %d\n", getEntryData("Bill Smith"));

  return 0;
}