//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 64
#define HASH_SIZE 1024

#define ROTATE(x, n) (((x) << (n)) | ((x) >> (n))

typedef struct Node {
  struct Node* next;
  unsigned int data;
} Node;

void hash_add(Node** head, unsigned int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

unsigned int hash_get(Node* head, unsigned int data) {
  for (Node* current = head; current; current = current->next) {
    if (current->data == data) {
      return 1;
    }
  }

  return 0;
}

int main() {
  Node* hashTable = NULL;

  // Hash some data
  hash_add(&hashTable, 12);
  hash_add(&hashTable, 24);
  hash_add(&hashTable, 36);
  hash_add(&hashTable, 48);

  // Check if data is in the hash table
  if (hash_get(hashTable, 24) == 1) {
    printf("Data found!\n");
  }

  return 0;
}