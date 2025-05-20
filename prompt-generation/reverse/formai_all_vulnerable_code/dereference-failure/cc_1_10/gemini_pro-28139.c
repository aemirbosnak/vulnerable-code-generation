//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the linked list structure
typedef struct list {
  node_t *head;
  node_t *tail;
  int size;
} list_t;

// Create a new linked list
list_t *create_list() {
  list_t *list = malloc(sizeof(list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Destroy a linked list
void destroy_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(list_t *list, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(list_t *list, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

// Insert a node at a specific position in the linked list
void insert_at_position(list_t *list, int data, int position) {
  if (position == 0) {
    insert_at_beginning(list, data);
  } else if (position == list->size) {
    insert_at_end(list, data);
  } else {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    node_t *current = list->head;
    for (int i = 0; i < position - 1; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
  }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(list_t *list) {
  if (list->head == NULL) {
    return;
  }
  node_t *current = list->head;
  list->head = current->next;
  free(current);
  list->size--;
  if (list->head == NULL) {
    list->tail = NULL;
  }
}

// Delete a node from the end of the linked list
void delete_from_end(list_t *list) {
  if (list->tail == NULL) {
    return;
  }
  node_t *current = list->head;
  while (current->next != list->tail) {
    current = current->next;
  }
  free(list->tail);
  list->tail = current;
  current->next = NULL;
  list->size--;
  if (list->tail == NULL) {
    list->head = NULL;
  }
}

// Delete a node from a specific position in the linked list
void delete_from_position(list_t *list, int position) {
  if (position == 0) {
    delete_from_beginning(list);
  } else if (position == list->size - 1) {
    delete_from_end(list);
  } else {
    node_t *current = list->head;
    for (int i = 0; i < position - 1; i++) {
      current = current->next;
    }
    node_t *next = current->next->next;
    free(current->next);
    current->next = next;
    list->size--;
  }
}

// Print the linked list
void print_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Main function
int main() {
  // Create a new linked list
  list_t *list = create_list();

  // Insert some nodes into the linked list
  insert_at_beginning(list, 1);
  insert_at_end(list, 2);
  insert_at_position(list, 3, 1);

  // Print the linked list
  printf("The linked list is: ");
  print_list(list);

  // Delete some nodes from the linked list
  delete_from_beginning(list);
  delete_from_end(list);
  delete_from_position(list, 0);

  // Print the linked list
  printf("The linked list is: ");
  print_list(list);

  // Destroy the linked list
  destroy_list(list);

  return 0;
}