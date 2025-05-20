//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 1024

struct HashNode {
  char *data;
  struct HashNode *next;
};

void hash_insert(struct HashNode **head, char *data) {
  struct HashNode *newNode = malloc(sizeof(struct HashNode));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    struct HashNode *curr = *head;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newNode;
  }
}

int hash_search(struct HashNode *head, char *data) {
  struct HashNode *curr = head;
  while (curr) {
    if (strcmp(curr->data, data) == 0) {
      return 1;
    }
    curr = curr->next;
  }
  return 0;
}

int main() {
  struct HashNode *head = NULL;
  hash_insert(head, "A");
  hash_insert(head, "B");
  hash_insert(head, "C");
  hash_insert(head, "D");

  if (hash_search(head, "B") == 1) {
    printf("B is in the hash table.\n");
  }

  return 0;
}