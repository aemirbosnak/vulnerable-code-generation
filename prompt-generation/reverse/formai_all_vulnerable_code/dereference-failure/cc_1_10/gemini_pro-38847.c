//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(Node **head, int data) {
  Node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(Node **head, int data) {
  Node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  Node *current_node = *head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }
  current_node->next = new_node;
}

// Function to insert a node at a given position in the linked list
void insert_at_position(Node **head, int data, int position) {
  if (position == 1) {
    insert_at_beginning(head, data);
    return;
  }
  Node *new_node = create_node(data);
  Node *current_node = *head;
  for (int i = 1; i < position - 1; i++) {
    current_node = current_node->next;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning(Node **head) {
  if (*head == NULL) {
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Function to delete a node from the end of the linked list
void delete_from_end(Node **head) {
  if (*head == NULL) {
    return;
  }
  Node *current_node = *head;
  Node *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    *head = NULL;
    free(current_node);
    return;
  }
  previous_node->next = NULL;
  free(current_node);
}

// Function to delete a node from a given position in the linked list
void delete_from_position(Node **head, int position) {
  if (position == 1) {
    delete_from_beginning(head);
    return;
  }
  Node *current_node = *head;
  Node *previous_node = NULL;
  for (int i = 1; i < position; i++) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    *head = NULL;
    free(current_node);
    return;
  }
  previous_node->next = current_node->next;
  free(current_node);
}

// Function to print the linked list
void print_linked_list(Node *head) {
  Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;

  // Inserting nodes into the linked list
  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);
  insert_at_position(&head, 4, 2);

  // Printing the linked list
  printf("The original linked list: ");
  print_linked_list(head);

  // Deleting nodes from the linked list
  delete_from_beginning(&head);
  delete_from_end(&head);
  delete_from_position(&head, 2);

  // Printing the linked list after deleting nodes
  printf("The linked list after deleting nodes: ");
  print_linked_list(head);

  return 0;
}