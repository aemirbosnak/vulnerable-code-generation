//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INDEX_ENTRIES 100

typedef struct IndexEntry {
  char key[20];
  int data_ptr;
  struct IndexEntry* next;
} IndexEntry;

IndexEntry* insert_index_entry(IndexEntry* head, char* key, int data_ptr) {
  IndexEntry* new_entry = malloc(sizeof(IndexEntry));
  strcpy(new_entry->key, key);
  new_entry->data_ptr = data_ptr;
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    IndexEntry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_entry;
  }

  return head;
}

int search_index(IndexEntry* head, char* key) {
  IndexEntry* current = head;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      return current->data_ptr;
    }
    current = current->next;
  }

  return -1;
}

int main() {
  IndexEntry* head = NULL;
  head = insert_index_entry(head, "John Doe", 12);
  head = insert_index_entry(head, "Jane Doe", 23);
  head = insert_index_entry(head, "Peter Pan", 45);

  int data_ptr = search_index(head, "Jane Doe");
  if (data_ptr != -1) {
    printf("Data pointer for Jane Doe: %d\n", data_ptr);
  }

  return 0;
}