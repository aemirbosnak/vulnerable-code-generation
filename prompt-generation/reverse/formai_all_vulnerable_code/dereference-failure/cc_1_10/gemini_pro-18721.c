//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char *name;
  int data;
  struct node *next;
};

struct list {
  struct node *head;
  struct node *tail;
  int size;
};

struct list *create_list() {
  struct list *list = malloc(sizeof(struct list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void add_to_list(struct list *list, char *name, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->name = strdup(name);
  new_node->data = data;
  new_node->next = NULL;
  if (list->size == 0) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

void print_list(struct list *list) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    printf("%s: %d\n", current_node->name, current_node->data);
    current_node = current_node->next;
  }
}

void free_list(struct list *list) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node->name);
    free(current_node);
    current_node = next_node;
  }
  free(list);
}

int main() {
  struct list *list = create_list();

  add_to_list(list, "The Beatles", 10);
  add_to_list(list, "The Rolling Stones", 9);
  add_to_list(list, "Led Zeppelin", 8);
  add_to_list(list, "Pink Floyd", 7);
  add_to_list(list, "The Who", 6);

  print_list(list);

  free_list(list);

  return 0;
}