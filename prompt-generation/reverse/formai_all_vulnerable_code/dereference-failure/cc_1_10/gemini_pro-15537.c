//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: innovative
// The C Linked List Song

#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Create a new node
node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
node_t *insert_at_beginning(node_t *head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = head;
  head = new_node;
  return head;
}

// Insert a node at the end of the list
node_t *insert_at_end(node_t *head, int data) {
  node_t *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
  } else {
    node_t *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
  return head;
}

// Insert a node after a given node
node_t *insert_after(node_t *head, int data, int after) {
  node_t *new_node = create_node(data);
  if (head == NULL) {
    head = new_node;
  } else {
    node_t *temp = head;
    while (temp != NULL && temp->data != after) {
      temp = temp->next;
    }
    if (temp != NULL) {
      new_node->next = temp->next;
      temp->next = new_node;
    }
  }
  return head;
}

// Delete a node from the beginning of the list
node_t *delete_from_beginning(node_t *head) {
  if (head != NULL) {
    node_t *temp = head;
    head = head->next;
    free(temp);
  }
  return head;
}

// Delete a node from the end of the list
node_t *delete_from_end(node_t *head) {
  if (head != NULL) {
    if (head->next == NULL) {
      free(head);
      head = NULL;
    } else {
      node_t *temp = head;
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      free(temp->next);
      temp->next = NULL;
    }
  }
  return head;
}

// Delete a node after a given node
node_t *delete_after(node_t *head, int after) {
  if (head != NULL) {
    node_t *temp = head;
    while (temp != NULL && temp->data != after) {
      temp = temp->next;
    }
    if (temp != NULL && temp->next != NULL) {
      node_t *to_delete = temp->next;
      temp->next = temp->next->next;
      free(to_delete);
    }
  }
  return head;
}

// Print the list
void print_list(node_t *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a linked list
  node_t *head = NULL;

  // Insert some nodes
  head = insert_at_beginning(head, 1);
  head = insert_at_beginning(head, 2);
  head = insert_at_beginning(head, 3);
  head = insert_at_end(head, 4);
  head = insert_at_end(head, 5);
  head = insert_at_end(head, 6);
  head = insert_after(head, 7, 3);
  head = insert_after(head, 8, 6);

  // Print the list
  printf("Original list: ");
  print_list(head);

  // Delete some nodes
  head = delete_from_beginning(head);
  head = delete_from_end(head);
  head = delete_after(head, 3);

  // Print the list
  printf("Modified list: ");
  print_list(head);

  return 0;
}