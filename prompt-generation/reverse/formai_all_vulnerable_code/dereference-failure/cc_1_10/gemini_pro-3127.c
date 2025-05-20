//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int key;
  void *value;
  struct node *next;
} node;

typedef struct hashtable {
  int size;
  node **table;
} hashtable;

hashtable *create_hashtable(int size) {
  hashtable *ht = (hashtable *)malloc(sizeof(hashtable));
  ht->size = size;
  ht->table = (node **)calloc(size, sizeof(node *));
  return ht;
}

void insert(hashtable *ht, int key, void *value) {
  int index = key % ht->size;
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->value = value;
  new_node->next = ht->table[index];
  ht->table[index] = new_node;
}

void *get(hashtable *ht, int key) {
  int index = key % ht->size;
  node *current = ht->table[index];
  while (current) {
    if (current->key == key) {
      return current->value;
    }
    current = current->next;
  }
  return NULL;
}

void print_hashtable(hashtable *ht) {
  for (int i = 0; i < ht->size; i++) {
    node *current = ht->table[i];
    while (current) {
      printf("(%d, %d) -> ", current->key, current->value);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  hashtable *ht = create_hashtable(10);
  insert(ht, 1, "One");
  insert(ht, 2, "Two");
  insert(ht, 3, "Three");
  insert(ht, 4, "Four");
  insert(ht, 5, "Five");
  print_hashtable(ht);
  printf("Value of key 3: %s\n", (char *)get(ht, 3));
  return 0;
}