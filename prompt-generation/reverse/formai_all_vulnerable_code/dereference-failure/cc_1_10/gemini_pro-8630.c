//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct node {
  int value;
  struct node *next;
} node_t;

typedef struct list {
  node_t *head;
  node_t *tail;
  int size;
} list_t;

list_t *create_list() {
  list_t *list = (list_t *)malloc(sizeof(list_t));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

void insert_node(list_t *list, int value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
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
  node_t *current_node = list->head;
  while (current_node != NULL) {
    printf("%d ", current_node->value);
    current_node = current_node->next;
  }
  printf("\n");
}

void free_list(list_t *list) {
  node_t *current_node = list->head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(list);
}

int main() {
  list_t *list = create_list();

  // Insert some values into the list
  insert_node(list, 1);
  insert_node(list, 2);
  insert_node(list, 3);
  insert_node(list, 4);
  insert_node(list, 5);

  // Print the list
  printf("The list is: ");
  print_list(list);

  // Search for a value in the list
  int search_value = 3;
  node_t *found_node = NULL;
  node_t *current_node = list->head;
  while (current_node != NULL) {
    if (current_node->value == search_value) {
      found_node = current_node;
      break;
    }
    current_node = current_node->next;
  }

  // Print the result
  if (found_node == NULL) {
    printf("The value %d was not found in the list.\n", search_value);
  } else {
    printf("The value %d was found at index %d in the list.\n", search_value, found_node->value);
  }

  // Free the list
  free_list(list);

  return 0;
}