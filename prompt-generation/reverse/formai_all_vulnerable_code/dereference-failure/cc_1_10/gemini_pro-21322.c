//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: interoperable
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

struct node *search_node(struct node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

void inorder_traversal(struct node *root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

int main() {
  struct node *root = NULL;
  root = insert_node(root, 50);
  root = insert_node(root, 30);
  root = insert_node(root, 20);
  root = insert_node(root, 40);
  root = insert_node(root, 70);
  root = insert_node(root, 60);
  root = insert_node(root, 80);

  printf("Inorder traversal: ");
  inorder_traversal(root);
  printf("\n");

  struct node *found_node = search_node(root, 40);
  if (found_node != NULL) {
    printf("Found node with data %d\n", found_node->data);
  } else {
    printf("Node not found\n");
  }

  return 0;
}