//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char *data;
  struct node *next;
} node_t;

typedef struct list {
  node_t *head;
  node_t *tail;
  int size;
} list_t;

list_t *create_list() {
  list_t *list = malloc(sizeof(list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void destroy_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current->data);
    free(current);
    current = next;
  }
  free(list);
}

void add_to_list(list_t *list, char *data) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->data = strdup(data);
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

void print_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    printf("%s ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  // Create a new list
  list_t *list = create_list();

  // Add some data to the list
  add_to_list(list, "Hello");
  add_to_list(list, "World");
  add_to_list(list, "!");

  // Print the list
  print_list(list);

  // Destroy the list
  destroy_list(list);

  return 0;
}