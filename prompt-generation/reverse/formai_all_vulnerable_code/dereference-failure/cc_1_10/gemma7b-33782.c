//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct HashTable {
  char **keys;
  int **values;
  int size;
  int capacity;
} HashTable;

int hashFunction(char *key) {
  int hash = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hash = (hash * 33) + key[i];
  }
  return hash;
}

void insertIntoHashTable(HashTable *table, char *key, int value) {
  int hash = hashFunction(key);
  table->keys[hash] = key;
  table->values[hash] = value;
}

int getFromHashTable(HashTable *table, char *key) {
  int hash = hashFunction(key);
  if (table->keys[hash] != NULL && strcmp(table->keys[hash], key) == 0) {
    return table->values[hash];
  } else {
    return -1;
  }
}

int main() {
  HashTable *table = malloc(sizeof(HashTable));
  table->keys = malloc(MAX_BUFFER_SIZE * sizeof(char *));
  table->values = malloc(MAX_BUFFER_SIZE * sizeof(int));
  table->size = 0;
  table->capacity = MAX_BUFFER_SIZE;

  insertIntoHashTable(table, "abc", 10);
  insertIntoHashTable(table, "def", 20);
  insertIntoHashTable(table, "ghi", 30);

  printf("%d", getFromHashTable(table, "abc"));
  printf("%d", getFromHashTable(table, "def"));
  printf("%d", getFromHashTable(table, "ghi"));

  return 0;
}