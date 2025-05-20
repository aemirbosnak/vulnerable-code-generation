//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtStart(struct Node** head_ref, int value) {
  struct Node* new_node = newNode(value);
  new_node->next = *head_ref;
  *head_ref = new_node;
  return new_node;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node** head_ref, int value) {
  struct Node* current = *head_ref;
  struct Node* new_node = newNode(value);
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return new_node;
}

// Function to remove the first node from the list
struct Node* removeFirst(struct Node** head_ref) {
  struct Node* node = *head_ref;
  *head_ref = node->next;
  free(node);
  return node;
}

// Function to remove the last node from the list
struct Node* removeLast(struct Node** head_ref) {
  struct Node* current = *head_ref;
  struct Node* previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (previous != NULL) {
    previous->next = NULL;
  }
  free(current);
  return previous;
}

// Function to traverse the list
void traverse(struct Node* head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  // Insert some nodes at the beginning of the list
  head = insertAtStart(&head, 1);
  head = insertAtStart(&head, 2);
  head = insertAtStart(&head, 3);

  // Insert some nodes at the end of the list
  head = insertAtEnd(&head, 4);
  head = insertAtEnd(&head, 5);
  head = insertAtEnd(&head, 6);

  // Remove the first node from the list
  head = removeFirst(&head);

  // Remove the last node from the list
  head = removeLast(&head);

  // Traverse the list
  traverse(head);

  return 0;
}