//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Creates a new node
Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Inserts a new node at the beginning of the linked list
Node *insert_at_beginning(Node *head, int data) {
  Node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Inserts a new node at the end of the linked list
Node *insert_at_end(Node *head, int data) {
  Node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Inserts a new node after a given node
Node *insert_after(Node *head, int after_data, int data) {
  if (head == NULL) {
    return NULL;
  }
  Node *current = head;
  while (current != NULL) {
    if (current->data == after_data) {
      Node *new_node = create_node(data);
      new_node->next = current->next;
      current->next = new_node;
      return head;
    }
    current = current->next;
  }
  return NULL;
}

// Deletes a node from the linked list
Node *delete_node(Node *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  if (head->data == data) {
    Node *new_head = head->next;
    free(head);
    return new_head;
  }
  Node *current = head;
  while (current->next != NULL) {
    if (current->next->data == data) {
      Node *temp = current->next;
      current->next = current->next->next;
      free(temp);
      return head;
    }
    current = current->next;
  }
  return NULL;
}

// Prints the linked list
void print_linked_list(Node *head) {
  Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  head = insert_at_end(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_end(head, 3);
  head = insert_at_end(head, 4);
  head = insert_at_end(head, 5);
  print_linked_list(head);
  head = insert_at_beginning(head, 0);
  print_linked_list(head);
  head = insert_after(head, 2, 2.5);
  print_linked_list(head);
  head = delete_node(head, 3);
  print_linked_list(head);
  return 0;
}