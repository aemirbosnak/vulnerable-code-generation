//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 1024

typedef struct Node {
  uint32_t data;
  struct Node* next;
} Node;

Node* hash_insert(Node* head, uint32_t data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  return head;
}

uint32_t hash_search(Node* head, uint32_t data) {
  Node* current = head;
  while (current) {
    if (current->data == data) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

uint32_t hash_func(char* str) {
  uint32_t hash = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    hash = (hash << 5) | str[i];
  }

  return hash;
}

int main() {
  Node* head = NULL;
  hash_insert(head, hash_func("abc"));
  hash_insert(head, hash_func("bcd"));
  hash_insert(head, hash_func("cde"));

  if (hash_search(head, hash_func("abc")) == 1) {
    printf("abc is found\n");
  }

  return 0;
}