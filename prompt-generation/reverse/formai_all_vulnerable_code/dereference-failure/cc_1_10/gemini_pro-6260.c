//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc failed\n");
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
  node_t *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  node_t *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void insert_at_index(node_t **head, int index, int data) {
  if (index == 0) {
    insert_at_head(head, data);
    return;
  }
  node_t *new_node = create_node(data);
  node_t *current = *head;
  int i = 0;
  while (current != NULL && i < index - 1) {
    current = current->next;
    i++;
  }
  if (current == NULL) {
    fprintf(stderr, "Error: index out of range\n");
    exit(1);
  }
  new_node->next = current->next;
  current->next = new_node;
}

void delete_at_head(node_t **head) {
  if (*head == NULL) {
    fprintf(stderr, "Error: list is empty\n");
    exit(1);
  }
  node_t *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_tail(node_t **head) {
  if (*head == NULL) {
    fprintf(stderr, "Error: list is empty\n");
    exit(1);
  }
  node_t *current = *head;
  node_t *previous = NULL;
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  if (previous == NULL) {
    *head = NULL;
  } else {
    previous->next = NULL;
  }
  free(current);
}

void delete_at_index(node_t **head, int index) {
  if (*head == NULL) {
    fprintf(stderr, "Error: list is empty\n");
    exit(1);
  }
  if (index == 0) {
    delete_at_head(head);
    return;
  }
  node_t *current = *head;
  node_t *previous = NULL;
  int i = 0;
  while (current != NULL && i < index) {
    previous = current;
    current = current->next;
    i++;
  }
  if (current == NULL) {
    fprintf(stderr, "Error: index out of range\n");
    exit(1);
  }
  if (previous == NULL) {
    *head = (*head)->next;
  } else {
    previous->next = current->next;
  }
  free(current);
}

void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  node_t *head = NULL;

  insert_at_head(&head, 10);
  insert_at_tail(&head, 20);
  insert_at_index(&head, 1, 15);
  print_list(head);  // 10 15 20

  delete_at_head(&head);
  print_list(head);  // 15 20

  delete_at_tail(&head);
  print_list(head);  // 15

  delete_at_index(&head, 0);
  print_list(head);  //

  return 0;
}