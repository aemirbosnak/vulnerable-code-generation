//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  new_node->next = *head;
  *head = new_node;
}

void print_list(node_t *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void reverse_list(node_t **head) {
  if (*head == NULL || (*head)->next == NULL) {
    return;
  }
  node_t *next_node = (*head)->next;
  (*head)->next = NULL;
  reverse_list(&next_node);
  next_node->next = *head;
  *head = next_node;
}

void delete_list(node_t **head) {
  while (*head != NULL) {
    node_t *next_node = (*head)->next;
    free(*head);
    *head = next_node;
  }
}

int main() {
  node_t *head = NULL;
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);
  insert_node(&head, 5);
  print_list(head);
  reverse_list(&head);
  print_list(head);
  delete_list(&head);
  return 0;
}