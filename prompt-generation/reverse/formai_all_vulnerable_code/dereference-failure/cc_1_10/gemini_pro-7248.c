//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

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
  } else if (data <= (*root)->data) {
    insert_node(&(*root)->left, data);
  } else {
    insert_node(&(*root)->right, data);
  }
}

void preorder(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  node *root = NULL;
  int data[] = {10, 5, 15, 3, 7, 12, 17};
  for (int i = 0; i < 7; i++) {
    insert_node(&root, data[i]);
  }

  printf("Preorder traversal: ");
  preorder(root);
  printf("\n");

  printf("Inorder traversal: ");
  inorder(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder(root);
  printf("\n");

  return 0;
}