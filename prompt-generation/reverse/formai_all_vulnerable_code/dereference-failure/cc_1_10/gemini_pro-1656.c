//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/* A node in the linked list */
typedef struct node {
  int data;
  struct node *next;
} node;

/* Insert a new node at the beginning of the list */
node *insert_at_beginning(node *head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = head;
  return new_node;
}

/* Insert a new node at the end of the list */
node *insert_at_end(node *head, int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    return new_node;
  } else {
    node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    return head;
  }
}

/* Insert a new node after a given node */
node *insert_after(node *head, node *prev_node, int data) {
  if (prev_node == NULL) {
    return head;
  }

  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
  return head;
}

/* Delete a node from the list */
node *delete_node(node *head, node *node_to_delete) {
  if (head == NULL || node_to_delete == NULL) {
    return head;
  }

  if (head == node_to_delete) {
    head = head->next;
    free(node_to_delete);
    return head;
  }

  node *current = head;
  while (current->next != node_to_delete) {
    current = current->next;
  }

  current->next = node_to_delete->next;
  free(node_to_delete);
  return head;
}

/* Print the list */
void print_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  /* Create an empty list */
  node *head = NULL;

  /* Insert some nodes */
  head = insert_at_beginning(head, 10);
  head = insert_at_end(head, 20);
  head = insert_after(head, head, 30);

  /* Print the list */
  print_list(head);

  /* Delete a node */
  head = delete_node(head, head->next);

  /* Print the list */
  print_list(head);

  return 0;
}