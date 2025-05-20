//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* head = NULL;

void insert(int x) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = head;
  head = newNode;
}

void delete(int x) {
  Node* temp = head;
  Node* prev = NULL;
  while (temp != NULL && temp->data != x) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("%d not found.\n", x);
    return;
  }
  if (prev == NULL) {
    head = temp->next;
    free(temp);
    return;
  }
  prev->next = temp->next;
  free(temp);
}

void printList() {
  Node* temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  insert(3);
  insert(2);
  insert(1);
  printList(); // 1 2 3
  delete(2);
  printList(); // 1 3
  insert(4);
  printList(); // 4 1 3
  return 0;
}