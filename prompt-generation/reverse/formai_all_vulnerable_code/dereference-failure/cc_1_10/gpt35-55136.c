//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

struct Node {
  int key;
  struct Node* left;
  struct Node* right;
};

struct Node* createNode(int key) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct Node* insert(struct Node* node, int key) {
  if (node == NULL) return createNode(key);

  if (key < node->key)
    node->left = insert(node->left, key);
  else if (key > node->key)
    node->right = insert(node->right, key);

  return node;
}

void inorder(struct Node* node) {
  if (node == NULL) return;
  inorder(node->left);
  printf("%d ", node->key);
  inorder(node->right);
}

bool search(struct Node* node, int key) {
  if (node == NULL) return false;

  if (node->key == key) return true;

  if (key < node->key)
    return search(node->left, key);
  else
    return search(node->right, key);
}

int main() {
  struct Node* root = NULL;

  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  inorder(root);
  printf("\n");
  
  int searchKey = 60;
  printf("%d is%s in the tree\n", searchKey, search(root, searchKey) ? "" : " not");

  return 0;
}