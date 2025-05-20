//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
typedef struct node {
  char *value;
  struct node *next;
} node;

// Define the linked list structure
typedef struct linked_list {
  node *head;
  node *tail;
  int size;
} linked_list;

// Create a new linked list
linked_list *create_linked_list() {
  linked_list *list = malloc(sizeof(linked_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Add a new node to the linked list
void add_node(linked_list *list, char *value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }

  list->size++;
}

// Print the linked list
void print_linked_list(linked_list *list) {
  node *current_node = list->head;

  while (current_node != NULL) {
    printf("%s\n", current_node->value);
    current_node = current_node->next;
  }
}

// Free the linked list
void free_linked_list(linked_list *list) {
  node *current_node = list->head;

  while (current_node != NULL) {
    node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  free(list);
}

// Main function
int main() {
  // Create a new linked list
  linked_list *list = create_linked_list();

  // Add some nodes to the linked list
  add_node(list, "Hello");
  add_node(list, "World");
  add_node(list, "!");

  // Print the linked list
  printf("Linked list:\n");
  print_linked_list(list);

  // Free the linked list
  free_linked_list(list);

  return 0;
}