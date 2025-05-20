//Gemma-7B DATASET v1.0 Category: Database querying ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY 10

typedef struct Node {
  char data;
  struct Node* next;
} Node;

void insertNode(Node* head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
}

int queryNode(Node* head, char data) {
  while (head) {
    if (head->data == data) {
      return 1;
    } else {
      head = head->next;
    }
  }

  return 0;
}

int main() {
  Node* head = NULL;

  // Insert nodes
  insertNode(head, 'a');
  insertNode(head, 'b');
  insertNode(head, 'c');
  insertNode(head, 'd');

  // Query nodes
  if (queryNode(head, 'b') == 1) {
    printf("Node b found!\n");
  }

  if (queryNode(head, 'e') == 0) {
    printf("Node e not found!\n");
  }

  return 0;
}