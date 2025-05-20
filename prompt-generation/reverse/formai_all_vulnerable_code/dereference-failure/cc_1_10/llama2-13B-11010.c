//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: retro
// RetroLinkedList.c - A blast from the past!

// Includes
#include <stdio.h>
#include <stdlib.h>

// Structures
struct Node {
  int data;
  struct Node *next;
};

// Functions
void printList(struct Node *list); // Prints the list in a retro style
void addToList(struct Node **head_ref, int data); // Adds a new node to the list
void removeFromList(struct Node **head_ref, int data); // Removes a node from the list

int main() {
  struct Node *list = NULL; // Initialize the list

  // Add some nodes
  addToList(&list, 1);
  addToList(&list, 2);
  addToList(&list, 3);

  // Print the list
  printList(list);

  // Remove a node
  removeFromList(&list, 2);

  // Print the list again
  printList(list);

  return 0;
}

// PrintList function
void printList(struct Node *list) {
  printf("[");
  for (struct Node *current = list; current != NULL; current = current->next) {
    printf("%d ", current->data);
  }
  printf("]");
}

// AddToList function
void addToList(struct Node **head_ref, int data) {
  struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// RemoveFromList function
void removeFromList(struct Node **head_ref, int data) {
  struct Node *current = *head_ref;
  struct Node *previous = NULL;

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