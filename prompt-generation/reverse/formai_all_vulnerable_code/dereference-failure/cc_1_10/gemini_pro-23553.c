//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Create a new node
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Insert a node at the end of the list
node *insert_at_end(node *head, int data) {
  node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
  return head;
}

// Insert a node after a given node
node *insert_after_node(node *head, int data, int after_data) {
  node *new_node = create_node(data);
  node *temp = head;
  while (temp != NULL) {
    if (temp->data == after_data) {
      new_node->next = temp->next;
      temp->next = new_node;
      return head;
    }
    temp = temp->next;
  }
  printf("Node not found\n");
  return head;
}

// Delete a node from the beginning of the list
node *delete_from_beginning(node *head) {
  if (head == NULL) {
    return NULL;
  }
  node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Delete a node from the end of the list
node *delete_from_end(node *head) {
  if (head == NULL) {
    return NULL;
  }
  node *temp = head;
  node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  if (prev == NULL) {
    return NULL;
  }
  prev->next = NULL;
  free(temp);
  return head;
}

// Delete a node from the list
node *delete_node(node *head, int data) {
  if (head == NULL) {
    return NULL;
  }
  node *temp = head;
  node *prev = NULL;
  while (temp != NULL) {
    if (temp->data == data) {
      if (prev == NULL) {
        return head->next;
      }
      prev->next = temp->next;
      free(temp);
      return head;
    }
    prev = temp;
    temp = temp->next;
  }
  printf("Node not found\n");
  return head;
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
  // Create the head of the list
  node *head = NULL;

  // Insert some nodes into the list
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_end(head, 3);
  head = insert_after_node(head, 4, 2);

  // Print the list
  printf("Original list: ");
  print_list(head);

  // Delete a node from the beginning of the list
  head = delete_from_beginning(head);

  // Delete a node from the end of the list
  head = delete_from_end(head);

  // Delete a node from the list
  head = delete_node(head, 4);

  // Print the list
  printf("Modified list: ");
  print_list(head);

  return 0;
}