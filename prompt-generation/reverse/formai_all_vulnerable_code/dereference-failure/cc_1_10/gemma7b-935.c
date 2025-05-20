//Gemma-7B DATASET v1.0 Category: Memory management ; Style: cheerful
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node* head, int data) {
  Node* newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }
}

void freeNode(Node* node) {
  free(node);
}

int main() {
  Node* head = NULL;
  insertNode(head, 10);
  insertNode(head, 20);
  insertNode(head, 30);
  insertNode(head, 40);

  // Traverse the linked list
  Node* current = head;
  while (current) {
    printf("%d ", current->data);
    current = current->next;
  }

  // Free the nodes
  freeNode(head);
  freeNode(current);

  return 0;
}