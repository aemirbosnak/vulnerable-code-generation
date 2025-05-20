//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int steps;
  int calories;
  int distance;
  struct node *next;
} node;

void print_list(node *head) {
  if (head == NULL) {
    return;
  }

  printf("Steps: %d\n", head->steps);
  printf("Calories: %d\n", head->calories);
  printf("Distance: %d\n", head->distance);

  print_list(head->next);
}

void free_list(node *head) {
  if (head == NULL) {
    return;
  }

  free_list(head->next);
  free(head);
}

node *insert_at_head(node *head, int steps, int calories, int distance) {
  node *new_node = malloc(sizeof(node));
  new_node->steps = steps;
  new_node->calories = calories;
  new_node->distance = distance;
  new_node->next = head;

  return new_node;
}

int main() {
  node *head = NULL;

  head = insert_at_head(head, 10000, 500, 5);
  head = insert_at_head(head, 8000, 400, 4);
  head = insert_at_head(head, 6000, 300, 3);
  head = insert_at_head(head, 4000, 200, 2);
  head = insert_at_head(head, 2000, 100, 1);

  print_list(head);

  free_list(head);

  return 0;
}