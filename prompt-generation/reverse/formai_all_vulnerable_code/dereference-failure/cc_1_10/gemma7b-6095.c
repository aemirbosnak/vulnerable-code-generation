//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
  char *key;
  int data_ptr;
  struct IndexEntry *next;
} IndexEntry;

IndexEntry *insert_index_entry(IndexEntry *head, char *key, int data_ptr) {
  IndexEntry *new_entry = malloc(sizeof(IndexEntry));
  new_entry->key = strdup(key);
  new_entry->data_ptr = data_ptr;
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    IndexEntry *prev = head;
    IndexEntry *curr = head;
    while (curr) {
      if (strcmp(curr->key, key) == 0) {
        return NULL;
      } else if (strcmp(curr->key, key) < 0) {
        prev = curr;
        curr = curr->next;
      } else {
        break;
      }
    }

    prev->next = new_entry;
  }

  return head;
}

int main() {
  IndexEntry *head = NULL;

  insert_index_entry(head, "a", 10);
  insert_index_entry(head, "b", 20);
  insert_index_entry(head, "c", 30);
  insert_index_entry(head, "d", 40);

  IndexEntry *curr = head;
  while (curr) {
    printf("%s: %d\n", curr->key, curr->data_ptr);
    curr = curr->next;
  }

  return 0;
}