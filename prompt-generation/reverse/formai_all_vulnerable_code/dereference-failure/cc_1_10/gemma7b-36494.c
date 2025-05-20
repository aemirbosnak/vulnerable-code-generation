//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct HashTable {
  struct Node** buckets;
  int size;
  int capacity;
};

void insert(struct HashTable* ht, int data) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (ht->buckets[data] == NULL) {
    ht->buckets[data] = newNode;
  } else {
    struct Node* temp = ht->buckets[data];
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void traverse(struct HashTable* ht) {
  for (int i = 0; i < ht->size; i++) {
    if (ht->buckets[i] != NULL) {
      struct Node* temp = ht->buckets[i];
      while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
      }
      printf("\n");
    }
  }
}

int main() {
  struct HashTable* ht = malloc(sizeof(struct HashTable));
  ht->size = 10;
  ht->capacity = 10;
  ht->buckets = (struct Node**)malloc(ht->size * sizeof(struct Node*));

  insert(ht, 10);
  insert(ht, 20);
  insert(ht, 30);
  insert(ht, 40);
  insert(ht, 50);

  traverse(ht);

  return 0;
}