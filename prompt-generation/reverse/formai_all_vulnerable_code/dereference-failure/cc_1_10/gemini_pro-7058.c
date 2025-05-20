//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

void insert_node(struct node *root, int data) {
  if (root == NULL) {
    root = create_node(data);
  } else if (data < root->data) {
    insert_node(root->left, data);
  } else {
    insert_node(root->right, data);
  }
}

void print_tree(struct node *root, int level) {
  if (root == NULL) {
    return;
  }

  for (int i = 0; i < level; i++) {
    printf("  ");
  }

  printf("%d\n", root->data);

  print_tree(root->left, level + 1);
  print_tree(root->right, level + 1);
}

int main() {
  struct node *root = NULL;

  insert_node(root, 10);
  insert_node(root, 5);
  insert_node(root, 15);
  insert_node(root, 2);
  insert_node(root, 7);
  insert_node(root, 12);
  insert_node(root, 20);

  print_tree(root, 0);

  return 0;
}