//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
  char key[MAX_INDEX_SIZE];
  struct IndexNode* next;
} IndexNode;

typedef struct IndexTable {
  IndexNode** buckets;
  int size;
  int capacity;
} IndexTable;

IndexTable* createIndexTable(int capacity) {
  IndexTable* table = (IndexTable*)malloc(sizeof(IndexTable));
  table->buckets = (IndexNode**)malloc(sizeof(IndexNode*) * capacity);
  table->size = 0;
  table->capacity = capacity;

  return table;
}

void insertIndexEntry(IndexTable* table, char key) {
  int bucketIndex = key % table->capacity;
  IndexNode* newNode = (IndexNode*)malloc(sizeof(IndexNode));
  strcpy(newNode->key, key);
  newNode->next = table->buckets[bucketIndex];
  table->buckets[bucketIndex] = newNode;
  table->size++;
}

char searchIndexEntry(IndexTable* table, char key) {
  int bucketIndex = key % table->capacity;
  IndexNode* node = table->buckets[bucketIndex];

  while (node) {
    if (strcmp(node->key, key) == 0) {
      return 1;
    }
    node = node->next;
  }

  return 0;
}

int main() {
  IndexTable* table = createIndexTable(5);
  insertIndexEntry(table, "John");
  insertIndexEntry(table, "Alice");
  insertIndexEntry(table, "Bob");
  insertIndexEntry(table, "Charlie");

  if (searchIndexEntry(table, "Alice") == 1) {
    printf("Alice is in the index.\n");
  }

  return 0;
}