//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

typedef struct HashNode {
  char data[HASH_SIZE];
  struct HashNode* next;
} HashNode;

void hash_init(HashNode** head) {
  *head = NULL;
}

void hash_insert(HashNode** head, char* data) {
  HashNode* newNode = malloc(sizeof(HashNode));
  strcpy(newNode->data, data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int hash_search(HashNode* head, char* data) {
  while (head) {
    if (strcmp(head->data, data) == 0) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  HashNode* head = NULL;
  hash_init(&head);

  char* data = "Hello, world!";
  hash_insert(&head, data);

  if (hash_search(head, data) == 1) {
    printf("Data found!");
  } else {
    printf("Data not found!");
  }

  return 0;
}