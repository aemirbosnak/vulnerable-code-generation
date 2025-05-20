//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node;

node *create_node(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(node **root, int data) {
  if (*root == NULL) {
    *root = create_node(data);
  } else if (data < (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
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
  srand(time(NULL));

  node *root = NULL;

  for (int i = 0; i < 100; i++) {
    int data = rand() % 100;
    insert_node(&root, data);
  }

  print_tree(root);

  free_tree(root);

  return 0;
}