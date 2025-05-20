//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Create a new node
Node* create_node(int data) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(Node **head, int data) {
  Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(Node **head, int data) {
  Node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

// Insert a node after a given node
void insert_after(Node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be null.\n");
    return;
  }
  Node *new_node = create_node(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_at_beginning(Node **head) {
  if (*head == NULL) {
    printf("List is already empty.\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Delete a node from the end of the list
void delete_at_end(Node **head) {
  if (*head == NULL) {
    printf("List is already empty.\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  Node *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

// Delete a node from the middle of the list
void delete_node(Node **head, Node *node) {
  if (*head == NULL || node == NULL) {
    printf("List is already empty or node to be deleted does not exist.\n");
    return;
  }
  if (*head == node) {
    delete_at_beginning(head);
    return;
  }
  Node *current = *head;
  while (current->next != node) {
    current = current->next;
  }
  if (current->next == NULL) {
    printf("Node to be deleted does not exist.\n");
    return;
  }
  current->next = node->next;
  free(node);
}

// Reverse the linked list
void reverse_list(Node **head) {
  Node *prev = NULL;
  Node *current = *head;
  Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

// Print the linked list
void print_list(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a linked list
  Node *head = NULL;
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_end(&head, 30);
  insert_after(head->next, 40);

  // Print the linked list
  printf("Original linked list: ");
  print_list(head);

  // Delete a node from the beginning of the list
  delete_at_beginning(&head);

  // Print the linked list
  printf("Linked list after deleting a node from the beginning: ");
  print_list(head);

  // Delete a node from the end of the list
  delete_at_end(&head);

  // Print the linked list
  printf("Linked list after deleting a node from the end: ");
  print_list(head);

  // Delete a node from the middle of the list
  delete_node(&head, head->next);

  // Print the linked list
  printf("Linked list after deleting a node from the middle: ");
  print_list(head);

  // Reverse the linked list
  reverse_list(&head);

  // Print the linked list
  printf("Reversed linked list: ");
  print_list(head);

  return 0;
}