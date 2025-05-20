//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define NUM_ENTRIES 10

typedef struct Entry {
  char name[20];
  int number;
  struct Entry* next;
} Entry;

Entry* createEntry(char* name, int number) {
  Entry* entry = malloc(sizeof(Entry));
  strcpy(entry->name, name);
  entry->number = number;
  entry->next = NULL;
  return entry;
}

void addEntry(Entry* head, char* name, int number) {
  Entry* newEntry = createEntry(name, number);
  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newEntry;
  }
}

void searchEntry(Entry* head, char* name) {
  Entry* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Name: %s, Number: %d\n", current->name, current->number);
      return;
    }
    current = current->next;
  }
  printf("Entry not found.\n");
}

int main() {
  Entry* head = NULL;
  addEntry(head, "John Doe", 123);
  addEntry(head, "Jane Doe", 456);
  addEntry(head, "Peter Pan", 987);
  addEntry(head, "Mary Poppins", 514);

  searchEntry(head, "Jane Doe");
  searchEntry(head, "John Doe");
  searchEntry(head, "Peter Pan");
  searchEntry(head, "Mary Poppins");

  return 0;
}