//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left, *right;
} node;

node *insert(node *root, int data) {
  if (root == NULL) {
    root = (node *)malloc(sizeof(node));
    root->data = data;
    root->left = root->right = NULL;
  } else if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

node *search(node *root, int data) {
  if (root == NULL)
    return NULL;
  else if (data < root->data)
    return search(root->left, data);
  else if (data > root->data)
    return search(root->right, data);
  else
    return root;
}

void print_inorder(node *root) {
  if (root != NULL) {
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
  }
}

void print_preorder(node *root) {
  if (root != NULL) {
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
  }
}

void print_postorder(node *root) {
  if (root != NULL) {
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 20);

  printf("Inorder: ");
  print_inorder(root);
  printf("\n");

  printf("Preorder: ");
  print_preorder(root);
  printf("\n");

  printf("Postorder: ");
  print_postorder(root);
  printf("\n");

  node *found = search(root, 15);
  if (found != NULL)
    printf("Found 15\n");
  else
    printf("Not found 15\n");

  return 0;
}