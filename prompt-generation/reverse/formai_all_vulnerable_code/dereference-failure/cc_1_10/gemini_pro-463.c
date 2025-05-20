//GEMINI-pro DATASET v1.0 Category: Educational ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Defining the structure of a node
typedef struct node {
  int data;
  struct node *next;
} node;

// Inserting a node at the beginning of a linked list
node *insert_at_beginning(node *head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
  return head;
}

// Inserting a node at the end of a linked list
node *insert_at_end(node *head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
    return head;
  }
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  return head;
}

// Inserting a node at a specific position in a linked list
node *insert_at_position(node *head, int data, int position) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  if (position == 1) {
    return insert_at_beginning(head, data);
  }
  node *temp = head;
  for (int i = 1; i < position - 1; i++) {
    if (!temp) {
      printf("The position is out of range!\n");
      return head;
    }
    temp = temp->next;
  }
  if (!temp) {
    printf("The position is out of range!\n");
    return head;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  return head;
}

// Deleting a node from the beginning of a linked list
node *delete_at_beginning(node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return head;
  }
  node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Deleting a node from the end of a linked list
node *delete_at_end(node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return head;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return head;
}

// Deleting a node from a specific position in a linked list
node *delete_at_position(node *head, int position) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return head;
  }
  if (position == 1) {
    return delete_at_beginning(head);
  }
  node *temp = head;
  for (int i = 1; i < position - 1; i++) {
    if (!temp) {
      printf("The position is out of range!\n");
      return head;
    }
    temp = temp->next;
  }
  if (!temp->next) {
    printf("The position is out of range!\n");
    return head;
  }
  node *to_delete = temp->next;
  temp->next = to_delete->next;
  free(to_delete);
  return head;
}

// Reversing a linked list using iteration
node *reverse_linked_list_iteration(node *head) {
  node *previous = NULL;
  node *current = head;
  node *next;
  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  return previous;
}

// Reversing a linked list using recursion
node *reverse_linked_list_recursion(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  node *new_head = reverse_linked_list_recursion(head->next);
  head->next->next = head;
  head->next = NULL;
  return new_head;
}

// Printing a linked list
void print_linked_list(node *head) {
  if (head == NULL) {
    printf("The linked list is empty!\n");
    return;
  }
  node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Creating a linked list
  node *head = NULL;
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_position(head, 3, 2);
  print_linked_list(head);  // Output: 1 3 2

  // Deleting a node from the beginning of the linked list
  head = delete_at_beginning(head);
  print_linked_list(head);  // Output: 3 2

  // Deleting a node from the end of the linked list
  head = delete_at_end(head);
  print_linked_list(head);  // Output: 3

  // Deleting a node from a specific position in the linked list
  head = delete_at_position(head, 1);
  print_linked_list(head);  // Output:

  // Reversing the linked list using iteration
  head = reverse_linked_list_iteration(head);
  print_linked_list(head);  // Output:

  // Reversing the linked list using recursion
  head = reverse_linked_list_recursion(head);
  print_linked_list(head);  // Output:

  return 0;
}