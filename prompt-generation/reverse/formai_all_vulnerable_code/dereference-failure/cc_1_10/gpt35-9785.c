//FormAI DATASET v1.0 Category: Data structures visualization ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for linked list
struct node {
  int data;
  struct node *next;
};

// Define a function to create a new node
struct node *newNode(int data) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Define a function to insert a new node at the beginning of the linked list
void push(struct node **head_ref, int data) {
  struct node *new_node = newNode(data);
  new_node->next = *head_ref;
  *head_ref = new_node;
}

// Define a function to insert a new node after a given node in the linked list
void insertAfter(struct node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL!");
    return;
  }
  struct node *new_node = newNode(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

// Define a function to append a new node at the end of the linked list
void append(struct node **head_ref, int data) {
  struct node *new_node = newNode(data);
  struct node *last = *head_ref;
  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_node;
}

// Define a function to delete a node with a given key from the linked list
void deleteNode(struct node **head_ref, int key) {
  struct node *temp = *head_ref, *prev;
  if (temp != NULL && temp->data == key) {
    *head_ref = temp->next;
    free(temp);
    return;
  }
  while (temp != NULL && temp->data != key) {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Key not found in the linked list!");
    return;
  }
  prev->next = temp->next;
  free(temp);
}

// Define a function to print the linked list
void printList(struct node *node) {
  while (node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL\n");
}

int main() {
  struct node *head = NULL;
  
  // Create a linked list with 4 nodes
  append(&head, 1);
  append(&head, 2);
  push(&head, 0);
  insertAfter(head->next, 3);
  
  // Print out the linked list
  printf("Linked list before deletion:\n");
  printList(head);
  
  // Delete node with key 2
  deleteNode(&head, 2);
  
  // Print out the updated linked list
  printf("Linked list after deletion:\n");
  printList(head);
  
  return 0;
}