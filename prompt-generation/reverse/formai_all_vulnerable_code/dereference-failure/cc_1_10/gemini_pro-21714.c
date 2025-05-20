//GEMINI-pro DATASET v1.0 Category: Recursive ; Style: Donald Knuth
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *create_node(int data) {
  node *new_node = malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data <= (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  print_tree(root->left);
  printf("%d ", root->data);
  print_tree(root->right);
}

void free_tree(node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  node *root = NULL;
  insert_node(&root, 10);
  insert_node(&root, 5);
  insert_node(&root, 15);
  insert_node(&root, 3);
  insert_node(&root, 7);
  insert_node(&root, 12);
  insert_node(&root, 17);

  print_tree(root);
  printf("\n");

  free_tree(root);

  return 0;
}