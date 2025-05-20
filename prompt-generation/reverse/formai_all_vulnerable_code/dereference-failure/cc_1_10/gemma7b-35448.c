//Gemma-7B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdlib.h>
#include <stdio.h>

#define MAX_ALLOCATIONS 10

typedef struct Node {
  struct Node* next;
  int data;
} Node;

Node* head = NULL;

void allocateNode() {
  if (head == NULL) {
    head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    head->data = 0;
  } else {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = head;
    head = newNode;
    newNode->data = 0;
  }
}

void freeNode(int data) {
  Node* current = head;
  Node* previous = NULL;

  while (current) {
    if (current->data == data) {
      if (previous) {
        previous->next = current->next;
      } else {
        head = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }

  printf("Error: Node not found.\n");
}

int main() {
  allocateNode();
  allocateNode();
  allocateNode();
  allocateNode();
  allocateNode();

  freeNode(1);
  freeNode(3);

  allocateNode();

  freeNode(2);

  printf("Head data: %d\n", head->data);

  return 0;
}