//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// RetroLinkedList.c - A blast from the past!

#include <stdio.h>
#include <stdlib.h>

// Struct to represent a node in the linked list
typedef struct Node {
  int data;   // data stored in each node
  struct Node *next; // pointer to the next node
} Node;

// Function to create a new node with a given value
Node* newNode(int value) {
  Node* node = malloc(sizeof(Node));
  node->data = value;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head_ref, int value) {
  Node* new_node = newNode(value);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head_ref, int value) {
  Node* current = *head_ref;
  Node* new_node = newNode(value);
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
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

  // Insert some nodes
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtEnd(&head, 3);
  insertAtEnd(&head, 4);

  // Print the list
  printList(head);

  return 0;
}