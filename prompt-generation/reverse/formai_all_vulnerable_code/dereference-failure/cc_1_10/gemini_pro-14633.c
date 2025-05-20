//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_at_beginning(struct node **head, int data) {
  struct node *new_node = create_node(data);
  new_node->next = *head;
  *head = new_node;
}

void insert_at_end(struct node **head, int data) {
  struct node *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
    return;
  }
  struct node *last_node = *head;
  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
}

void insert_after_node(struct node *prev_node, int data) {
  if (prev_node == NULL) {
    printf("Previous node cannot be NULL\n");
    return;
  }
  struct node *new_node = create_node(data);
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void delete_node(struct node **head, struct node *node_to_delete) {
  if (*head == node_to_delete) {
    *head = (*head)->next;
  } else {
    struct node *current_node = *head;
    while (current_node->next != node_to_delete) {
      current_node = current_node->next;
    }
    current_node->next = node_to_delete->next;
  }
  free(node_to_delete);
}

void print_list(struct node *head) {
  struct node *current_node = head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;

  insert_at_beginning(&head, 1);
  insert_at_end(&head, 2);
  insert_at_end(&head, 3);
  insert_after_node(head->next, 4);

  printf("Original list: ");
  print_list(head);

  delete_node(&head, head->next->next);

  printf("List after deletion: ");
  print_list(head);

  return 0;
}