//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdlib.h>
#include <stdio.h>

// A simple linked list node
struct node {
  int data;
  struct node *next;
};

// Create a new node with the given data and return it
struct node *new_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node into the linked list after the given node
void insert_after(struct node *prev, struct node *new_node) {
  new_node->next = prev->next;
  prev->next = new_node;
}

// Delete the given node from the linked list
void delete_node(struct node *node) {
  struct node *prev = NULL;
  while (node->next != NULL) {
    prev = node;
    node = node->next;
  }
  if (prev != NULL) {
    prev->next = node->next;
  }
  free(node);
}

// Print the linked list
void print_list(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Free the linked list
void free_list(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    struct node *next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  // Create a linked list
  struct node *head = new_node(1);
  insert_after(head, new_node(2));
  insert_after(head->next, new_node(3));
  insert_after(head->next->next, new_node(4));

  // Print the linked list
  print_list(head);

  // Delete a node from the linked list
  delete_node(head->next);

  // Print the linked list again
  print_list(head);

  // Free the linked list
  free_list(head);

  return 0;
}