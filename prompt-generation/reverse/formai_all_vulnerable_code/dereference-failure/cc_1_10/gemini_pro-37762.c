//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int key;
  char *value;
  struct node *next;
} node_t;

typedef struct hash_table {
  int size;
  node_t **table;
} hash_table_t;

hash_table_t *create_hash_table(int size) {
  hash_table_t *hash_table = malloc(sizeof(hash_table_t));
  hash_table->size = size;
  hash_table->table = malloc(sizeof(node_t *) * size);
  for (int i = 0; i < size; i++) {
    hash_table->table[i] = NULL;
  }
  return hash_table;
}

void destroy_hash_table(hash_table_t *hash_table) {
  for (int i = 0; i < hash_table->size; i++) {
    node_t *node = hash_table->table[i];
    while (node) {
      node_t *next = node->next;
      free(node->value);
      free(node);
      node = next;
    }
  }
  free(hash_table->table);
  free(hash_table);
}

int hash_function(int key, int size) {
  return key % size;
}

void insert_into_hash_table(hash_table_t *hash_table, int key, char *value) {
  int index = hash_function(key, hash_table->size);
  node_t *node = malloc(sizeof(node_t));
  node->key = key;
  node->value = malloc(strlen(value) + 1);
  strcpy(node->value, value);
  node->next = hash_table->table[index];
  hash_table->table[index] = node;
}

char *get_from_hash_table(hash_table_t *hash_table, int key) {
  int index = hash_function(key, hash_table->size);
  node_t *node = hash_table->table[index];
  while (node) {
    if (node->key == key) {
      return node->value;
    }
    node = node->next;
  }
  return NULL;
}

void print_hash_table(hash_table_t *hash_table) {
  for (int i = 0; i < hash_table->size; i++) {
    node_t *node = hash_table->table[i];
    while (node) {
      printf("key: %d, value: %s\n", node->key, node->value);
      node = node->next;
    }
  }
}

int main() {
  hash_table_t *hash_table = create_hash_table(10);

  insert_into_hash_table(hash_table, 1, "one");
  insert_into_hash_table(hash_table, 2, "two");
  insert_into_hash_table(hash_table, 3, "three");
  insert_into_hash_table(hash_table, 4, "four");
  insert_into_hash_table(hash_table, 5, "five");

  print_hash_table(hash_table);

  char *value = get_from_hash_table(hash_table, 3);
  printf("The value for the key 3 is: %s\n", value);

  destroy_hash_table(hash_table);

  return 0;
}