//FormAI DATASET v1.0 Category: Memory management ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertNode(Node* head, int data) {
  Node* current = head;
  while(current->next != NULL) {
    current = current->next;
  }
  current->next = createNode(data);
}

void deleteNode(Node* head, int data) {
  Node* current = head;
  while(current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if(current->next == NULL) {
    printf("Node with data %d not found\n", data);
    return;
  }
  Node* temp = current->next;
  current->next = current->next->next;
  free(temp);
}

void printList(Node* head) {
  Node* current = head;
  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node* head = createNode(1);
  insertNode(head, 2);
  insertNode(head, 3);
  insertNode(head, 4);
  printList(head);
  deleteNode(head, 3);
  printList(head);
  deleteNode(head, 5);
  printList(head);
  return 0;
}