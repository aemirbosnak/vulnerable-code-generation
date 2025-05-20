//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

// Create a new node with the given data
node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the head of the list
node *insert_at_head(node *head, int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Insert a new node at the tail of the list
node *insert_at_tail(node *head, int data) {
  node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Delete the node with the given data from the list
node *delete_node(node *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == data) {
    node *new_head = head->next;
    free(head);
    return new_head;
  }
  node *current = head;
  while (current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if (current->next == NULL) {
    return head;
  }
  node *next_node = current->next->next;
  free(current->next);
  current->next = next_node;
  return head;
}

// Print the list
void print_list(node *head) {
  if (head == NULL) {
    printf("[]\n");
    return;
  }
  printf("[");
  node *current = head;
  while (current->next != NULL) {
    printf("%d, ", current->data);
    current = current->next;
  }
  printf("%d]\n", current->data);
}

int main() {
  node *head = NULL;

  // Insert some nodes into the list
  head = insert_at_head(head, 1);
  head = insert_at_head(head, 2);
  head = insert_at_head(head, 3);

  // Print the list
  printf("Initial list: ");
  print_list(head);

  // Insert a new node at the tail of the list
  head = insert_at_tail(head, 4);

  // Print the list
  printf("List after inserting at tail: ");
  print_list(head);

  // Delete a node from the list
  head = delete_node(head, 2);

  // Print the list
  printf("List after deleting a node: ");
  print_list(head);

  return 0;
}