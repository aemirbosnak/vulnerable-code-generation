//Gemma-7B DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1024

struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
};

struct HashNode **hashTable = NULL;

void insertHashNode(char *key, int value) {
  struct HashNode *newNode = (struct HashNode *)malloc(sizeof(struct HashNode));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;

  if (hashTable == NULL) {
    hashTable = (struct HashNode **)malloc(sizeof(struct HashNode *) * HASH_TABLE_SIZE);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
      hashTable[i] = NULL;
    }
  }

  int hashIndex = hashFunction(key);
  if (hashTable[hashIndex] == NULL) {
    hashTable[hashIndex] = newNode;
  } else {
    struct HashNode *currentNode = hashTable[hashIndex];
    while (currentNode->next) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
  }
}

int hashFunction(char *key) {
  int hashValue = 0;
  for (int i = 0; key[i] != '\0'; i++) {
    hashValue = (hashValue * 33) + key[i];
  }
  return hashValue % HASH_TABLE_SIZE;
}

int main() {
  insertHashNode("a", 10);
  insertHashNode("b", 20);
  insertHashNode("c", 30);

  struct HashNode *currentNode = hashTable[hashFunction("a")];
  printf("Value for key 'a': %d\n", currentNode->value);

  return 0;
}