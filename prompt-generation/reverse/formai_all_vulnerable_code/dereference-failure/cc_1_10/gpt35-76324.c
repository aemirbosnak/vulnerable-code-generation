//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int key;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNode(int key) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void inorderTraversal(Node* node) {
  if (node == NULL) return;
  inorderTraversal(node->left);
  printf("%d ", node->key);
  inorderTraversal(node->right);
}

void display(Node* root, int level) {
  if (root == NULL) return;
  display(root->right, level + 1);
  printf("\n");
  for (int i = 0; i < level; i++) {
    printf("    ");
  }
  printf("%d", root->key);
  display(root->left, level + 1);
}

int main() {
  Node* root = createNode(10);
  root->left = createNode(5);
  root->right = createNode(15);
  root->left->left = createNode(2);
  root->left->right = createNode(6);
  root->right->left = createNode(12);
  root->right->right = createNode(20);
  
  printf("Binary Tree Visualization:\n");
  printf("--------------------------\n");
  display(root, 0);
  
  printf("\n\nInorder Traversal: ");
  inorderTraversal(root);
  
  return 0;
}