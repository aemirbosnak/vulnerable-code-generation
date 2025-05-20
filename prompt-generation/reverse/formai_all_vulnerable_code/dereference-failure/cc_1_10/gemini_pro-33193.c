//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Ada Lovelace-style linked list operations

// Node definition
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Insert a node at the beginning of the list
node_t *insert_at_head(node_t *head, int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = head;
  return new_node;
}

// Insert a node after a given node
node_t *insert_after(node_t *head, node_t *prev_node, int data) {
  if (prev_node == NULL) {
    return head;
  }
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
  return head;
}

// Delete a node from the list
node_t *delete_node(node_t *head, int data) {
  node_t *curr_node = head;
  node_t *prev_node = NULL;
  while (curr_node != NULL) {
    if (curr_node->data == data) {
      if (prev_node == NULL) {
        head = curr_node->next;
      } else {
        prev_node->next = curr_node->next;
      }
      free(curr_node);
      return head;
    }
    prev_node = curr_node;
    curr_node = curr_node->next;
  }
  return head;
}

// Print the list
void print_list(node_t *head) {
  node_t *curr_node = head;
  while (curr_node != NULL) {
    printf("%d ", curr_node->data);
    curr_node = curr_node->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Initialize the list
  node_t *head = NULL;

  // Insert some nodes
  head = insert_at_head(head, 1);
  head = insert_at_head(head, 2);
  head = insert_at_head(head, 3);

  // Print the list
  printf("Original list: ");
  print_list(head);

  // Insert a node after the first node
  head = insert_after(head, head, 4);

  // Print the list
  printf("List after inserting a node after the first node: ");
  print_list(head);

  // Delete a node
  head = delete_node(head, 2);

  // Print the list
  printf("List after deleting a node: ");
  print_list(head);

  // Free the list
  while (head != NULL) {
    node_t *next_node = head->next;
    free(head);
    head = next_node;
  }

  return 0;
}