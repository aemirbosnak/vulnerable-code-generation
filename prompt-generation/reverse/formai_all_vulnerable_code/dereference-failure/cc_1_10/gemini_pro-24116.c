//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
  int data;
  struct node *next;
};

// Create a new node
struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(struct node **head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(struct node **head, int data) {
  struct node *new_node = create_node(data);
  struct node *temp = *head;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = new_node;
}

// Insert a node after a given node
void insert_after_node(struct node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }

  struct node *new_node = create_node(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(struct node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct node *temp = *head;
  *head = temp->next;
  free(temp);
}

// Delete a node from the end of the list
void delete_from_end(struct node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }

  struct node *temp = *head;
  struct node *prev = NULL;

  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL) {
    *head = NULL;
  } else {
    prev->next = NULL;
  }

  free(temp);
}

// Delete a node from the middle of the list
void delete_node(struct node **head, struct node *node_to_delete) {
  if (*head == NULL || node_to_delete == NULL) {
    printf("List or node to delete is empty\n");
    return;
  }

  struct node *temp = *head;
  struct node *prev = NULL;

  while (temp != node_to_delete) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL) {
    *head = temp->next;
  } else {
    prev->next = temp->next;
  }

  free(temp);
}

// Print the list
void print_list(struct node *head) {
  struct node *temp = head;

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

// Driver code
int main() {
  struct node *head = NULL;

  // Insert some nodes into the list
  insert_at_beginning(&head, 10);
  insert_at_end(&head, 20);
  insert_at_end(&head, 30);
  insert_after_node(head->next, 15);

  // Print the list
  printf("Original list: ");
  print_list(head);

  // Delete a node from the beginning of the list
  delete_from_beginning(&head);

  // Print the list
  printf("List after deleting a node from the beginning: ");
  print_list(head);

  // Delete a node from the end of the list
  delete_from_end(&head);

  // Print the list
  printf("List after deleting a node from the end: ");
  print_list(head);

  // Delete a node from the middle of the list
  delete_node(&head, head->next);

  // Print the list
  printf("List after deleting a node from the middle: ");
  print_list(head);

  return 0;
}