//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list node
typedef struct node {
  char *data;
  struct node *next;
} node;

// Create a new linked list node
node *create_node(char *data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(node **head, node *new_node) {
  new_node->next = *head;
  *head = new_node;
}

// Insert a new node at the end of the linked list
void insert_at_end(node **head, node *new_node) {
  if (*head == NULL) {
    *head = new_node;
  } else {
    node *curr = *head;
    while (curr->next != NULL) {
      curr = curr->next;
    }
    curr->next = new_node;
  }
}

// Delete a node from the linked list
void delete_node(node **head, char *data) {
  if (*head == NULL) {
    return;
  }

  if (strcmp((*head)->data, data) == 0) {
    *head = (*head)->next;
  } else {
    node *prev = *head;
    node *curr = (*head)->next;

    while (curr != NULL) {
      if (strcmp(curr->data, data) == 0) {
        prev->next = curr->next;
        free(curr);
        return;
      }

      prev = curr;
      curr = curr->next;
    }
  }
}

// Print the linked list
void print_linked_list(node *head) {
  node *curr = head;

  while (curr != NULL) {
    printf("%s ", curr->data);
    curr = curr->next;
  }

  printf("\n");
}

// Free the linked list
void free_linked_list(node *head) {
  node *curr = head;

  while (curr != NULL) {
    node *next = curr->next;
    free(curr);
    curr = next;
  }
}

// Get the length of the linked list
int get_length(node *head) {
  int length = 0;

  node *curr = head;

  while (curr != NULL) {
    length++;
    curr = curr->next;
  }

  return length;
}

// Reverse the linked list
node *reverse_linked_list(node *head) {
  node *prev = NULL;
  node *curr = head;
  node *next;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return prev;
}

// Test the linked list
int main() {
  node *head = NULL;

  // Insert some data into the linked list
  insert_at_beginning(&head, create_node("Hello"));
  insert_at_beginning(&head, create_node("World"));
  insert_at_end(&head, create_node("!"));

  // Print the linked list
  printf("Original linked list: ");
  print_linked_list(head);

  // Get the length of the linked list
  printf("Length of the linked list: %d\n", get_length(head));

  // Reverse the linked list
  head = reverse_linked_list(head);

  // Print the reversed linked list
  printf("Reversed linked list: ");
  print_linked_list(head);

  // Delete a node from the linked list
  delete_node(&head, "World");

  // Print the modified linked list
  printf("Modified linked list: ");
  print_linked_list(head);

  // Free the linked list
  free_linked_list(head);

  return 0;
}