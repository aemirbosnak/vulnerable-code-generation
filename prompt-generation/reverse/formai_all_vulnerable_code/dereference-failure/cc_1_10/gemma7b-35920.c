//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 256

struct hash_node {
  char *key;
  int value;
  struct hash_node *next;
};

struct hash_table {
  struct hash_node **buckets;
  int size;
  int load_factor;
};

int hash(char *key) {
  int hash_value = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash_value = (hash_value * 33) + key[i];
  }
  return hash_value % HASH_SIZE;
}

void insert(struct hash_table *ht, char *key, int value) {
  int bucket = hash(key);
  struct hash_node *node = malloc(sizeof(struct hash_node));
  node->key = strdup(key);
  node->value = value;
  node->next = ht->buckets[bucket] ? ht->buckets[bucket] : NULL;
  ht->buckets[bucket] = node;
  ht->size++;
}

int main() {
  struct hash_table *ht = malloc(sizeof(struct hash_table));
  ht->buckets = (struct hash_node **)malloc(HASH_SIZE * sizeof(struct hash_node *));
  ht->size = 0;
  ht->load_factor = 0;

  insert(ht, "foo", 10);
  insert(ht, "bar", 20);
  insert(ht, "baz", 30);

  struct hash_node *node = ht->buckets[hash("foo")];
  if (node) {
    printf("Value for key 'foo': %d\n", node->value);
  }

  free(ht->buckets);
  free(ht);

  return 0;
}