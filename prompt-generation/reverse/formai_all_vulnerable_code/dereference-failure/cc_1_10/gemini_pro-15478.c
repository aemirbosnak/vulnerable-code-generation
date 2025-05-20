//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node *next;
} Node;

// Linked list operations
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void insertAtEnd(Node **head, int data) {
  Node *newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

void insertAfter(Node *prevNode, int data) {
  if (prevNode == NULL) {
    printf("Previous node cannot be null.\n");
    return;
  }
  Node *newNode = createNode(data);
  newNode->next = prevNode->next;
  prevNode->next = newNode;
}

void deleteNode(Node **head, int data) {
  if (*head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *prev = NULL;
  Node *temp = *head;
  while (temp != NULL && temp->data != data) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Node with data %d not found.\n", data);
    return;
  }
  if (prev == NULL) {
    *head = temp->next;
  } else {
    prev->next = temp->next;
  }
  free(temp);
}

void printList(Node *head) {
  if (head == NULL) {
    printf("List is empty.\n");
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  Node *head = NULL;

  // Creating a linked list
  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtBeginning(&head, 5);
  insertAfter(head->next, 15);

  // Printing the linked list
  printf("Linked list: ");
  printList(head);

  // Deleting a node from the linked list
  deleteNode(&head, 15);

  // Printing the linked list again
  printf("Linked list after deletion: ");
  printList(head);

  return 0;
}