//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} node_t;

node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

node_t *insert_node(node_t *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

void inorder_traversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

void preorder_traversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(node_t *root) {
  if (root == NULL) {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);
}

int main() {
  node_t *root = NULL;
  root = insert_node(root, 10);
  root = insert_node(root, 5);
  root = insert_node(root, 15);
  root = insert_node(root, 2);
  root = insert_node(root, 7);
  root = insert_node(root, 12);
  root = insert_node(root, 20);
  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\nPreorder traversal: ");
  preorder_traversal(root);
  printf("\nPostorder traversal: ");
  postorder_traversal(root);
  printf("\n");
  return 0;
}