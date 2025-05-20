//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Declare the linked list node
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Function to create a new node
node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the linked list
node_t *insert_at_beginning(node_t *head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Function to insert a new node at the end of the linked list
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

// Function to insert a new node after a given node
node_t *insert_after(node_t *head, int data, int after_data) {
  node_t *new_node = create_node(data);
  node_t *current_node = head;
  while (current_node != NULL) {
    if (current_node->data == after_data) {
      new_node->next = current_node->next;
      current_node->next = new_node;
      return head;
    }
    current_node = current_node->next;
  }
  return head;
}

// Function to delete a node from the beginning of the linked list
node_t *delete_from_beginning(node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  node_t *new_head = head->next;
  free(head);
  return new_head;
}

// Function to delete a node from the end of the linked list
node_t *delete_from_end(node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  node_t *current_node = head;
  node_t *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  previous_node->next = NULL;
  free(current_node);
  return head;
}

// Function to delete a node from the middle of the linked list
node_t *delete_from_middle(node_t *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  node_t *current_node = head;
  node_t *previous_node = NULL;
  while (current_node != NULL) {
    if (current_node->data == data) {
      previous_node->next = current_node->next;
      free(current_node);
      return head;
    }
    previous_node = current_node;
    current_node = current_node->next;
  }
  return head;
}

// Function to search for a node in the linked list
node_t *search(node_t *head, int data) {
  node_t *current_node = head;
  while (current_node != NULL) {
    if (current_node->data == data) {
      return current_node;
    }
    current_node = current_node->next;
  }
  return NULL;
}

// Function to print the linked list
void print_list(node_t *head) {
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Function to free the linked list
void free_list(node_t *head) {
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
  head = insert_at_end(head, 3);
  head = insert_at_end(head, 4);
  head = insert_at_end(head, 5);

  // Print the linked list
  printf("Initial linked list: ");
  print_list(head);

  // Insert a node at the beginning of the linked list
  head = insert_at_beginning(head, 0);

  // Print the linked list
  printf("Linked list after inserting a node at the beginning: ");
  print_list(head);

  // Insert a node at the end of the linked list
  head = insert_at_end(head, 6);

  // Print the linked list
  printf("Linked list after inserting a node at the end: ");
  print_list(head);

  // Insert a node after a given node
  head = insert_after(head, 2.5, 2);

  // Print the linked list
  printf("Linked list after inserting a node after a given node: ");
  print_list(head);

  // Delete a node from the beginning of the linked list
  head = delete_from_beginning(head);

  // Print the linked list
  printf("Linked list after deleting a node from the beginning: ");
  print_list(head);

  // Delete a node from the end of the linked list
  head = delete_from_end(head);

  // Print the linked list
  printf("Linked list after deleting a node from the end: ");
  print_list(head);

  // Delete a node from the middle of the linked list
  head = delete_from_middle(head, 2.5);

  // Print the linked list
  printf("Linked list after deleting a node from the middle: ");
  print_list(head);

  // Search for a node in the linked list
  node_t *found_node = search(head, 3);
  if (found_node != NULL) {
    printf("Node found: %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  // Free the linked list
  free_list(head);

  return 0;
}