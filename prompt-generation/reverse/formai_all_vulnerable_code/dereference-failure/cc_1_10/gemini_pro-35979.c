//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Insert a node at the beginning of the linked list
struct node *insert_at_beginning(struct node *head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = head;
  head = new_node;
  return head;
}

// Insert a node at the end of the linked list
struct node *insert_at_end(struct node *head, int data) {
  struct node *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
    return head;
  }
  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  return head;
}

// Insert a node at a specific position in the linked list
struct node *insert_at_position(struct node *head, int data, int position) {
  struct node *new_node = create_node(data);
  if (position == 0) {
    head = insert_at_beginning(head, data);
    return head;
  }
  struct node *temp = head;
  for (int i = 0; i < position - 1; i++) {
    if (temp->next == NULL) {
      printf("Invalid position\n");
      return head;
    }
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
  return head;
}

// Delete a node from the beginning of the linked list
struct node *delete_from_beginning(struct node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }
  struct node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Delete a node from the end of the linked list
struct node *delete_from_end(struct node *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }
  struct node *temp = head;
  struct node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  if (prev == NULL) {
    head = NULL;
    free(temp);
    return head;
  }
  prev->next = NULL;
  free(temp);
  return head;
}

// Delete a node from a specific position in the linked list
struct node *delete_from_position(struct node *head, int position) {
  if (head == NULL) {
    printf("List is empty\n");
    return head;
  }
  if (position == 0) {
    head = delete_from_beginning(head);
    return head;
  }
  struct node *temp = head;
  struct node *prev = NULL;
  for (int i = 0; i < position; i++) {
    if (temp->next == NULL) {
      printf("Invalid position\n");
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  free(temp);
  return head;
}

// Print the linked list
void print_list(struct node *head) {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

// Main function
int main() {
  struct node *head = NULL;
  head = insert_at_end(head, 10);
  head = insert_at_end(head, 20);
  head = insert_at_end(head, 30);
  head = insert_at_end(head, 40);
  head = insert_at_end(head, 50);
  print_list(head);
  head = delete_from_beginning(head);
  print_list(head);
  head = delete_from_end(head);
  print_list(head);
  head = delete_from_position(head, 2);
  print_list(head);
  return 0;
}