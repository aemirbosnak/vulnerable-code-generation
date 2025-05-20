//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void print_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void insert_at_beginning(node **head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = *head;
  *head = new_node;
}

void insert_at_end(node **head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (*head == NULL) {
    *head = new_node;
    return;
  }

  node *last_node = *head;
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
}

void insert_at_index(node **head, int data, int index) {
  if (index == 0) {
    insert_at_beginning(head, data);
    return;
  }

  node *new_node = malloc(sizeof(node));
  new_node->data = data;

  node *current_node = *head;
  for (int i = 0; i < index - 1; i++) {
    current_node = current_node->next;
  }
  new_node->next = current_node->next;
  current_node->next = new_node;
}

void delete_at_beginning(node **head) {
  if (*head == NULL) {
    return;
  }

  node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void delete_at_end(node **head) {
  if (*head == NULL) {
    return;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  node *current_node = *head;
  while (current_node->next->next != NULL) {
    current_node = current_node->next;
  }
  free(current_node->next);
  current_node->next = NULL;
}

void delete_at_index(node **head, int index) {
  if (index == 0) {
    delete_at_beginning(head);
    return;
  }

  node *current_node = *head;
  for (int i = 0; i < index - 1; i++) {
    current_node = current_node->next;
  }
  node *temp = current_node->next;
  current_node->next = current_node->next->next;
  free(temp);
}

int main() {
  node *head = NULL;

  insert_at_end(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);
  insert_at_end(&head, 4);
  insert_at_end(&head, 5);

  print_list(head);

  insert_at_beginning(&head, 0);
  print_list(head);

  insert_at_index(&head, 2.5, 3);
  print_list(head);

  delete_at_beginning(&head);
  print_list(head);

  delete_at_end(&head);
  print_list(head);

  delete_at_index(&head, 2);
  print_list(head);

  return 0;
}