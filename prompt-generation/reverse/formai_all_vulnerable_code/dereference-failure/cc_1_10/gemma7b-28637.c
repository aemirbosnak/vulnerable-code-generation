//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct HashTable {
  Node** buckets;
  int size;
  int capacity;
  int num_elements;
};

void insert(struct HashTable* ht, int data) {
  int hash = data % ht->size;
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;

  if (ht->buckets[hash] == NULL) {
    ht->buckets[hash] = node;
  } else {
    Node* temp = ht->buckets[hash];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = node;
  }

  ht->num_elements++;
}

struct HashTable* create_hash_table(int size) {
  struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
  ht->buckets = (Node**)malloc(size * sizeof(Node*));
  ht->size = size;
  ht->capacity = size;
  ht->num_elements = 0;

  return ht;
}

int main() {
  struct HashTable* ht = create_hash_table(10);
  insert(ht, 10);
  insert(ht, 20);
  insert(ht, 30);
  insert(ht, 40);
  insert(ht, 50);

  Node* node = ht->buckets[1];
  while (node) {
    printf("%d ", node->data);
    node = node->next;
  }

  return 0;
}