//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  struct node *next;
};

struct list {
  struct node *head;
  struct node *tail;
  int size;
};

struct list *create_list() {
  struct list *list = (struct list *)malloc(sizeof(struct list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void insert_node(struct list *list, int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  if (list->head == NULL) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }
  list->size++;
}

void delete_node(struct list *list, int data) {
  struct node *current = list->head;
  struct node *previous = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        list->head = current->next;
      } else {
        previous->next = current->next;
      }
      if (current == list->tail) {
        list->tail = previous;
      }
      free(current);
      list->size--;
      return;
    }
    previous = current;
    current = current->next;
  }
}

void print_list(struct list *list) {
  struct node *current = list->head;
  printf("[");
  while (current != NULL) {
    printf("%d, ", current->data);
    current = current->next;
  }
  printf("]\n");
}

void destroy_list(struct list *list) {
  struct node *current = list->head;
  struct node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int main() {
  struct list *list = create_list();
  insert_node(list, 1);
  insert_node(list, 2);
  insert_node(list, 3);
  insert_node(list, 4);
  insert_node(list, 5);
  print_list(list);
  delete_node(list, 3);
  print_list(list);
  destroy_list(list);
  return 0;
}