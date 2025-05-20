//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_HASH_SIZE 1000

typedef struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
} HashNode;

struct HashTable {
  HashNode **buckets;
  int size;
  int load_factor;
  int (*hash_function)(char *);
  int collisions;
};

int hash_function(char *key) {
  return (int) (key[0] * 3) % MAX_HASH_SIZE;
}

void insert(struct HashTable *ht, char *key, int value) {
  int hash_index = hash_function(key);
  HashNode *new_node = malloc(sizeof(HashNode));
  new_node->key = key;
  new_node->value = value;
  new_node->next = ht->buckets[hash_index] ? ht->buckets[hash_index] : NULL;
  ht->buckets[hash_index] = new_node;
  ht->collisions++;
}

int main() {
  struct HashTable *ht = malloc(sizeof(struct HashTable));
  ht->buckets = (HashNode **) malloc(MAX_HASH_SIZE * sizeof(HashNode *));
  ht->size = MAX_HASH_SIZE;
  ht->load_factor = 0.75;
  ht->hash_function = hash_function;
  ht->collisions = 0;

  insert(ht, "a", 10);
  insert(ht, "b", 20);
  insert(ht, "c", 30);
  insert(ht, "d", 40);
  insert(ht, "e", 50);

  printf("Collisions: %d\n", ht->collisions);

  return 0;
}