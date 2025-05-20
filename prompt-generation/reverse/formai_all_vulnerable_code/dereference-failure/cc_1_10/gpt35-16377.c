//FormAI DATASET v1.0 Category: Linked list operations ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// Declare the structure of the linked list node
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *create_new_node(int data) {
  Node *new_node = (Node*)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the linked list
void insert_at_beginning(Node **head, int data) {
  Node *new_node = create_new_node(data);
  new_node->next = *head;
  *head = new_node;
}

// Function to insert a node at the end of the linked list
void insert_at_end(Node **head, int data) {
  Node *new_node = create_new_node(data);
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

// Function to insert a node after a given node
void insert_after_node(Node *node, int data) {
  if (node == NULL) {
    return;
  }
  Node *new_node = create_new_node(data);
  new_node->next = node->next;
  node->next = new_node;
}

// Function to delete a node from the linked list
void delete_node(Node **head, int data) {
  if (*head == NULL) {
    return;
  }
  Node *current_node = *head;
  Node *previous_node = NULL;
  if (current_node->data == data) {
    *head = current_node->next;
    free(current_node);
    return;
  }
  while (current_node != NULL && current_node->data != data) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (current_node == NULL) {
    return;
  }
  previous_node->next = current_node->next;
  free(current_node);
}

// Function to display the linked list
void display_list(Node *head) {
  if (head == NULL) {
    return;
  }
  printf("Current linked list: ");
  Node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  // Insert nodes at the beginning of the linked list
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_beginning(&head, 30);
  display_list(head);

  // Insert nodes at the end of the linked list
  insert_at_end(&head, 40);
  insert_at_end(&head, 50);
  insert_at_end(&head, 60);
  display_list(head);

  // Insert nodes after a given node
  insert_after_node(head->next->next, 70);
  insert_after_node(head->next->next->next->next, 80);
  display_list(head);

  // Delete nodes from the linked list
  delete_node(&head, 20);
  delete_node(&head, 50);
  display_list(head);

  return 0;
}