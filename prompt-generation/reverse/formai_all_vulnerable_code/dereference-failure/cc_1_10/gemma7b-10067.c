//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: optimized
#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE 1024

typedef struct HashEntry {
  uint32_t key;
  uint32_t value;
  struct HashEntry* next;
} HashEntry;

typedef struct HashTable {
  HashEntry** buckets;
  int size;
  int capacity;
} HashTable;

uint32_t hash(uint32_t key) {
  return key % MAX_SIZE;
}

void insert(HashTable* ht, uint32_t key, uint32_t value) {
  uint32_t bucket = hash(key);
  HashEntry* newEntry = malloc(sizeof(HashEntry));
  newEntry->key = key;
  newEntry->value = value;
  newEntry->next = ht->buckets[bucket] ? ht->buckets[bucket] : NULL;
  ht->buckets[bucket] = newEntry;
}

uint32_t get(HashTable* ht, uint32_t key) {
  uint32_t bucket = hash(key);
  HashEntry* currentEntry = ht->buckets[bucket];
  while (currentEntry) {
    if (currentEntry->key == key) {
      return currentEntry->value;
    }
    currentEntry = currentEntry->next;
  }
  return -1;
}

int main() {
  HashTable* ht = malloc(sizeof(HashTable));
  ht->buckets = (HashEntry**)malloc(MAX_SIZE * sizeof(HashEntry*));
  ht->size = 0;
  ht->capacity = MAX_SIZE;

  insert(ht, 1, 10);
  insert(ht, 2, 20);
  insert(ht, 3, 30);
  insert(ht, 4, 40);

  printf("%d", get(ht, 2)); // Output: 20

  return 0;
}