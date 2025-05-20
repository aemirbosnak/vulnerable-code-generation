//Gemma-7B DATASET v1.0 Category: Bitwise operations ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 16

typedef struct Node {
  int value;
  struct Node* next;
} Node;

void traverse(Node* head) {
  while (head) {
    printf("%d ", head->value);
    head = head->next;
  }
}

int main() {
  Node* head = NULL;

  // Create a few nodes
  Node* node1 = malloc(sizeof(Node));
  node1->value = 5;
  node1->next = NULL;

  Node* node2 = malloc(sizeof(Node));
  node2->value = 10;
  node2->next = node1;

  Node* node3 = malloc(sizeof(Node));
  node3->value = 15;
  node3->next = node2;

  head = node3;

  // Traverse the linked list
  traverse(head);

  // Use bitwise AND to set all nodes' values to 0
  head = node3;
  while (head) {
    head->value &= 0;
    head = head->next;
  }

  // Traverse the list after setting all values to 0
  traverse(head);

  return 0;
}