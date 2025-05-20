//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
  char *value;
  struct node *next;
} node_t;

typedef struct list {
  node_t *head;
  node_t *tail;
} list_t;

list_t *create_list() {
  list_t *list = malloc(sizeof(list_t));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void destroy_list(list_t *list) {
  node_t *current = list->head;
  while (current != NULL) {
    node_t *next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

void add_to_list(list_t *list, char *value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = strdup(value);
  new_node->next = NULL;

  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
}

char *remove_from_list(list_t *list) {
  if (list->head == NULL) {
    return NULL;
  }

  char *value = list->head->value;
  node_t *next = list->head->next;
  free(list->head);
  list->head = next;

  if (list->head == NULL) {
    list->tail = NULL;
  }

  return value;
}

int main(int argc, char *argv[]) {
  list_t *list = create_list();

  add_to_list(list, "hello");
  add_to_list(list, "world");
  add_to_list(list, "!");

  char *value;
  while ((value = remove_from_list(list)) != NULL) {
    printf("%s", value);
    free(value);
  }

  destroy_list(list);

  return 0;
}