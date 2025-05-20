//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the structure of a node in the linked list
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the head of the linked list
node_t *head = NULL;

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(int data) {
  // Create a new node
  node_t *new_node = (node_t *)malloc(sizeof(node_t));

  // Set the data of the new node
  new_node->data = data;

  // Set the next pointer of the new node to the current head
  new_node->next = head;

  // Set the head to the new node
  head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(int data) {
  // Create a new node
  node_t *new_node = (node_t *)malloc(sizeof(node_t));

  // Set the data of the new node
  new_node->data = data;

  // Set the next pointer of the new node to NULL
  new_node->next = NULL;

  // If the linked list is empty, set the head to the new node
  if (head == NULL) {
    head = new_node;
  } else {
    // Traverse the linked list until we reach the last node
    node_t *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }

    // Set the next pointer of the last node to the new node
    current_node->next = new_node;
  }
}

// Function to insert a node at a given index in the linked list
void insert_at_index(int data, int index) {
  // Create a new node
  node_t *new_node = (node_t *)malloc(sizeof(node_t));

  // Set the data of the new node
  new_node->data = data;

  // If the index is 0, insert the node at the beginning of the linked list
  if (index == 0) {
    insert_at_beginning(data);
    return;
  }

  // Traverse the linked list until we reach the node before the given index
  node_t *current_node = head;
  for (int i = 0; i < index - 1; i++) {
    current_node = current_node->next;
  }

  // Set the next pointer of the new node to the node after the given index
  new_node->next = current_node->next;

  // Set the next pointer of the node before the given index to the new node
  current_node->next = new_node;
}

// Function to delete a node from the beginning of the linked list
void delete_from_beginning() {
  // If the linked list is empty, do nothing
  if (head == NULL) {
    return;
  }

  // Set the head to the next node
  head = head->next;

  // Free the memory of the deleted node
  free(head);
}

// Function to delete a node from the end of the linked list
void delete_from_end() {
  // If the linked list is empty, do nothing
  if (head == NULL) {
    return;
  }

  // Traverse the linked list until we reach the last node
  node_t *current_node = head;
  while (current_node->next != NULL) {
    current_node = current_node->next;
  }

  // Set the next pointer of the second last node to NULL
  current_node->next = NULL;

  // Free the memory of the deleted node
  free(current_node);
}

// Function to delete a node from a given index in the linked list
void delete_from_index(int index) {
  // If the linked list is empty, do nothing
  if (head == NULL) {
    return;
  }

  // If the index is 0, delete the node from the beginning of the linked list
  if (index == 0) {
    delete_from_beginning();
    return;
  }

  // Traverse the linked list until we reach the node before the given index
  node_t *current_node = head;
  for (int i = 0; i < index - 1; i++) {
    current_node = current_node->next;
  }

  // Set the next pointer of the node before the given index to the node after the given index
  current_node->next = current_node->next->next;

  // Free the memory of the deleted node
  free(current_node->next);
}

// Function to print the linked list
void print_linked_list() {
  // If the linked list is empty, do nothing
  if (head == NULL) {
    return;
  }

  // Traverse the linked list and print the data of each node
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

// Main function
int main() {
  // Insert some elements into the linked list
  insert_at_beginning(10);
  insert_at_end(20);
  insert_at_index(30, 1);
  insert_at_index(40, 3);

  // Print the linked list
  printf("Linked list before deletion:\n");
  print_linked_list();

  // Delete some elements from the linked list
  delete_from_beginning();
  delete_from_end();
  delete_from_index(2);

  // Print the linked list
  printf("Linked list after deletion:\n");
  print_linked_list();

  return 0;
}