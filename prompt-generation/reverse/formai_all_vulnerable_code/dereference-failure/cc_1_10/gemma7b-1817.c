//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char name[20];
  int index;
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name) {
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->index = head->index + 1;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

int searchEntry(Entry* head, char* name) {
  for (Entry* currentEntry = head; currentEntry; currentEntry = currentEntry->next) {
    if (strcmp(currentEntry->name, name) == 0) {
      return currentEntry->index;
    }
  }

  return -1;
}

int main() {
  Entry* head = NULL;

  insertEntry(head, "John Doe");
  insertEntry(head, "Jane Doe");
  insertEntry(head, "Bill Smith");
  insertEntry(head, "Mary Johnson");

  int index = searchEntry(head, "Bill Smith");

  if (index != -1) {
    printf("Index of Bill Smith: %d\n", index);
  } else {
    printf("Bill Smith not found.\n");
  }

  return 0;
}