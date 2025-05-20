//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Define the linked list structure
typedef struct linked_list {
  node_t *head;
  node_t *tail;
  int size;
} linked_list_t;

// Create a new linked list
linked_list_t *create_linked_list() {
  linked_list_t *list = malloc(sizeof(linked_list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Insert a new node at the beginning of the linked list
void insert_at_beginning(linked_list_t *list, int data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

// Insert a new node at the end of the linked list
void insert_at_end(linked_list_t *list, int data) {
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

// Insert a new node at a specific position in the linked list
void insert_at_position(linked_list_t *list, int data, int position) {
  if (position < 0 || position > list->size) {
    printf("Invalid position!\n");
    return;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = data;
  if (position == 0) {
    new_node->next = list->head;
    list->head = new_node;
  } else {
    node_t *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
      current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
  }
  if (position == list->size) {
    list->tail = new_node;
  }
  list->size++;
}

// Delete the first node in the linked list
void delete_first_node(linked_list_t *list) {
  if (list->head == NULL) {
    printf("List is empty!\n");
    return;
  }
  node_t *temp = list->head;
  list->head = list->head->next;
  free(temp);
  list->size--;
  if (list->head == NULL) {
    list->tail = NULL;
  }
}

// Delete the last node in the linked list
void delete_last_node(linked_list_t *list) {
  if (list->tail == NULL) {
    printf("List is empty!\n");
    return;
  }
  node_t *current_node = list->head;
  while (current_node->next != list->tail) {
    current_node = current_node->next;
  }
  free(list->tail);
  list->tail = current_node;
  list->tail->next = NULL;
  list->size--;
  if (list->head == NULL) {
    list->tail = NULL;
  }
}

// Delete a node at a specific position in the linked list
void delete_at_position(linked_list_t *list, int position) {
  if (position < 0 || position >= list->size) {
    printf("Invalid position!\n");
    return;
  }
  node_t *current_node = list->head;
  if (position == 0) {
    list->head = list->head->next;
  } else {
    for (int i = 0; i < position - 1; i++) {
      current_node = current_node->next;
    }
    node_t *temp = current_node->next;
    current_node->next = temp->next;
    free(temp);
  }
  list->size--;
  if (position == list->size) {
    list->tail = current_node;
  }
}

// Print the linked list
void print_linked_list(linked_list_t *list) {
  node_t *current_node = list->head;
  while (current_node != NULL) {
    printf("%d -> ", current_node->data);
    current_node = current_node->next;
  }
  printf("NULL\n");
}

// Free the linked list
void free_linked_list(linked_list_t *list) {
  node_t *current_node = list->head;
  while (current_node != NULL) {
    node_t *temp = current_node->next;
    free(current_node);
    current_node = temp;
  }
  free(list);
}

int main() {
  linked_list_t *list = create_linked_list();

  // Insert some nodes into the linked list
  insert_at_beginning(list, 1);
  insert_at_end(list, 2);
  insert_at_position(list, 3, 1);
  insert_at_position(list, 4, list->size);

  // Print the linked list
  print_linked_list(list);

  // Delete some nodes from the linked list
  delete_first_node(list);
  delete_at_position(list, 1);
  delete_last_node(list);

  // Print the linked list again
  print_linked_list(list);

  // Free the linked list
  free_linked_list(list);

  return 0;
}