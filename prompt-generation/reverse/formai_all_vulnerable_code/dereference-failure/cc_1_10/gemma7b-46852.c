//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct Entry {
  char name[20];
  char number[20];
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name, char* number) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->number, number);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = newEntry;
  }

  return head;
}

Entry* findEntry(Entry* head, char* name) {
  while (head) {
    if (strcmp(head->name, name) == 0) {
      return head;
    }
    head = head->next;
  }

  return NULL;
}

int main() {
  Entry* head = NULL;

  insertEntry(head, "John Doe", "123-456-7890");
  insertEntry(head, "Jane Doe", "456-789-0123");
  insertEntry(head, "Bill Smith", "321-456-7890");

  Entry* entry = findEntry(head, "John Doe");

  if (entry) {
    printf("Name: %s\n", entry->name);
    printf("Number: %s\n", entry->number);
  } else {
    printf("Entry not found.\n");
  }

  return 0;
}