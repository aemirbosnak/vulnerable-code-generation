//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

struct HashTable {
  Node** buckets;
  int size;
  int loadFactor;
  int capacity;
  int numBuckets;
  int collisions;
};

void insert(struct HashTable* ht, int data) {
  int hash = data % ht->numBuckets;
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = ht->buckets[hash];
  ht->buckets[hash] = node;
  ht->collisions++;
}

int search(struct HashTable* ht, int data) {
  int hash = data % ht->numBuckets;
  Node* current = ht->buckets[hash];
  while (current) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

int main() {
  struct HashTable* ht = (struct HashTable*)malloc(sizeof(struct HashTable));
  ht->size = MAX_INDEX;
  ht->loadFactor = 0.75;
  ht->capacity = 10;
  ht->numBuckets = 11;
  ht->collisions = 0;

  insert(ht, 10);
  insert(ht, 20);
  insert(ht, 30);
  insert(ht, 40);
  insert(ht, 50);
  insert(ht, 60);
  insert(ht, 70);
  insert(ht, 80);
  insert(ht, 90);
  insert(ht, 100);

  printf("Number of collisions: %d\n", ht->collisions);

  if (search(ht, 20) == 1) {
    printf("Item found: 20\n");
  }

  return 0;
}