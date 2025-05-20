//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct Entry {
  char name[MAX_ENTRIES];
  int index;
  struct Entry* next;
} Entry;

Entry* insert(Entry* head, char* name) {
  Entry* newEntry = malloc(sizeof(Entry));
  strcpy(newEntry->name, name);
  newEntry->index = rand() % MAX_ENTRIES;
  newEntry->next = NULL;

  if (head == NULL) {
    head = newEntry;
  } else {
    head->next = insert(head->next, name);
  }

  return head;
}

int search(Entry* head, char* name) {
  for (Entry* current = head; current; current = current->next) {
    if (strcmp(current->name, name) == 0) {
      return current->index;
    }
  }

  return -1;
}

int main() {
  Entry* head = NULL;

  // Insert some entries
  insert(head, "Donald Knuth");
  insert(head, "Bob Ross");
  insert(head, "Steve Jobs");
  insert(head, "Bill Gates");

  // Search for an entry
  int index = search(head, "Steve Jobs");

  // Print the index
  if (index != -1) {
    printf("Index of Steve Jobs: %d\n", index);
  } else {
    printf("Entry not found.\n");
  }

  return 0;
}