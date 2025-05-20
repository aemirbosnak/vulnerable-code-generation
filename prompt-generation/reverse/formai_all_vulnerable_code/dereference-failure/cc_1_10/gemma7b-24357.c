//Gemma-7B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* insert(Node* head, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void printList(Node* head) {
  while (head) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;

  insert(head, 10);
  insert(head, 20);
  insert(head, 30);
  insert(head, 40);

  printList(head);

  if (head == NULL) {
    printf("List is empty\n");
  } else {
    printf("List is not empty\n");
  }

  return 0;
}