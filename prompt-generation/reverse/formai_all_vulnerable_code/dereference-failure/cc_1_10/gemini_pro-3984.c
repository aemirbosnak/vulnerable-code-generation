//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Create a new node
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
Node *insert_at_beginning(Node *head, int data) {
  Node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Insert a node at the end of the list
Node *insert_at_end(Node *head, int data) {
  Node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  Node *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
  return head;
}

// Insert a node after a given node
Node *insert_after_node(Node *head, int data, int after_data) {
  Node *new_node = create_node(data);
  Node *current_node = head;
  while (current_node != NULL && current_node->data != after_data) {
    current_node = current_node->next;
  }
  if (current_node == NULL) {
    printf("The given node was not found in the list.\n");
    return head;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
  return head;
}

// Delete a node from the beginning of the list
Node *delete_from_beginning(Node *head) {
  if (head == NULL) {
    printf("The list is already empty.\n");
    return head;
  }
  Node *new_head = head->next;
  free(head);
  return new_head;
}

// Delete a node from the end of the list
Node *delete_from_end(Node *head) {
  if (head == NULL) {
    printf("The list is already empty.\n");
    return head;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  Node *current_node = head;
  while (current_node->next->next != NULL) {
    current_node = current_node->next;
  }
  free(current_node->next);
  current_node->next = NULL;
  return head;
}

// Delete a node from the middle of the list
Node *delete_node(Node *head, int data) {
  if (head == NULL) {
    printf("The list is already empty.\n");
    return head;
  }
  if (head->data == data) {
    return delete_from_beginning(head);
  }
  Node *current_node = head;
  while (current_node->next != NULL && current_node->next->data != data) {
    current_node = current_node->next;
  }
  if (current_node->next == NULL) {
    printf("The given node was not found in the list.\n");
    return head;
  }
  Node *next_node = current_node->next->next;
  free(current_node->next);
  current_node->next = next_node;
  return head;
}

// Print the list
void print_list(Node *head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }
  Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  // Create an empty list
  Node *head = NULL;

  // Insert some nodes into the list
  head = insert_at_beginning(head, 10);
  head = insert_at_end(head, 20);
  head = insert_after_node(head, 15, 10);

  // Print the list
  printf("The list is: ");
  print_list(head);

  // Delete a node from the beginning of the list
  head = delete_from_beginning(head);

  // Print the list
  printf("The list after deleting a node from the beginning is: ");
  print_list(head);

  // Delete a node from the end of the list
  head = delete_from_end(head);

  // Print the list
  printf("The list after deleting a node from the end is: ");
  print_list(head);

  // Delete a node from the middle of the list
  head = delete_node(head, 15);

  // Print the list
  printf("The list after deleting a node from the middle is: ");
  print_list(head);

  return 0;
}