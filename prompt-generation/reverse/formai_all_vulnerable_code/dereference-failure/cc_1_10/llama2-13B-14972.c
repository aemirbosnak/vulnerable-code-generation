//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
  int data;
  struct Node* next;
};

// Function to create a new node with a given value
struct Node* newNode(int value) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = value;
  node->next = NULL;
  return node;
}

// Function to insert a node into the linked list
void insertNode(struct Node** head_ref, int value) {
  struct Node* new_node = newNode(value);
  if (*head_ref == NULL) {
    *head_ref = new_node;
  } else {
    (*head_ref)->next = new_node;
  }
  (*head_ref) = new_node;
}

// Function to print the linked list
void printList(struct Node* head) {
  if (head == NULL) {
    printf("List is empty!\n");
    return;
  }
  printf("List: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL;

  // Create a linked list with some nodes
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);
  insertNode(&head, 5);

  // Print the linked list
  printList(head);

  return 0;
}