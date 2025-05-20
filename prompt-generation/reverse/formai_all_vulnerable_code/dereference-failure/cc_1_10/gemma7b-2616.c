//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define HASH_SIZE 256

struct hash_node {
  char *key;
  int value;
  struct hash_node *next;
};

void hash_insert(struct hash_node **head, char *key, int value) {
  struct hash_node *new_node = malloc(sizeof(struct hash_node));
  new_node->key = strdup(key);
  new_node->value = value;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
  } else {
    struct hash_node *current = *head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }
}

int hash_search(struct hash_node *head, char *key) {
  struct hash_node *current = head;
  while (current) {
    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  return -1;
}

int main() {
  struct hash_node *head = NULL;

  hash_insert(head, "John Doe", 12);
  hash_insert(head, "Jane Doe", 14);
  hash_insert(head, "Peter Pan", 16);

  int value = hash_search(head, "Jane Doe");

  if (value != -1) {
    printf("Value for Jane Doe: %d\n", value);
  } else {
    printf("Key not found.\n");
  }

  return 0;
}