//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet style linked list operations

typedef struct node {
  int data;
  struct node *next;
} node;

// Create a new node
node* create_node(int data) {
  node *new_node = (node*)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
void insert_at_beginning(node **head, int data) {
  node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Insert a node at the end of the list
void insert_at_end(node **head, int data) {
  node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

// Insert a node after a given node
void insert_after(node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }
  node *new_node = create_node(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Delete a node from the beginning of the list
void delete_from_beginning(node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Delete a node from the end of the list
void delete_from_end(node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
    return;
  }
  node *temp = *head;
  node *prev = NULL;
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
void delete_from_middle(node **head, node *node_to_delete) {
  if (*head == NULL || node_to_delete == NULL) {
    printf("List is empty or node to delete is NULL\n");
    return;
  }
  if (*head == node_to_delete) {
    delete_from_beginning(head);
    return;
  }
  node *temp = *head;
  node *prev = NULL;
  while (temp != node_to_delete) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Node to delete not found\n");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

// Print the list
void print_list(node *head) {
  node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  node *head = NULL;

  // Inserting nodes at the beginning of the list
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_beginning(&head, 30);

  // Inserting nodes at the end of the list
  insert_at_end(&head, 40);
  insert_at_end(&head, 50);
  insert_at_end(&head, 60);

  // Inserting a node after a given node
  insert_after(head->next, 35);

  // Deleting a node from the beginning of the list
  delete_from_beginning(&head);

  // Deleting a node from the end of the list
  delete_from_end(&head);

  // Deleting a node from the middle of the list
  delete_from_middle(&head, head->next->next);

  // Printing the list
  print_list(head);

  return 0;
}