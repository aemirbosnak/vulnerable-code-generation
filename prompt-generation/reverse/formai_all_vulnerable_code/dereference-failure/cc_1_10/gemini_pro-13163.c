//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Create a new node
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of a linked list
node *insert_at_beginning(node *head, int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  head = new_node;
  return head;
}

// Insert a node at the end of a linked list
node *insert_at_end(node *head, int data) {
  node *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  node *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
  return head;
}

// Insert a node after a given node
node *insert_after(node *head, int data, int after) {
  node *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  node *current_node = head;
  while (current_node != NULL && current_node->data != after) {
    current_node = current_node->next;
  }
  if (current_node != NULL) {
    new_node->next = current_node->next;
    current_node->next = new_node;
  }
  return head;
}

// Delete a node from a linked list
node *delete_node(node *head, int data) {
  if (head == NULL) {
    return head;
  }
  if (head->data == data) {
    node *next_node = head->next;
    free(head);
    return next_node;
  }
  node *current_node = head;
  while (current_node->next != NULL) {
    if (current_node->next->data == data) {
      node *next_node = current_node->next->next;
      free(current_node->next);
      current_node->next = next_node;
      return head;
    }
    current_node = current_node->next;
  }
  return head;
}

// Print a linked list
void print_linked_list(node *head) {
  if (head == NULL) {
    printf("The linked list is empty.\n");
    return;
  }
  node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Reverse a linked list
node *reverse_linked_list(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  node *new_head = reverse_linked_list(head->next);
  head->next->next = head;
  head->next = NULL;
  return new_head;
}

// Main function
int main() {
  // Create a linked list
  node *head = NULL;
  head = insert_at_beginning(head, 10);
  head = insert_at_end(head, 20);
  head = insert_after(head, 30, 10);

  // Print the linked list
  print_linked_list(head);

  // Reverse the linked list
  head = reverse_linked_list(head);

  // Print the reversed linked list
  print_linked_list(head);

  // Delete a node from the linked list
  head = delete_node(head, 20);

  // Print the linked list after deleting a node
  print_linked_list(head);

  return 0;
}