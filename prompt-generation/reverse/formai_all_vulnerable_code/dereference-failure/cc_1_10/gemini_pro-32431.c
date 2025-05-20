//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct linked_list {
  node *head;
  node *tail;
  int size;
} linked_list;

linked_list *create_linked_list() {
  linked_list *list = malloc(sizeof(linked_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void insert_node(linked_list *list, int data) {
  node *new_node = malloc(sizeof(node));
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

void print_linked_list(linked_list *list) {
  node *current = list->head;

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }

  printf("\n");
}

bool search_linked_list(linked_list *list, int data) {
  node *current = list->head;

  while (current != NULL) {
    if (current->data == data) {
      return true;
    }

    current = current->next;
  }

  return false;
}

void free_linked_list(linked_list *list) {
  node *current = list->head;

  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }

  free(list);
}

int main() {
  linked_list *list = create_linked_list();

  insert_node(list, 1);
  insert_node(list, 2);
  insert_node(list, 3);
  insert_node(list, 4);
  insert_node(list, 5);

  print_linked_list(list);

  bool found = search_linked_list(list, 3);

  if (found) {
    printf("Data found in the linked list.\n");
  } else {
    printf("Data not found in the linked list.\n");
  }

  free_linked_list(list);

  return 0;
}