//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A simple linked list node
struct node {
  int data;
  struct node *next;
};

// A simple linked list
struct list {
  struct node *head;
  struct node *tail;
  int size;
};

// Create a new linked list
struct list *create_list() {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Insert a new node at the end of the linked list
void insert_node(struct list *list, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
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
void print_list(struct list *list) {
  struct node *current_node = list->head;

  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

// Free the linked list
void free_list(struct list *list) {
  struct node *current_node = list->head;

  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }

  free(list);
}

int main() {
  // Create a new linked list
  struct list *list = create_list();

  // Insert some nodes into the linked list
  insert_node(list, 1);
  insert_node(list, 2);
  insert_node(list, 3);
  insert_node(list, 4);
  insert_node(list, 5);

  // Print the linked list
  printf("The linked list is: ");
  print_list(list);

  // Free the linked list
  free_list(list);

  return 0;
}