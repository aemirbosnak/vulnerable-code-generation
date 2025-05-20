//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void print_list(node *head) {
  while (head != NULL) {
    printf("%d -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}

void insert_at_head(node **head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_tail(node **head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (*head == NULL) {
    *head = new_node;
  } else {
    node *current_node = *head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

void delete_at_head(node **head) {
  if (*head == NULL) {
    return;
  }
  node *current_node = *head;
  *head = (*head)->next;
  free(current_node);
}

void delete_at_tail(node **head) {
  if (*head == NULL) {
    return;
  }
  node *current_node = *head;
  node *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    *head = NULL;
  } else {
    previous_node->next = NULL;
  }
  free(current_node);
}

int main() {
  node *head = NULL;

  insert_at_head(&head, 1);
  insert_at_tail(&head, 2);
  insert_at_head(&head, 3);
  insert_at_tail(&head, 4);

  print_list(head);

  delete_at_head(&head);
  delete_at_tail(&head);

  print_list(head);

  return 0;
}