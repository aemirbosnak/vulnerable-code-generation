//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// RetroLinkedList.c - A vintage-inspired linked list library

// Includes
#include <stdio.h>
#include <stdlib.h>

// Structs
struct Node {
  int data;
  struct Node *next;
};

// Functions
void initList(struct Node **head_ref);
void insertNode(struct Node **head_ref, int data);
void removeNode(struct Node **head_ref, int data);
void printList(struct Node *head);

// Global variables
struct Node *head = NULL;

// Function implementations

// Initialize list
void initList(struct Node **head_ref) {
  *head_ref = NULL;
}

// Insert node
void insertNode(struct Node **head_ref, int data) {
  struct Node *new_node = malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;

  if (*head_ref == NULL) {
    head = new_node;
  } else {
    struct Node *current = *head_ref;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Remove node
void removeNode(struct Node **head_ref, int data) {
  struct Node *current = head;
  struct Node *prev = NULL;

  while (current != NULL) {
    if (current->data == data) {
      if (prev == NULL) {
        head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

// Print list
void printList(struct Node *head) {
  struct Node *current = head;

  printf("Linked List: \n");

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

int main() {
  struct Node *new_node;

  // Initialize list
  initList(&head);

  // Insert nodes
  insertNode(&head, 1);
  insertNode(&head, 2);
  insertNode(&head, 3);
  insertNode(&head, 4);

  // Remove nodes
  removeNode(&head, 2);
  removeNode(&head, 4);

  // Print list
  printList(head);

  return 0;
}