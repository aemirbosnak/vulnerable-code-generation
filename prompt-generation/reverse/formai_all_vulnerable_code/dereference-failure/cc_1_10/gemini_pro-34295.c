//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Our love story will be a linked list of nodes.
typedef struct node {
  int data;
  struct node *next;
} node;

// The first node in the linked list is called the head.
node *head = NULL;

// Function to create a new node with the given data.
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a new node at the beginning of the linked list.
void insert_at_beginning(int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  head = new_node;
}

// Function to insert a new node at the end of the linked list.
void insert_at_end(int data) {
  node *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
    return;
  }
  node *last_node = head;
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
}

// Function to insert a new node after a given node.
void insert_after(node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }
  node *new_node = create_node(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Function to delete a node from the linked list.
void delete_node(node *node_to_delete) {
  if (node_to_delete == NULL) {
    printf("Node to delete cannot be NULL\n");
    return;
  }
  if (node_to_delete == head) {
    head = head->next;
  } else {
    node *prev_node = head;
    while (prev_node->next != node_to_delete) {
      prev_node = prev_node->next;
    }
    prev_node->next = node_to_delete->next;
  }
  free(node_to_delete);
}

// Function to print the linked list.
void print_linked_list() {
  node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// The main function is where our love story begins.
int main() {
  // We meet each other and fall in love.
  insert_at_beginning(2);
  insert_at_end(5);

  // We go on dates and create memories.
  insert_after(head, 7);
  insert_after(head->next, 11);

  // We share our dreams and aspirations.
  insert_at_end(13);

  // We face challenges together and overcome them.
  delete_node(head->next->next);

  // We grow stronger and more connected.
  insert_after(head->next, 9);

  // We cherish each moment we have together.
  print_linked_list();

  return 0;
}