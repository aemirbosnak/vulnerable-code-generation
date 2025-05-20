//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* insert(struct Node* node, int data) {
  if (node == NULL) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  } else if (data < node->data) {
    node->left = insert(node->left, data);
  } else {
    node->right = insert(node->right, data);
  }
  return node;
}

struct Node* search(struct Node* node, int data) {
  if (node == NULL) {
    return NULL;
  } else if (node->data == data) {
    return node;
  } else if (data < node->data) {
    return search(node->left, data);
  } else {
    return search(node->right, data);
  }
}

int main() {
  struct Node* root = NULL;
  insert(root, 10);
  insert(root, 5);
  insert(root, 15);
  insert(root, 2);
  insert(root, 7);
  insert(root, 12);

  struct Node* result = search(root, 5);
  if (result) {
    printf("Node found: %d\n", result->data);
  } else {
    printf("Node not found\n");
  }

  return 0;
}