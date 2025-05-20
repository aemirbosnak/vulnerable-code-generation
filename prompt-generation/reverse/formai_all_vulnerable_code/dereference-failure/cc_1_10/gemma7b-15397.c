//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_HASH_SIZE 64

typedef struct HashNode {
  char data[MAX_HASH_SIZE];
  struct HashNode* next;
} HashNode;

HashNode* hash_insert(HashNode* head, char* data) {
  HashNode* newNode = malloc(sizeof(HashNode));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode* traverse = head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }

  return head;
}

int hash_search(HashNode* head, char* data) {
  HashNode* traverse = head;
  while (traverse) {
    if (strcmp(traverse->data, data) == 0) {
      return 1;
    }
    traverse = traverse->next;
  }

  return 0;
}

int main() {
  HashNode* head = NULL;
  head = hash_insert(head, "Hello, world!");
  head = hash_insert(head, "Goodbye, cruel world!");

  if (hash_search(head, "Hello, world!") == 1) {
    printf("Data found!\n");
  } else {
    printf("Data not found.\n");
  }

  return 0;
}