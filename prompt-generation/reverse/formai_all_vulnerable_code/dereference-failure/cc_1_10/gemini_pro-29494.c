//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int key;
  struct node *next;
} node;

typedef struct hashtable {
  int size;
  node **table;
} hashtable;

hashtable *create_hashtable(int size) {
  hashtable *ht = (hashtable *)malloc(sizeof(hashtable));
  ht->size = size;
  ht->table = (node **)malloc(sizeof(node *) * size);
  for (int i = 0; i < size; i++) {
    ht->table[i] = NULL;
  }
  return ht;
}

void insert(hashtable *ht, int key) {
  int index = key % ht->size;
  node *new_node = (node *)malloc(sizeof(node));
  new_node->key = key;
  new_node->next = ht->table[index];
  ht->table[index] = new_node;
}

int search(hashtable *ht, int key) {
  int index = key % ht->size;
  node *current = ht->table[index];
  while (current != NULL) {
    if (current->key == key) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

void delete(hashtable *ht, int key) {
  int index = key % ht->size;
  node *current = ht->table[index];
  node *previous = NULL;
  while (current != NULL) {
    if (current->key == key) {
      if (previous == NULL) {
        ht->table[index] = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void print_hashtable(hashtable *ht) {
  for (int i = 0; i < ht->size; i++) {
    node *current = ht->table[i];
    printf("%d: ", i);
    while (current != NULL) {
      printf("%d -> ", current->key);
      current = current->next;
    }
    printf("\n");
  }
}

int main() {
  hashtable *ht = create_hashtable(10);
  insert(ht, 1);
  insert(ht, 2);
  insert(ht, 3);
  insert(ht, 4);
  insert(ht, 5);
  insert(ht, 6);
  insert(ht, 7);
  insert(ht, 8);
  insert(ht, 9);
  insert(ht, 10);
  print_hashtable(ht);
  printf("Searching for 5: %d\n", search(ht, 5));
  printf("Searching for 11: %d\n", search(ht, 11));
  delete(ht, 5);
  print_hashtable(ht);
  return 0;
}