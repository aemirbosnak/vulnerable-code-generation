//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_INDEX 100

typedef struct Node {
  int key;
  struct Node* next;
} Node;

Node* insert(Node* head, int key) {
  Node* newNode = malloc(sizeof(Node));
  newNode->key = key;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    Node* current = head;
    Node* previous = NULL;
    while (current) {
      if (key < current->key) {
        previous = current;
        current = current->next;
      } else if (key == current->key) {
        return head;
      }
    }
    previous->next = newNode;
  }

  return head;
}

int main() {
  Node* head = NULL;
  insert(head, 20);
  insert(head, 10);
  insert(head, 30);
  insert(head, 25);
  insert(head, 40);
  insert(head, 22);

  Node* current = head;
  while (current) {
    printf("%d ", current->key);
    current = current->next;
  }

  return 0;
}