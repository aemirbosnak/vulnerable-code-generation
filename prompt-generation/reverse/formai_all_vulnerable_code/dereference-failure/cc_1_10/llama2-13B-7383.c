//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct Node {
  int data; // The data stored in the node
  struct Node *next; // The next node in the list
} Node;

// Function to create a new node
Node* createNode(int data) {
  Node* newNode = (Node*) malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to add a node to the beginning of the list
void addNodeToBeginning(Node** head_ref, int data) {
  Node* newNode = createNode(data);
  newNode->next = *head_ref;
  *head_ref = newNode;
}

// Function to add a node to the end of the list
void addNodeToEnd(Node** head_ref, int data) {
  Node* current = *head_ref;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = createNode(data);
}

// Function to remove the first node from the list
Node* removeFirstNode(Node** head_ref) {
  if (*head_ref == NULL) {
    return NULL;
  }
  Node* firstNode = *head_ref;
  *head_ref = firstNode->next;
  free(firstNode);
  return firstNode;
}

// Function to remove the last node from the list
Node* removeLastNode(Node** head_ref) {
  if (*head_ref == NULL) {
    return NULL;
  }
  Node* current = *head_ref;
  Node* previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    // List is empty, return NULL
    return NULL;
  }
  previous->next = NULL;
  free(current);
  return previous;
}

// Function to print the list
void printList(Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node* head = NULL;

  // Add some nodes to the list
  addNodeToBeginning(&head, 1);
  addNodeToBeginning(&head, 2);
  addNodeToEnd(&head, 3);
  addNodeToEnd(&head, 4);

  // Remove the first node
  Node* firstNode = removeFirstNode(&head);
  printList(head);

  // Remove the last node
  Node* lastNode = removeLastNode(&head);
  printList(head);

  return 0;
}