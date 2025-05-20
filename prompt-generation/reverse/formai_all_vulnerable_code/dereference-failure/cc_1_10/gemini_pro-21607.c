//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
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
  } else {
    node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void insert_at_index(node **head, int index, int data) {
  if (index == 0) {
    insert_at_beginning(head, data);
  } else {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    node *current = *head;
    for (int i = 0; i < index - 1; i++) {
      current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
}

void delete_at_beginning(node **head) {
  if (*head == NULL) {
    return;
  }
  node *current = *head;
  *head = current->next;
  free(current);
}

void delete_at_end(node **head) {
  if (*head == NULL) {
    return;
  }
  node *current = *head;
  node *previous = NULL;
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

void delete_at_index(node **head, int index) {
  if (index == 0) {
    delete_at_beginning(head);
  } else {
    node *current = *head;
    node *previous = NULL;
    for (int i = 0; i < index; i++) {
      previous = current;
      current = current->next;
    }
    if (previous == NULL) {
      *head = current->next;
    } else {
      previous->next = current->next;
    }
    free(current);
  }
}

int main() {
  node *head = NULL;
  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_index(&head, 1, 3);
  print_list(head); // 1 3 2
  delete_at_beginning(&head);
  print_list(head); // 3 2
  delete_at_end(&head);
  print_list(head); // 3
  delete_at_index(&head, 0);
  print_list(head); // NULL
  return 0;
}