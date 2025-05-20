//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64

typedef struct HashNode {
  char *data;
  struct HashNode *next;
} HashNode;

HashNode *insertHash(HashNode *head, char *data) {
  HashNode *newNode = malloc(sizeof(HashNode));
  newNode->data = strdup(data);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    HashNode *current = head;
    HashNode *previous = NULL;
    while (current) {
      if (strcmp(newNode->data, current->data) == 0) {
        return NULL;
      } else if (previous) {
        previous = current;
        current = current->next;
      } else {
        previous = newNode;
        current = head;
      }
    }
    previous->next = newNode;
  }

  return head;
}

int main() {
  HashNode *head = NULL;
  char *data = "Hello, world!";
  insertHash(head, data);

  data = "Goodbye, cruel world!";
  insertHash(head, data);

  data = "Foobar";
  insertHash(head, data);

  for (HashNode *current = head; current; current = current->next) {
    printf("%s\n", current->data);
  }

  return 0;
}