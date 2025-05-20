//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} node;

node *create_node(int value) {
  node *new_node = malloc(sizeof(node));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}

void insert_node(node **head, int value) {
  node *new_node = create_node(value);
  new_node->next = *head;
  *head = new_node;
}

void print_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // Create an empty list
  node *head = NULL;

  // Insert some values into the list
  insert_node(&head, 1);
  insert_node(&head, 2);
  insert_node(&head, 3);
  insert_node(&head, 4);

  // Print the list
  print_list(head);

  // Free the list
  while (head != NULL) {
    node *next = head->next;
    free(head);
    head = next;
  }

  return 0;
}