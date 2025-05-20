//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a node in a linked list
typedef struct node {
  int value;
  struct node *next;
} node;

// Create a new node with the given value
node *create_node(int value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node into the linked list
void insert_node(node **head, node *new_node) {
  if (*head == NULL) {
    *head = new_node;
  } else {
    node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Print the linked list
void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

// Free the memory used by the linked list
void free_list(node *head) {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Create a new linked list
  node *head = NULL;

  // Insert some values into the linked list
  insert_node(&head, create_node(1));
  insert_node(&head, create_node(2));
  insert_node(&head, create_node(3));
  insert_node(&head, create_node(4));
  insert_node(&head, create_node(5));

  // Print the linked list
  print_list(head);

  // Free the memory used by the linked list
  free_list(head);

  return 0;
}