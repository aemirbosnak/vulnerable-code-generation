//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the array
#define MAX_SIZE 100

// Define the structure of the node
typedef struct node {
  int value;
  struct node *next;
} node_t;

// Create a new node
node_t *create_node(int value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int value) {
  node_t *new_node = create_node(value);
  new_node->next = *head;
  *head = new_node;
}

// Insert a new node at the end of the list
void insert_at_end(node_t **head, int value) {
  node_t *new_node = create_node(value);
  if (*head == NULL) {
    *head = new_node;
  } else {
    node_t *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Delete a node from the list
void delete_node(node_t **head, int value) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->value == value) {
    *head = (*head)->next;
    return;
  }

  node_t *current = *head;
  while (current->next != NULL) {
    if (current->next->value == value) {
      current->next = current->next->next;
      return;
    }
    current = current->next;
  }
}

// Print the list
void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

// Search for a value in the list using linear search
int linear_search(node_t *head, int value) {
  node_t *current = head;
  while (current != NULL) {
    if (current->value == value) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// Search for a value in the list using binary search
int binary_search(node_t *head, int value) {
  int low = 0;
  int high = MAX_SIZE - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    node_t *current = head;
    for (int i = 0; i < mid; i++) {
      current = current->next;
    }

    if (current->value == value) {
      return 1;
    } else if (current->value < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return 0;
}

// Main function
int main() {
  // Create a linked list
  node_t *head = NULL;
  insert_at_beginning(&head, 10);
  insert_at_beginning(&head, 20);
  insert_at_beginning(&head, 30);
  insert_at_end(&head, 40);
  insert_at_end(&head, 50);

  // Print the list
  print_list(head);

  // Search for a value using linear search
  int value = 30;
  int result = linear_search(head, value);
  if (result) {
    printf("Value %d found using linear search\n", value);
  } else {
    printf("Value %d not found using linear search\n", value);
  }

  // Search for a value using binary search
  value = 40;
  result = binary_search(head, value);
  if (result) {
    printf("Value %d found using binary search\n", value);
  } else {
    printf("Value %d not found using binary search\n", value);
  }

  return 0;
}