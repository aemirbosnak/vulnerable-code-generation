//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct HashTable {
  int size;
  Node** buckets;
} HashTable;

void ht_init(HashTable* ht) {
  ht->size = MAX_SIZE;
  ht->buckets = (Node**)malloc(MAX_SIZE * sizeof(Node*));
  for (int i = 0; i < MAX_SIZE; i++) {
    ht->buckets[i] = NULL;
  }
}

int ht_insert(HashTable* ht, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  int hash = data % ht->size;
  if (ht->buckets[hash] == NULL) {
    ht->buckets[hash] = newNode;
  } else {
    Node* temp = ht->buckets[hash];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return 0;
}

int main() {
  HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
  ht_init(ht);

  ht_insert(ht, 10);
  ht_insert(ht, 20);
  ht_insert(ht, 30);
  ht_insert(ht, 40);

  Node* search = ht->buckets[10];
  while (search) {
    printf("%d ", search->data);
    search = search->next;
  }

  return 0;
}