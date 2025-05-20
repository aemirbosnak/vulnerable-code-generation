//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *left;
  struct node *right;
} node;

node *create_node(int val) {
  node *n = malloc(sizeof(node));
  n->val = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void insert(node **root, int val) {
  if (*root == NULL) {
    *root = create_node(val);
    return;
  }
  if (val < (*root)->val) {
    insert(&(*root)->left, val);
  } else {
    insert(&(*root)->right, val);
  }
}

void print_tree(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->val);
  print_tree(root->left);
  print_tree(root->right);
}

void search(node *root, int val) {
  if (root == NULL) {
    printf("Not found\n");
    return;
  }
  if (root->val == val) {
    printf("Found\n");
    return;
  }
  if (val < root->val) {
    search(root->left, val);
  } else {
    search(root->right, val);
  }
}

int main() {
  node *root = NULL;
  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 20);
  insert(&root, 40);
  insert(&root, 70);
  insert(&root, 60);
  insert(&root, 80);
  print_tree(root);
  printf("\n");
  search(root, 40);
  search(root, 100);
  return 0;
}