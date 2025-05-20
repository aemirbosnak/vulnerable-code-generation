//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct Entry {
  char name[20];
  char number[20];
  struct Entry* next;
} Entry;

Entry* head = NULL;

void addEntry(char* name, char* number) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  strcpy(newEntry->number, number);
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    Entry* current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newEntry;
  }
}

void searchEntry(char* name) {
  Entry* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      printf("Name: %s\n", current->name);
      printf("Number: %s\n", current->number);
      return;
    }
    current = current->next;
  }
  printf("Entry not found.\n");
}

int main() {
  addEntry("John Doe", "123-456-7890");
  addEntry("Jane Doe", "456-789-0123");
  addEntry("Bill Smith", "321-456-7890");

  searchEntry("John Doe");
  searchEntry("Jane Doe");
  searchEntry("Bill Smith");
  searchEntry("Not Found");

  return 0;
}