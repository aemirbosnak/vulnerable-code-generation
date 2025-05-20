//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;
struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* create_node(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    return create_node(data);
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else if (data > root->data) {
    root->right = insert(root->right, data);
  }
  return root;
}

void inorder(Node* root) {
  if (root == NULL) {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int search(Node* root, int data) {
  if (root == NULL) {
    return 0;
  }
  if (data == root->data) {
    return 1;
  }
  if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void free_tree(Node* root) {
  if (root == NULL) {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main() {
  Node* root = NULL;
  int data[] = {50, 30, 20, 40, 70, 60, 80};
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    root = insert(root, data[i]);
  }
  inorder(root);
  printf("\n");
  printf("%d\n", search(root, 40));
  printf("%d\n", search(root, 100));
  free_tree(root);
  return 0;
}