//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = malloc(sizeof(node_t));
  if (new_node == NULL) {
    printf("Error: malloc failed\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_at_head(node_t **head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

void insert_at_tail(node_t **head, int data) {
  if (*head == NULL) {
    *head = create_node(data);
    return;
  }
  insert_at_tail(&(*head)->next, data);
}

void print_list(node_t *head) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }
  printf("%d ", head->data);
  print_list(head->next);
}

void free_list(node_t *head) {
  if (head == NULL) {
    return;
  }
  free_list(head->next);
  free(head);
}

int main() {
  node_t *head = NULL;
  insert_at_head(&head, 1);
  insert_at_tail(&head, 2);
  insert_at_tail(&head, 3);
  insert_at_tail(&head, 4);
  insert_at_tail(&head, 5);
  print_list(head);
  printf("\n");
  free_list(head);
  return 0;
}