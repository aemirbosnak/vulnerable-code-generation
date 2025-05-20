//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node *next;
} node;

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

void insert_at_position(node **head, int data, int position) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  if (position == 0) {
    new_node->next = *head;
    *head = new_node;
  } else {
    node *current = *head;
    int count = 0;
    while (current->next != NULL && count < position - 1) {
      current = current->next;
      count++;
    }
    if (count == position - 1) {
      new_node->next = current->next;
      current->next = new_node;
    } else {
      printf("Invalid position\n");
    }
  }
}

void delete_at_beginning(node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
  } else {
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
  }
}

void delete_at_end(node **head) {
  if (*head == NULL) {
    printf("List is empty\n");
  } else if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
  } else {
    node *current = *head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
  }
}

void delete_at_position(node **head, int position) {
  if (*head == NULL) {
    printf("List is empty\n");
  } else if (position == 0) {
    node *temp = *head;
    *head = (*head)->next;
    free(temp);
  } else {
    node *current = *head;
    int count = 0;
    while (current->next != NULL && count < position - 1) {
      current = current->next;
      count++;
    }
    if (count == position - 1) {
      node *temp = current->next;
      current->next = current->next->next;
      free(temp);
    } else {
      printf("Invalid position\n");
    }
  }
}

void print_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  node *head = NULL;
  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_position(&head, 3, 1);
  print_list(head);
  delete_at_beginning(&head);
  delete_at_end(&head);
  delete_at_position(&head, 0);
  print_list(head);
  return 0;
}