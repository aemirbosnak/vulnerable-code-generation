//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 1024

typedef struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
} HashNode;

HashNode *hash_insert(HashNode *head, char *key, int value) {
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->key = strdup(key);
  newNode->value = value;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode *traversing = head;
    while (traversing->next) {
      traversing = traversing->next;
    }
    traversing->next = newNode;
  }

  return head;
}

int hash_search(HashNode *head, char *key) {
  HashNode *traversing = head;
  while (traversing) {
    if (strcmp(traversing->key, key) == 0) {
      return traversing->value;
    }
    traversing = traversing->next;
  }

  return -1;
}

int main() {
  HashNode *head = NULL;

  head = hash_insert(head, "a", 10);
  head = hash_insert(head, "b", 20);
  head = hash_insert(head, "c", 30);

  int value = hash_search(head, "b");
  printf("Value for key 'b': %d\n", value);

  return 0;
}