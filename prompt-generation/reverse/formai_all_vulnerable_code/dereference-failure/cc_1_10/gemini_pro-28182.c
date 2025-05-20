//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: curious
#include <stdio.h>
#include <stdlib.h>

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

// Insert a node at the beginning of a linked list
node *insert_at_beginning(node *head, int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Insert a node at the end of a linked list
node *insert_at_end(node *head, int data) {
  if (head == NULL) {
    return create_node(data);
  }
  node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = create_node(data);
  return head;
}

// Insert a node at a specific position in a linked list
node *insert_at_position(node *head, int data, int position) {
  if (position == 0) {
    return insert_at_beginning(head, data);
  }
  node *current = head;
  for (int i = 0; i < position - 1; i++) {
    if (current->next == NULL) {
      return head;
    }
    current = current->next;
  }
  node *new_node = create_node(data);
  new_node->next = current->next;
  current->next = new_node;
  return head;
}

// Delete a node from the beginning of a linked list
node *delete_at_beginning(node *head) {
  if (head == NULL) {
    return NULL;
  }
  node *new_head = head->next;
  free(head);
  return new_head;
}

// Delete a node from the end of a linked list
node *delete_at_end(node *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  node *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  return head;
}

// Delete a node from a specific position in a linked list
node *delete_at_position(node *head, int position) {
  if (position == 0) {
    return delete_at_beginning(head);
  }
  node *current = head;
  for (int i = 0; i < position - 1; i++) {
    if (current->next == NULL) {
      return head;
    }
    current = current->next;
  }
  node *temp = current->next;
  current->next = temp->next;
  free(temp);
  return head;
}

// Print a linked list
void print_linked_list(node *head) {
  if (head == NULL) {
    printf("The linked list is empty.\n");
    return;
  }
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Get the length of a linked list
int get_length(node *head) {
  if (head == NULL) {
    return 0;
  }
  return 1 + get_length(head->next);
}

// Find the middle of a linked list
node *get_middle(node *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    return head;
  }
  node *slow = head;
  node *fast = head;
  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

int main() {
  node *head = NULL;

  // Insert some nodes into the linked list
  head = insert_at_end(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_end(head, 3);
  head = insert_at_end(head, 4);
  head = insert_at_end(head, 5);

  // Print the linked list
  printf("The original linked list: ");
  print_linked_list(head);

  // Insert a node at the beginning of the linked list
  head = insert_at_beginning(head, 0);

  // Print the linked list
  printf("The linked list after inserting a node at the beginning: ");
  print_linked_list(head);

  // Insert a node at the end of the linked list
  head = insert_at_end(head, 6);

  // Print the linked list
  printf("The linked list after inserting a node at the end: ");
  print_linked_list(head);

  // Insert a node at a specific position in the linked list
  head = insert_at_position(head, 7, 3);

  // Print the linked list
  printf("The linked list after inserting a node at a specific position: ");
  print_linked_list(head);

  // Delete a node from the beginning of the linked list
  head = delete_at_beginning(head);

  // Print the linked list
  printf("The linked list after deleting a node from the beginning: ");
  print_linked_list(head);

  // Delete a node from the end of the linked list
  head = delete_at_end(head);

  // Print the linked list
  printf("The linked list after deleting a node from the end: ");
  print_linked_list(head);

  // Delete a node from a specific position in the linked list
  head = delete_at_position(head, 3);

  // Print the linked list
  printf("The linked list after deleting a node from a specific position: ");
  print_linked_list(head);

  // Get the length of the linked list
  int length = get_length(head);
  printf("The length of the linked list: %d\n", length);

  // Find the middle of the linked list
  node *middle = get_middle(head);
  if (middle == NULL) {
    printf("The linked list is empty.\n");
  } else {
    printf("The middle of the linked list: %d\n", middle->data);
  }

  return 0;
}