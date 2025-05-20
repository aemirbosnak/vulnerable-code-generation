//FormAI DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Node struct
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// Function declarations
Node* createNode(int data);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int data);
void printList(Node* head);
void destroyList(Node** head);

int main() {

  // Initial list
  Node* head = NULL;

  // Insert nodes
  insertNode(&head, 10);
  insertNode(&head, 20);
  insertNode(&head, 30);
  insertNode(&head, 40);
  insertNode(&head, 50);

  // Prints list
  printf("Initial Linked List:\n");
  printList(head);

  // Deletes node
  deleteNode(&head, 20);

  // Prints list after deletion
  printf("\nLinked List after deleting 20:\n");
  printList(head);

  // Destroys the list
  destroyList(&head);

  return 0;
}

// Function to create a new node
Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the end of the list
void insertNode(Node** head, int data) {
  Node* newNode = createNode(data);
  if (*head == NULL) {
    *head = newNode;
  } else {
    Node* current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Function to delete a node from the list
void deleteNode(Node** head, int data) {
  Node* current = *head;
  Node* previous = NULL;

  while (current != NULL && current->data != data) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Node not found\n");
    return;
  } else if (previous == NULL) {
    *head = current->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

// Function to print the list
void printList(Node* head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Function to destroy the list
void destroyList(Node** head) {
  Node* current = *head;
  while (current != NULL) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  *head = NULL;
}