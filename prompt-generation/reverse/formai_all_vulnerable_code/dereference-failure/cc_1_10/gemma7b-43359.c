//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

typedef struct HashEntry {
  char *key;
  void *data;
  struct HashEntry *next;
} HashEntry;

HashEntry **hash_table = NULL;

void hash_add(char *key, void *data) {
  HashEntry *new_entry = malloc(sizeof(HashEntry));
  new_entry->key = strdup(key);
  new_entry->data = data;
  new_entry->next = NULL;

  if (hash_table == NULL) {
    hash_table = new_entry;
  } else {
    HashEntry *current = hash_table;
    HashEntry *previous = NULL;
    while (current) {
      if (strcmp(key, current->key) == 0) {
        previous->next = new_entry;
        return;
      } else if (previous == NULL) {
        previous = current;
        current = current->next;
      } else {
        previous = current;
        current = current->next;
      }
    }

    previous->next = new_entry;
  }
}

void hash_print() {
  HashEntry *current = hash_table;
  while (current) {
    printf("%s: %p\n", current->key, current->data);
    current = current->next;
  }
}

int main() {
  hash_add("John Doe", (void *)123);
  hash_add("Jane Doe", (void *)456);
  hash_add("Peter Pan", (void *)789);

  hash_print();

  return 0;
}