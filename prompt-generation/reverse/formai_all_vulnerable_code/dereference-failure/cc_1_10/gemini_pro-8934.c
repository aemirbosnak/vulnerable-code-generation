//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct node {
  int data;
  struct node *next;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_node(node_t **head, int data) {
  node_t *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
  } else {
    new_node->next = *head;
    *head = new_node;
  }
}

void print_list(node_t *head) {
  if (head == NULL) {
    printf("List is empty.\n");
  } else {
    node_t *current = head;
    while (current != NULL) {
      printf("%d ", current->data);
      current = current->next;
    }
    printf("\n");
  }
}

void free_list(node_t *head) {
  if (head == NULL) {
    return;
  } else {
    free_list(head->next);
    free(head);
  }
}

int main() {
  node_t *head = NULL;

  // Insert some data into the list.
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 5);

  // Print the list.
  printf("List: ");
  print_list(head);

  // Free the list.
  free_list(head);
  return 0;
}