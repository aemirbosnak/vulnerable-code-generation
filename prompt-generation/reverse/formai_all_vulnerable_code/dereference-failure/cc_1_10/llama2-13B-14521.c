//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to store a node in the linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node* newNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to insert a node at the beginning of the list
void insertNode(struct Node** head_ref, int data) {
  struct Node* new_node = newNode(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Function to delete a node from the list
void deleteNode(struct Node** head_ref, int data) {
  struct Node* current = *head_ref;
  struct Node* previous = NULL;

  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        *head_ref = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
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

  // Insert nodes into the list
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);
  insertNode(&head, 5);

  // Delete nodes from the list
  deleteNode(&head, 2);
  deleteNode(&head, 4);

  // Traverse the list
  traverse(head);

  return 0;
}