//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// A struct to represent a node in a linked list
typedef struct node {
  int data;
  struct node *next;
} node_t;

// A function to create a new node
node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    printf("Error: Could not allocate memory for new node.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// A function to insert a new node at the beginning of a linked list
node_t *insert_at_beginning(node_t *head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// A function to insert a new node at the end of a linked list
node_t *insert_at_end(node_t *head, int data) {
  node_t *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node_t *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
  return head;
}

// A function to delete a node from a linked list
node_t *delete_node(node_t *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == data) {
    node_t *new_head = head->next;
    free(head);
    return new_head;
  }
  node_t *current_node = head;
  node_t *previous_node = NULL;
  while (current_node != NULL && current_node->data != data) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (current_node == NULL) {
    return head;
  }
  previous_node->next = current_node->next;
  free(current_node);
  return head;
}

// A function to print a linked list
void print_linked_list(node_t *head) {
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// A function to free a linked list
void free_linked_list(node_t *head) {
  node_t *current_node = head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
}

int main() {
  // Create a linked list
  node_t *head = NULL;
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_beginning(head, 3);
  head = insert_at_end(head, 4);

  // Print the linked list
  print_linked_list(head);

  // Delete a node from the linked list
  head = delete_node(head, 2);

  // Print the linked list
  print_linked_list(head);

  // Free the linked list
  free_linked_list(head);

  return 0;
}