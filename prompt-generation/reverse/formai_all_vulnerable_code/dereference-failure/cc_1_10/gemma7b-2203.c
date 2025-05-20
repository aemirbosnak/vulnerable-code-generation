//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>
#include <stdint.h>

#define HASH_SIZE 256

typedef struct HashEntry {
  uint32_t key;
  struct HashEntry* next;
} HashEntry;

HashEntry* hash_insert(HashEntry* head, uint32_t key) {
  HashEntry* new_entry = malloc(sizeof(HashEntry));
  new_entry->key = key;
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    HashEntry* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_entry;
  }

  return head;
}

uint32_t hash_lookup(HashEntry* head, uint32_t key) {
  HashEntry* current = head;
  while (current) {
    if (current->key == key) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  HashEntry* head = NULL;
  head = hash_insert(head, 12);
  head = hash_insert(head, 23);
  head = hash_insert(head, 4);

  if (hash_lookup(head, 4)) {
    printf("Key 4 found.\n");
  }

  return 0;
}