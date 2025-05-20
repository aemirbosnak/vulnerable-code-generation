//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 50

typedef struct percolator_node {
  struct percolator_node* up;
  struct percolator_node* left;
  struct percolator_node* right;
  int state;
} percolator_node;

void percolator_init(percolator_node** head) {
  *head = malloc(sizeof(percolator_node));
  (*head)->up = NULL;
  (*head)->left = NULL;
  (*head)->right = NULL;
  (*head)->state = 0;
}

void percolator_add(percolator_node** head, int x, int y) {
  percolator_node* newNode = malloc(sizeof(percolator_node));
  newNode->up = *head;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->state = 0;
  *head = newNode;
  (*head)->up = NULL;
  (*head)->left = NULL;
  (*head)->right = NULL;
  (*head)->state = 0;
}

void percolator_percolate(percolator_node* node) {
  if (node->state == 1) {
    return;
  }
  node->state = 1;
  if (node->left) {
    percolator_percolate(node->left);
  }
  if (node->right) {
    percolator_percolate(node->right);
  }
}

int main() {
  percolator_node* head = NULL;
  percolator_init(&head);
  percolator_add(&head, 0, 0);
  percolator_add(&head, 1, 0);
  percolator_add(&head, 2, 0);
  percolator_add(&head, 3, 0);
  percolator_add(&head, 4, 0);
  percolator_add(&head, 5, 0);
  percolator_add(&head, 0, 1);
  percolator_add(&head, 1, 1);
  percolator_add(&head, 2, 1);
  percolator_add(&head, 3, 1);
  percolator_add(&head, 4, 1);
  percolator_add(&head, 5, 1);

  srand(time(NULL));
  percolator_percolate(head);

  return 0;
}