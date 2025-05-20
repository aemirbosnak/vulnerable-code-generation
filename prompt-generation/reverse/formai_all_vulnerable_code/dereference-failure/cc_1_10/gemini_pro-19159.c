//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: complex
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

node *insert_node(node *root, int data) {
  if (root == NULL) {
    return create_node(data);
  } else if (data < root->data) {
    root->left = insert_node(root->left, data);
  } else {
    root->right = insert_node(root->right, data);
  }
  return root;
}

node *search_node(node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return search_node(root->left, data);
  } else {
    return search_node(root->right, data);
  }
}

void print_inorder(node *root) {
  if (root == NULL) {
    return;
  }
  print_inorder(root->left);
  printf("%d ", root->data);
  print_inorder(root->right);
}

void print_preorder(node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  print_preorder(root->left);
  print_preorder(root->right);
}

void print_postorder(node *root) {
  if (root == NULL) {
    return;
  }
  print_postorder(root->left);
  print_postorder(root->right);
  printf("%d ", root->data);
}

int main() {
  node *root = NULL;
  int data[] = {10, 5, 15, 2, 7, 12, 20};
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    root = insert_node(root, data[i]);
  }
  printf("Inorder traversal: ");
  print_inorder(root);
  printf("\n");
  printf("Preorder traversal: ");
  print_preorder(root);
  printf("\n");
  printf("Postorder traversal: ");
  print_postorder(root);
  printf("\n");
  node *found_node = search_node(root, 15);
  if (found_node == NULL) {
    printf("Node not found!\n");
  } else {
    printf("Node found: %d\n", found_node->data);
  }
  return 0;
}