//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* Insert(struct Node* node, int data) {
  if (node == NULL) {
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  } else if (data < node->data) {
    node->left = Insert(node->left, data);
  } else {
    node->right = Insert(node->right, data);
  }

  return node;
}

int Search(struct Node* node, int data) {
  if (node == NULL) {
    return 0;
  } else if (node->data == data) {
    return 1;
  } else if (data < node->data) {
    return Search(node->left, data);
  } else {
    return Search(node->right, data);
  }
}

int main() {
  struct Node* root = NULL;
  root = Insert(root, 5);
  Insert(root, 3);
  Insert(root, 7);
  Insert(root, 2);
  Insert(root, 4);
  Insert(root, 6);

  if (Search(root, 3) == 1) {
    printf("Data found!\n");
  } else {
    printf("Data not found.\n");
  }

  return 0;
}