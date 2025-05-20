//Gemma-7B DATASET v1.0 Category: Cryptographic hash function ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 64

#define HASH_PRIME 3

typedef struct Node {
  struct Node* next;
  int key;
  char data[HASH_SIZE];
} Node;

Node* hash_insert(Node* head, int key, char data[]) {
  int hash = key % HASH_PRIME;
  Node* newNode = malloc(sizeof(Node));
  newNode->key = key;
  strcpy(newNode->data, data);
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

int hash_search(Node* head, int key) {
  int hash = key % HASH_PRIME;
  Node* current = head;

  while (current) {
    if (current->key == key) {
      return 1;
    }
    current = current->next;
  }

  return 0;
}

int main() {
  Node* head = NULL;
  head = hash_insert(head, 1, "abc");
  head = hash_insert(head, 2, "def");
  head = hash_insert(head, 3, "ghi");

  if (hash_search(head, 2) == 1) {
    printf("Key 2 found.\n");
  }

  return 0;
}