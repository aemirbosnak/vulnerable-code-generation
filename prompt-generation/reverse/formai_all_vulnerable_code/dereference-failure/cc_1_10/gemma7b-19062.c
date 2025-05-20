//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define HASH_SIZE 256

typedef struct Node {
  uint32_t data;
  struct Node* next;
} Node;

Node* hash_insert(Node* head, uint32_t data) {
  Node* new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
      if (data < current->data) {
        previous = current;
        current = current->next;
      } else if (previous) {
        previous->next = new_node;
        new_node->next = current;
        break;
      }
    }

    if (previous) {
      previous->next = new_node;
    } else {
      head = new_node;
    }
  }

  return head;
}

uint32_t hash_lookup(Node* head, uint32_t data) {
  Node* current = head;

  while (current) {
    if (data == current->data) {
      return 1;
    } else if (data < current->data) {
      current = current->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;
  hash_insert(head, 10);
  hash_insert(head, 20);
  hash_insert(head, 30);
  hash_insert(head, 40);
  hash_insert(head, 50);

  if (hash_lookup(head, 30) == 1) {
    printf("Data found!\n");
  }

  return 0;
}