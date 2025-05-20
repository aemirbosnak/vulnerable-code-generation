//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 256
#define HASH_PRIME 3

typedef struct HashNode {
  char *data;
  struct HashNode *next;
} HashNode;

HashNode *hash_insert(HashNode *head, char *data) {
  int hash = hash_calc(data);
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->data = strdup(data);
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

int hash_calc(char *data) {
  int hash = 0;
  for (int i = 0; data[i] != '\0'; i++) {
    hash += (int)data[i] * HASH_PRIME;
  }
  return hash % HASH_SIZE;
}

int main() {
  HashNode *head = NULL;
  hash_insert(head, "John Doe");
  hash_insert(head, "Jane Doe");
  hash_insert(head, "Jack Doe");

  HashNode *traversing = head;
  while (traversing) {
    printf("%s\n", traversing->data);
    traversing = traversing->next;
  }

  return 0;
}