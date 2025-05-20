//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: authentic
#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Linked list structure
typedef struct LinkedList {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

// Create a new linked list
LinkedList *create_list() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(LinkedList *list, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(LinkedList *list, int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
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
void insert_at_position(LinkedList *list, int data, int position) {
  if (position == 0) {
    insert_at_beginning(list, data);
    return;
  }
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  Node *current_node = list->head;
  int current_position = 0;
  while (current_node != NULL && current_position < position - 1) {
    current_node = current_node->next;
    current_position++;
  }
  if (current_node == NULL) {
    printf("Invalid position\n");
    return;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
  if (position == list->size) {
    list->tail = new_node;
  }
  list->size++;
}

// Delete a node at the beginning of the linked list
void delete_at_beginning(LinkedList *list) {
  if (list->head == NULL) {
    printf("Linked list is empty\n");
    return;
  }
  Node *node_to_delete = list->head;
  list->head = list->head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(node_to_delete);
  list->size--;
}

// Delete a node at the end of the linked list
void delete_at_end(LinkedList *list) {
  if (list->tail == NULL) {
    printf("Linked list is empty\n");
    return;
  }
  Node *current_node = list->head;
  Node *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    previous_node->next = NULL;
    list->tail = previous_node;
  }
  free(current_node);
  list->size--;
}

// Delete a node at a specific position in the linked list
void delete_at_position(LinkedList *list, int position) {
  if (position == 0) {
    delete_at_beginning(list);
    return;
  }
  Node *current_node = list->head;
  Node *previous_node = NULL;
  int current_position = 0;
  while (current_node != NULL && current_position < position) {
    previous_node = current_node;
    current_node = current_node->next;
    current_position++;
  }
  if (current_node == NULL) {
    printf("Invalid position\n");
    return;
  }
  if (previous_node == NULL) {
    list->head = current_node->next;
  } else {
    previous_node->next = current_node->next;
  }
  if (current_node == list->tail) {
    list->tail = previous_node;
  }
  free(current_node);
  list->size--;
}

// Print the linked list
void print_list(LinkedList *list) {
  Node *current_node = list->head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Get the size of the linked list
int get_size(LinkedList *list) {
  return list->size;
}

// Check if the linked list is empty
int is_empty(LinkedList *list) {
  return list->size == 0;
}

// Free the linked list
void free_list(LinkedList *list) {
  Node *current_node = list->head;
  while (current_node != NULL) {
    Node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(list);
}

int main() {
  LinkedList *list = create_list();

  insert_at_beginning(list, 10);
  insert_at_beginning(list, 20);
  insert_at_beginning(list, 30);
  insert_at_end(list, 40);
  insert_at_end(list, 50);
  insert_at_position(list, 60, 3);

  print_list(list);

  delete_at_beginning(list);
  delete_at_end(list);
  delete_at_position(list, 2);

  print_list(list);

  printf("Size of the linked list: %d\n", get_size(list));
  printf("Is the linked list empty? %d\n", is_empty(list));

  free_list(list);

  return 0;
}