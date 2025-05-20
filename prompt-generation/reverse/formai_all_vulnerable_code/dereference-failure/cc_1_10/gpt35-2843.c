//FormAI DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int data) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}

Node* insert(Node* root, Node* new_node) {
  if (root == NULL) {
    return new_node;
  }
  if (new_node->data < root->data) {
    root->left = insert(root->left, new_node);
  } else {
    root->right = insert(root->right, new_node);
  }
  return root;
}

Node* search(Node* root, int key) {
  if (root == NULL || root->data == key) {
    return root;
  }
  if (root->data < key) {
    return search(root->right, key);
  }
  return search(root->left, key);
}

void inorder(Node* node) {
  if (node != NULL) {
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
  }
}

int main() {
  Node* root = NULL;
  int data[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  int n = sizeof(data) / sizeof(data[0]);

  for (int i = 0; i < n; i++) {
    root = insert(root, createNode(data[i]));
  }

  printf("Inorder traversal of the BST: ");
  inorder(root);

  int key = 6;
  if (search(root, key) != NULL) {
    printf("\n%d is present in the BST.\n", key);
  } else {
    printf("\n%d is not present in the BST.\n", key);
  }

  return 0;
}