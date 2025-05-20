//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// The main function
int main() {

  // Array of characters
  char arr[5] = {'H', 'e', 'l', 'l', 'o'};

  // Linked list of integers
  struct node {
    int data;
    struct node *next;
  };

  struct node *head = NULL;
  struct node *second = NULL;
  struct node *third = NULL;

  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  // Binary tree of characters
  struct node_bt {
    char data;
    struct node_bt *left;
    struct node_bt *right;
  };

  struct node_bt *root = NULL;
  struct node_bt *left = NULL;
  struct node_bt *right = NULL;

  root = (struct node_bt *)malloc(sizeof(struct node_bt));
  left = (struct node_bt *)malloc(sizeof(struct node_bt));
  right = (struct node_bt *)malloc(sizeof(struct node_bt));

  root->data = 'A';
  root->left = left;
  root->right = right;

  left->data = 'B';
  left->left = NULL;
  left->right = NULL;

  right->data = 'C';
  right->left = NULL;
  right->right = NULL;

  // Graph of integers
  struct node_g {
    int data;
    struct node_g *next;
  };

  struct node_g *n1 = NULL;
  struct node_g *n2 = NULL;
  struct node_g *n3 = NULL;

  n1 = (struct node_g *)malloc(sizeof(struct node_g));
  n2 = (struct node_g *)malloc(sizeof(struct node_g));
  n3 = (struct node_g *)malloc(sizeof(struct node_g));

  n1->data = 1;
  n1->next = n2;

  n2->data = 2;
  n2->next = n3;

  n3->data = 3;
  n3->next = NULL;

  // Print the data structures

  // Array
  printf("Array: ");
  for (int i = 0; i < 5; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");

  // Linked list
  printf("Linked list: ");
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");

  // Binary tree
  printf("Binary tree: ");
  printf("%c ", root->data);
  printf("%c ", root->left->data);
  printf("%c ", root->right->data);
  printf("\n");

  // Graph
  printf("Graph: ");
  struct node_g *current_g = n1;
  while (current_g != NULL) {
    printf("%d ", current_g->data);
    current_g = current_g->next;
  }
  printf("\n");

  return 0;
}