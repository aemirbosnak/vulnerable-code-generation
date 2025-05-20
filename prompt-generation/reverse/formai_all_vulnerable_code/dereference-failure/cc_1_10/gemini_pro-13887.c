//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  char *key;
  int value;
  struct Node *next;
};

struct HashTable {
  struct Node **table;
  int size;
};

struct HashTable *create_hash_table(int size) {
  struct HashTable *ht = malloc(sizeof(struct HashTable));
  ht->table = malloc(sizeof(struct Node *) * size);
  ht->size = size;
  for (int i = 0; i < size; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

int hash_function(char *key, int size) {
  int hash = 0;
  for (int i = 0; i < strlen(key); i++) {
    hash += key[i];
  }
  return hash % size;
}

void insert_into_hash_table(struct HashTable *ht, char *key, int value) {
  int index = hash_function(key, ht->size);
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = ht->table[index];
  ht->table[index] = new_node;
}

int get_from_hash_table(struct HashTable *ht, char *key) {
  int index = hash_function(key, ht->size);
  struct Node *node = ht->table[index];
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    node = node->next;
  }
  return -1;
}

void print_hash_table(struct HashTable *ht) {
  for (int i = 0; i < ht->size; i++) {
    struct Node *node = ht->table[i];
    while (node != NULL) {
      printf("%s: %d\n", node->key, node->value);
      node = node->next;
    }
  }
}

int main() {
  struct HashTable *ht = create_hash_table(10);
  insert_into_hash_table(ht, "Alice", 1);
  insert_into_hash_table(ht, "Bob", 2);
  insert_into_hash_table(ht, "Carol", 3);
  insert_into_hash_table(ht, "Dave", 4);
  insert_into_hash_table(ht, "Eve", 5);

  print_hash_table(ht);

  return 0;
}