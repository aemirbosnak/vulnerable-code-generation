//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 256

typedef struct HashNode {
  char *key;
  int data;
  struct HashNode *next;
} HashNode;

void hash_insert(HashNode **head, char *key, int data) {
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->key = strdup(key);
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    HashNode *traverse = *head;
    while (traverse->next) {
      traverse = traverse->next;
    }
    traverse->next = newNode;
  }
}

int hash_search(HashNode *head, char *key) {
  HashNode *traverse = head;
  while (traverse) {
    if (strcmp(traverse->key, key) == 0) {
      return traverse->data;
    }
    traverse = traverse->next;
  }
  return -1;
}

int main() {
  HashNode *head = NULL;
  hash_insert(&head, "John Doe", 12);
  hash_insert(&head, "Jane Doe", 13);
  hash_insert(&head, "Jack Doe", 14);

  int data = hash_search(head, "Jane Doe");
  if (data != -1) {
    printf("Data for Jane Doe: %d\n", data);
  } else {
    printf("Key not found.\n");
  }

  return 0;
}