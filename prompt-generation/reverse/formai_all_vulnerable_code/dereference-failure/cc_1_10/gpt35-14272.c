//FormAI DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node* head;

void createNode(int data) {
  Node* newNode = malloc(sizeof(Node));

  if(newNode == NULL) {
    printf("Error: Memory allocation failed\n");
    return;
  }

  newNode->data = data;
  newNode->next = NULL;

  if(head == NULL) {
    head = newNode;
    return;
  }

  Node* current = head;

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = newNode;
}

void deleteNode(int key) {
  Node* current = head;
  Node* previous;

  if(current->data == key) {
    head = current->next;
    free(current);
    return;
  }

  while(current != NULL) {
    if(current->data == key) {
      previous->next = current->next;
      free(current);
      return;
    }

    previous = current;
    current = current->next;
  }

  printf("Error: Key not found\n");
}

void displayList() {
  Node* current = head;

  while(current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  head = NULL;

  createNode(1);
  createNode(2);
  createNode(3);
  createNode(4);
  createNode(5);

  printf("Current linked list:\n");
  displayList();

  deleteNode(3);

  printf("After deleting node with key '3':\n");
  displayList();

  return 0;
}