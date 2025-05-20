//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
  int data;
  struct _node *left;
  struct _node *right;
} node;

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  if (new_node == NULL) {
    fprintf(stderr, "Error: malloc() failed.\n");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
    return;
  }
  if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else if (data > (*root)->data) {
    insert_node(&(*root)->right, data);
  } else {
    fprintf(stderr, "Error: duplicate data value.\n");
    exit(EXIT_FAILURE);
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d\n", root->data);
  print_tree(root->left);
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
  int data[] = {10, 5, 15, 3, 7, 12, 17, 1, 4, 6, 8, 11, 13, 16, 18};
  int i;
  for (i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    insert_node(&root, data[i]);
  }
  print_tree(root);
  free_tree(root);
  return 0;
}