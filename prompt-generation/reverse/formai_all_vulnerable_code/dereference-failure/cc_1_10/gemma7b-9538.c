//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
  char name[50];
  int number;
  struct Entry* next;
} Entry;

Entry* insertEntry(Entry* head, char* name, int number) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->number = number;
  newEntry->next = NULL;

  if (head == NULL) {
    return newEntry;
  }

  Entry* current = head;
  Entry* previous = NULL;

  while (current) {
    if (strcmp(current->name, name) < 0) {
      previous = current;
      current = current->next;
    } else {
      break;
    }
  }

  if (previous) {
    previous->next = newEntry;
  } else {
    head = newEntry;
  }

  return head;
}

int main() {
  Entry* head = NULL;

  insertEntry(head, "Donald Knuth", 1234);
  insertEntry(head, "John Doe", 5432);
  insertEntry(head, "Alice Smith", 3214);
  insertEntry(head, "Bob Brown", 6541);

  Entry* current = head;

  while (current) {
    printf("%s: %d\n", current->name, current->number);
    current = current->next;
  }

  return 0;
}