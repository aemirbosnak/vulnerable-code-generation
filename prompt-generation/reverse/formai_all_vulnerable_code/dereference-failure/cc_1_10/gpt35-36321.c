//FormAI DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} Node;

Node* createNode(int data) {
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node* insert(Node* node, int data) {
  if(node == NULL) {
    return createNode(data);
  }

  if(data < node->data) {
    node->left = insert(node->left, data);
  }
  else {
    node->right = insert(node->right, data);
  }

  return node;
}

Node* search(Node* node, int data) {
  if(node == NULL || node->data == data) {
    return node;
  }

  if(data < node->data) {
    return search(node->left, data);
  }
  else {
    return search(node->right, data);
  }
}

void inorderTraversal(Node* node) {
  if(node != NULL) {
    inorderTraversal(node->left);
    printf("%d ", node->data);
    inorderTraversal(node->right);
  }
}

int main() {
  Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  Node* result = search(root, 40);
  if(result == NULL) {
    printf("40 not found\n");
  }
  else {
    printf("40 found\n");
  }

  result = search(root, 90);
  if(result == NULL) {
    printf("90 not found\n");
  }
  else {
    printf("90 found\n");
  }

  return 0;
}