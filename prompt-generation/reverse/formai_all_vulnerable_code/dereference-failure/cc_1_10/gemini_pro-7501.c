//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// Node structure for a singly linked list
struct Node {
  int data;
  struct Node *next;
};

// Function to create a new node
struct Node *create_node(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of a linked list
struct Node *insert_at_beginning(struct Node *head, int data) {
  struct Node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Function to insert a node at the end of a linked list
struct Node *insert_at_end(struct Node *head, int data) {
  struct Node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  struct Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Function to insert a node at a given position in a linked list
struct Node *insert_at_position(struct Node *head, int data, int position) {
  if (position == 0) {
    return insert_at_beginning(head, data);
  }
  struct Node *new_node = create_node(data);
  struct Node *current = head;
  for (int i = 0; i < position - 1; i++) {
    if (current == NULL) {
      printf("Invalid position\n");
      return head;
    }
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  return head;
}

// Function to delete a node from the beginning of a linked list
struct Node *delete_from_beginning(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return NULL;
  }
  struct Node *new_head = head->next;
  free(head);
  return new_head;
}

// Function to delete a node from the end of a linked list
struct Node *delete_from_end(struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  struct Node *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  return head;
}

// Function to delete a node from a given position in a linked list
struct Node *delete_from_position(struct Node *head, int position) {
  if (position == 0) {
    return delete_from_beginning(head);
  }
  struct Node *current = head;
  for (int i = 0; i < position - 1; i++) {
    if (current == NULL) {
      printf("Invalid position\n");
      return head;
    }
    current = current->next;
  }
  if (current->next == NULL) {
    printf("Invalid position\n");
    return head;
  }
  struct Node *temp = current->next;
  current->next = temp->next;
  free(temp);
  return head;
}

// Function to print a linked list
void print_list(struct Node *head) {
  struct Node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Create an empty linked list
  struct Node *head = NULL;

  // Insert some nodes into the linked list
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_position(head, 3, 1);

  // Print the linked list
  print_list(head);

  // Delete a node from the beginning of the linked list
  head = delete_from_beginning(head);

  // Print the linked list
  print_list(head);

  // Delete a node from the end of the linked list
  head = delete_from_end(head);

  // Print the linked list
  print_list(head);

  // Delete a node from a given position in the linked list
  head = delete_from_position(head, 1);

  // Print the linked list
  print_list(head);

  return 0;
}