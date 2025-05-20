//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Ada Lovelace
#include <stdlib.h>
#include <stdio.h>

/* Node structure */
typedef struct Node {
  int data;
  struct Node *next;
} Node;

/* Linked list structure */
typedef struct LinkedList {
  Node *head;
  Node *tail;
  int size;
} LinkedList;

/* Create a new linked list */
LinkedList *create_list() {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

/* Insert a new node at the beginning of the list */
void insert_at_beginning(LinkedList *list, int data) {
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

/* Insert a new node at the end of the list */
void insert_at_end(LinkedList *list, int data) {
  Node *new_node = malloc(sizeof(Node));
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

/* Insert a new node at a given position in the list */
void insert_at_position(LinkedList *list, int data, int position) {
  if (position < 0 || position > list->size) {
    printf("Invalid position\n");
    return;
  }
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  if (position == 0) {
    insert_at_beginning(list, data);
    return;
  }
  Node *current_node = list->head;
  for (int i = 0; i < position - 1; i++) {
    current_node = current_node->next;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
  if (position == list->size) {
    list->tail = new_node;
  }
  list->size++;
}

/* Delete a node from the beginning of the list */
void delete_from_beginning(LinkedList *list) {
  if (list->head == NULL) {
    return;
  }
  Node *temp = list->head;
  list->head = list->head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(temp);
  list->size--;
}

/* Delete a node from the end of the list */
void delete_from_end(LinkedList *list) {
  if (list->head == NULL) {
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

/* Delete a node from a given position in the list */
void delete_from_position(LinkedList *list, int position) {
  if (position < 0 || position >= list->size) {
    printf("Invalid position\n");
    return;
  }
  Node *current_node = list->head;
  Node *previous_node = NULL;
  for (int i = 0; i < position; i++) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    list->head = list->head->next;
    if (list->head == NULL) {
      list->tail = NULL;
    }
  } else {
    previous_node->next = current_node->next;
    if (current_node == list->tail) {
      list->tail = previous_node;
    }
  }
  free(current_node);
  list->size--;
}

/* Print the list */
void print_list(LinkedList *list) {
  Node *current_node = list->head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

/* Free the list */
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
  insert_at_beginning(list, 1);
  insert_at_end(list, 2);
  insert_at_position(list, 3, 1);
  print_list(list);  // 1 3 2
  delete_from_beginning(list);
  delete_from_end(list);
  delete_from_position(list, 0);
  print_list(list);  // empty list
  free_list(list);
  return 0;
}