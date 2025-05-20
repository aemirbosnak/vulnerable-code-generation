//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Error: could not allocate memory for new node.\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_at_head(node **head, int data) {
  node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

void insert_at_tail(node **head, int data) {
  node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void insert_at_index(node **head, int data, int index) {
  if (index == 0) {
    insert_at_head(head, data);
    return;
  }
  node *new_node = create_node(data);
  node *current = *head;
  int i = 0;
  while (current->next != NULL && i < index - 1) {
    current = current->next;
    i++;
  }
  if (current->next == NULL && i < index - 1) {
    printf("Error: index out of bounds.\n");
    exit(1);
  }
  new_node->next = current->next;
  current->next = new_node;
}

void delete_at_head(node **head) {
  if (*head == NULL) {
    printf("Error: cannot delete from an empty list.\n");
    exit(1);
  }
  node *to_delete = *head;
  *head = (*head)->next;
  free(to_delete);
}

void delete_at_tail(node **head) {
  if (*head == NULL) {
    printf("Error: cannot delete from an empty list.\n");
    exit(1);
  }
  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }
  node *current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void delete_at_index(node **head, int index) {
  if (index == 0) {
    delete_at_head(head);
    return;
  }
  node *current = *head;
  int i = 0;
  while (current->next != NULL && i < index - 1) {
    current = current->next;
    i++;
  }
  if (current->next == NULL && i < index - 1) {
    printf("Error: index out of bounds.\n");
    exit(1);
  }
  node *to_delete = current->next;
  current->next = current->next->next;
  free(to_delete);
}

void print_list(node *head) {
  node *current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

int main() {
  node *head = NULL;
  insert_at_head(&head, 1);
  insert_at_tail(&head, 2);
  insert_at_index(&head, 3, 1);
  print_list(head); // 1 -> 3 -> 2 -> NULL
  delete_at_head(&head);
  print_list(head); // 3 -> 2 -> NULL
  delete_at_tail(&head);
  print_list(head); // 3 -> NULL
  delete_at_index(&head, 0);
  print_list(head); // NULL
  return 0;
}