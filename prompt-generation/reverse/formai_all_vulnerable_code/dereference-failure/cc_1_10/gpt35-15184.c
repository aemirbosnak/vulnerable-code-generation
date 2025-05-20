//FormAI DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *head = NULL;

void insert(int num) {
  Node *newNode = malloc(sizeof(Node));
  newNode->data = num;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node *currNode = head;
  while (currNode->next != NULL) {
    currNode = currNode->next;
  }
  currNode->next = newNode;
}

void delete(int num) {
  if (head == NULL) {
    return;
  }

  if (head->data == num) {
    Node *temp = head;
    head = head->next;
    free(temp);
    return;
  }

  Node *currNode = head;
  while (currNode->next != NULL && currNode->next->data != num) {
    currNode = currNode->next;
  }

  if (currNode->next == NULL) {
    return;
  }

  Node *temp = currNode->next;
  currNode->next = currNode->next->next;
  free(temp);
}

void printList() {
  Node *currNode = head;
  while (currNode != NULL) {
    printf("%d ", currNode->data);
    currNode = currNode->next;
  }
  printf("\n");
}

int main() {
  insert(5);
  insert(10);
  insert(15);
  insert(20);
  printList();

  delete(10);
  printList();

  return 0;
}