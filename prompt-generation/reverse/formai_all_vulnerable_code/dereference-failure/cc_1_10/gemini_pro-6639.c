//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A tree node
struct node {
  struct node *left;
  struct node *right;
  int data;
};

// Create a new tree node
struct node *new_node(int data) {
  struct node *new = malloc(sizeof(struct node));
  new->left = new->right = NULL;
  new->data = data;
  return new;
}

// Insert a node into a tree
void insert(struct node **root, int data) {
  if (*root == NULL) {
    *root = new_node(data);
    return;
  }
  if (data < (*root)->data) {
    insert(&(*root)->left, data);
  } else {
    insert(&(*root)->right, data);
  }
}

// Print a tree in preorder
void preorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

// Print a tree in inorder
void inorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// Print a tree in postorder
void postorder(struct node *root) {
  if (root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->data);
}

// Free a tree
void free_tree(struct node *root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  struct node *root = NULL;
  insert(&root, 10);
  insert(&root, 5);
  insert(&root, 15);
  insert(&root, 2);
  insert(&root, 7);
  insert(&root, 12);
  insert(&root, 20);

  printf("Preorder: ");
  preorder(root);
  printf("\n");

  printf("Inorder: ");
  inorder(root);
  printf("\n");

  printf("Postorder: ");
  postorder(root);
  printf("\n");

  free_tree(root);

  return 0;
}