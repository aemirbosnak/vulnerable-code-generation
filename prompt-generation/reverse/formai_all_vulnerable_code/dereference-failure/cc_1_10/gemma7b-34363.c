//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HashNode {
  char *key;
  int hashValue;
  struct HashNode *next;
} HashNode;

typedef struct HashTable {
  HashNode **buckets;
  int size;
  int capacity;
} HashTable;

int hashFunction(char *key) {
  int hashValue = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hashValue = (hashValue * 33) + key[i];
  }
  return hashValue;
}

void insertNode(HashTable *table, char *key) {
  int hashValue = hashFunction(key);
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->key = strdup(key);
  newNode->hashValue = hashValue;
  newNode->next = NULL;

  if (table->buckets[hashValue] == NULL) {
    table->buckets[hashValue] = newNode;
  } else {
    HashNode *tempNode = table->buckets[hashValue];
    while (tempNode->next != NULL) {
      tempNode = tempNode->next;
    }
    tempNode->next = newNode;
  }
}

int main() {
  HashTable *table = malloc(sizeof(HashTable));
  table->buckets = (HashNode **)malloc(MAX_BUFFER_SIZE * sizeof(HashNode));
  table->size = 0;
  table->capacity = MAX_BUFFER_SIZE;

  insertNode(table, "a");
  insertNode(table, "b");
  insertNode(table, "c");
  insertNode(table, "d");

  for (int i = 0; i < table->size; i++) {
    printf("%s ", table->buckets[i]->key);
  }

  return 0;
}