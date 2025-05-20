//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_HASH_SIZE 64

typedef struct HashNode {
  char *data;
  struct HashNode *next;
} HashNode;

void hash_init(HashNode **head) {
  *head = NULL;
}

void hash_add(HashNode **head, char *data) {
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

char *hash_get(HashNode *head, char *data) {
  for (HashNode *curr = head; curr; curr = curr->next) {
    if (strcmp(curr->data, data) == 0) {
      return curr->data;
    }
  }

  return NULL;
}

int main() {
  HashNode *head = NULL;
  hash_init(&head);

  char *data = "Hello, world!";
  hash_add(&head, data);

  char *retrieved_data = hash_get(head, data);

  if (retrieved_data) {
    printf("Retrieved data: %s\n", retrieved_data);
  } else {
    printf("Data not found.\n");
  }

  return 0;
}