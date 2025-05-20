//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Insert a new node at the beginning of the list
void insert_beginning(node_t **head, int data) {
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

// Insert a new node at the end of the list
void insert_end(node_t **head, int data) {
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_node;
}

// Insert a new node after a given node
void insert_after(node_t *node, int data) {
  if (node == NULL) {
    return;
  }

  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = node->next;
  node->next = new_node;
}

// Delete a node from the list
void delete_node(node_t **head, int data) {
  node_t *current = *head;
  node_t *previous = NULL;

  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        *head = current->next;
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

// Print the list
void print_list(node_t *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }

  printf("\n");
}

// Main function
int main() {
  // Create a new list
  node_t *head = NULL;

  // Insert some nodes into the list
  insert_beginning(&head, 10);
  insert_end(&head, 20);
  insert_after(head, 15);

  // Print the list
  print_list(head);

  // Delete a node from the list
  delete_node(&head, 15);

  // Print the list again
  print_list(head);

  return 0;
}