//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

struct node *insert_node(struct node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

int search_node(struct node *root, int data) {
  if (root == NULL) {
    return 0;
  } else if (root->data == data) {
    return 1;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

void inorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ", root->data);
  inorder_traversal(root->right);
}

void preorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(struct node *root) {
  if (root == NULL) {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->data);
}

int main() {
  struct node *root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 70);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 60);
  root = insert_node(root, 80);

  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  printf("Preorder traversal: ");
  preorder_traversal(root);
  printf("\n");

  printf("Postorder traversal: ");
  postorder_traversal(root);
  printf("\n");

  int data = 40;
  if (search_node(root, data)) {
    printf("%d found in the binary tree.\n", data);
  } else {
    printf("%d not found in the binary tree.\n", data);
  }

  return 0;
}