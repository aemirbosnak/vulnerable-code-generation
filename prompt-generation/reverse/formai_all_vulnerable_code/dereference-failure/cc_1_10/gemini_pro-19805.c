//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *insert_at_beginning(node *head, int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = head;
  return new_node;
}

node *insert_at_end(node *head, int data) {
  if (head == NULL) {
    return insert_at_beginning(head, data);
  }
  head->next = insert_at_end(head->next, data);
  return head;
}

node *insert_at_index(node *head, int data, int index) {
  if (index == 0) {
    return insert_at_beginning(head, data);
  }
  head->next = insert_at_index(head->next, data, index - 1);
  return head;
}

node *delete_at_beginning(node *head) {
  if (head == NULL) {
    return NULL;
  }
  node *new_head = head->next;
  free(head);
  return new_head;
}

node *delete_at_end(node *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  head->next = delete_at_end(head->next);
  return head;
}

node *delete_at_index(node *head, int index) {
  if (index == 0) {
    return delete_at_beginning(head);
  }
  head->next = delete_at_index(head->next, index - 1);
  return head;
}

void print_list(node *head) {
  if (head == NULL) {
    printf("[]\n");
    return;
  }
  printf("[%d", head->data);
  print_list(head->next);
}

int main() {
  node *head = NULL;
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_index(head, 3, 1);
  head = insert_at_beginning(head, 0);
  head = insert_at_end(head, 4);
  printf("Original list: ");
  print_list(head);
  head = delete_at_beginning(head);
  head = delete_at_end(head);
  head = delete_at_index(head, 1);
  printf("Modified list: ");
  print_list(head);
  return 0;
}