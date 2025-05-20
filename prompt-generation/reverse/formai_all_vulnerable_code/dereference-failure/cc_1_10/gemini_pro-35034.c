//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdlib.h>
#include <stdio.h>

// Define a simple struct to represent a node in a linked list
typedef struct node {
  int data;
  struct node *next;
} node;

// Create a new node with the given data
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Error allocating memory for new node.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(node **head, int data) {
  node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(node **head, int data) {
  node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

// Delete the first node in the linked list
void delete_first_node(node **head) {
  if (*head == NULL) {
    printf("Error: Cannot delete first node from an empty linked list.\n");
    return;
  }
  node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Delete the last node in the linked list
void delete_last_node(node **head) {
  if (*head == NULL) {
    printf("Error: Cannot delete last node from an empty linked list.\n");
    return;
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  node *current = *head;
  node *previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  previous->next = NULL;
  free(current);
}

// Print the linked list
void print_linked_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Free the entire linked list
void free_linked_list(node *head) {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
}

int main() {
  // Create an empty linked list
  node *head = NULL;

  // Insert some nodes into the linked list
  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);
  insert_at_end(&head, 4);
  insert_at_end(&head, 5);

  // Print the linked list
  printf("Initial linked list: ");
  print_linked_list(head);

  // Delete the first node from the linked list
  delete_first_node(&head);

  // Print the linked list again
  printf("Linked list after deleting first node: ");
  print_linked_list(head);

  // Delete the last node from the linked list
  delete_last_node(&head);

  // Print the linked list again
  printf("Linked list after deleting last node: ");
  print_linked_list(head);

  // Free the entire linked list
  free_linked_list(head);

  return 0;
}