//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure
typedef struct node {
  int data;
  struct node *next;
} node;

// Function to create a new node
node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Function to insert a node at the beginning of the list
node *insert_at_beginning(node *head, int data) {
  node *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Function to insert a node at the end of the list
node *insert_at_end(node *head, int data) {
  node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Function to insert a node after a given node
node *insert_after_node(node *head, int data, int after) {
  node *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node *current = head;
  while (current != NULL) {
    if (current->data == after) {
      new_node->next = current->next;
      current->next = new_node;
      return head;
    }
    current = current->next;
  }
  return head;
}

// Function to delete a node from the beginning of the list
node *delete_at_beginning(node *head) {
  if (head == NULL) {
    return NULL;
  }
  node *new_head = head->next;
  free(head);
  return new_head;
}

// Function to delete a node from the end of the list
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

// Function to delete a node after a given node
node *delete_after_node(node *head, int after) {
  if (head == NULL) {
    return NULL;
  }
  node *current = head;
  while (current != NULL) {
    if (current->data == after) {
      if (current->next == NULL) {
        return head;
      }
      node *temp = current->next;
      current->next = temp->next;
      free(temp);
      return head;
    }
    current = current->next;
  }
  return head;
}

// Function to search for a node in the list
int search_node(node *head, int data) {
  if (head == NULL) {
    return -1;
  }
  node *current = head;
  int index = 0;
  while (current != NULL) {
    if (current->data == data) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;
}

// Function to print the list
void print_list(node *head) {
  if (head == NULL) {
    printf("Empty list.\n");
    return;
  }
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Driver code to test the linked list operations
int main() {
  // Create an empty linked list
  node *head = NULL;

  // Insert a node at the beginning of the list
  head = insert_at_beginning(head, 10);

  // Insert a node at the end of the list
  head = insert_at_end(head, 20);

  // Insert a node after the first node
  head = insert_after_node(head, 30, 10);

  // Delete a node from the beginning of the list
  head = delete_at_beginning(head);

  // Delete a node from the end of the list
  head = delete_at_end(head);

  // Delete a node after the first node
  head = delete_after_node(head, 10);

  // Search for a node in the list
  int index = search_node(head, 20);
  if (index == -1) {
    printf("Node not found.\n");
  } else {
    printf("Node found at index %d.\n", index);
  }

  // Print the list
  print_list(head);

  return 0;
}