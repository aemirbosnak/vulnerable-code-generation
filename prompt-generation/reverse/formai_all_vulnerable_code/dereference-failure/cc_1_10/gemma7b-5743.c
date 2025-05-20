//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 100

typedef struct Node {
  char data[MAX_INDEX_SIZE];
  struct Node* next;
} Node;

struct HashTable {
  int size;
  Node** buckets;
  int (*compare)(char*, char*);
  void (*insert)(char*);
  char* (*find)(char*);
};

void hash_table_init(struct HashTable* ht, int size, int (*compare)(char*, char*), void (*insert)(char*), char* (*find)(char*)) {
  ht->size = size;
  ht->buckets = (Node**)malloc(size * sizeof(Node*));
  ht->compare = compare;
  ht->insert = insert;
  ht->find = find;
}

void hash_table_insert(struct HashTable* ht, char* data) {
  int hash = ht->compare(data, "");
  Node* node = (Node*)malloc(sizeof(Node));
  strcpy(node->data, data);
  node->next = ht->buckets[hash] ? ht->buckets[hash] : NULL;
  ht->buckets[hash] = node;
}

char* hash_table_find(struct HashTable* ht, char* data) {
  int hash = ht->compare(data, "");
  for (Node* node = ht->buckets[hash]; node; node = node->next) {
    if (strcmp(node->data, data) == 0) {
      return node->data;
    }
  }
  return NULL;
}

int main() {
  struct HashTable* ht = NULL;
  hash_table_init(ht, 10, strcmp, hash_table_insert, hash_table_find);

  hash_table_insert(ht, "John Doe");
  hash_table_insert(ht, "Jane Doe");
  hash_table_insert(ht, "Peter Pan");

  char* data = hash_table_find(ht, "Jane Doe");
  if (data) {
    printf("%s", data);
  } else {
    printf("Data not found");
  }

  return 0;
}