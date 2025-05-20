//Gemma-7B DATASET v1.0 Category: Password management ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 1024

typedef struct HashNode {
  char *key;
  struct HashNode *next;
} HashNode;

void hash_insert(HashNode **head, char *key) {
  int hash = key_hash(key);
  HashNode *node = malloc(sizeof(HashNode));
  node->key = strdup(key);
  node->next = NULL;

  if (*head == NULL) {
    *head = node;
  } else {
    (*head)->next = node;
  }
}

char *key_search(HashNode *head, char *key) {
  int hash = key_hash(key);
  HashNode *node = head;

  while (node) {
    if (strcmp(node->key, key) == 0) {
      return node->key;
    }
    node = node->next;
  }

  return NULL;
}

int key_hash(char *key) {
  return (unsigned int) key[0] * HASH_SIZE;
}

int main() {
  HashNode *passwords = NULL;

  // Insert passwords
  hash_insert(&passwords, "Secret1");
  hash_insert(&passwords, "Secret2");
  hash_insert(&passwords, "Secret3");

  // Search for passwords
  char *password = key_search(passwords, "Secret2");

  // Print password
  if (password) {
    printf("Password: %s\n", password);
  } else {
    printf("Password not found.\n");
  }

  return 0;
}