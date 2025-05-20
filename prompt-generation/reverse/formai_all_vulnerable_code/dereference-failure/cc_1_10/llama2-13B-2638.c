//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
  struct Node* new_node = newNode(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
  struct Node* current = *head_ref;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode(data);
}

// Function to delete the first node of the list
struct Node* deleteFirst(struct Node** head_ref) {
  if (*head_ref == NULL) {
    return NULL;
  }
  struct Node* first = *head_ref;
  *head_ref = first->next;
  free(first);
  return first;
}

// Function to delete the last node of the list
struct Node* deleteLast(struct Node** head_ref) {
  struct Node* current = *head_ref;
  struct Node* previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    return NULL;
  }
  previous->next = NULL;
  free(current);
  return previous;
}

int main() {
  struct Node* head = NULL;

  // Insert some nodes at the beginning of the list
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 3);

  // Insert some nodes at the end of the list
  insertAtEnd(&head, 4);
  insertAtEnd(&head, 5);
  insertAtEnd(&head, 6);

  // Delete the first node of the list
  struct Node* first = deleteFirst(&head);
  printf("First node deleted: %d\n", first->data);

  // Delete the last node of the list
  struct Node* last = deleteLast(&head);
  printf("Last node deleted: %d\n", last->data);

  return 0;
}