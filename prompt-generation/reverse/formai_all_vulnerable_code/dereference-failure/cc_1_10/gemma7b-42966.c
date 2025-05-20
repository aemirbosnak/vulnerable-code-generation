//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_TREE_ Nodes 100

typedef struct Node {
  struct Node* left;
  struct Node* right;
  int data;
} Node;

struct Tree {
  Node* root;
  int size;
};

void insert(struct Tree* tree, int data) {
  if (tree == NULL) {
    tree = malloc(sizeof(struct Tree));
    tree->root = malloc(sizeof(Node));
    tree->root->data = data;
    tree->root->left = NULL;
    tree->root->right = NULL;
    tree->size = 1;
  } else if (data < tree->root->data) {
    insert(tree->root->left, data);
  } else {
    insert(tree->root->right, data);
  }
  tree->size++;
}

void preorder(struct Tree* tree) {
  if (tree) {
    printf("%d ", tree->root->data);
    preorder(tree->root->left);
    preorder(tree->root->right);
  }
}

int main() {
  struct Tree* tree = NULL;
  insert(tree, 20);
  insert(tree, 10);
  insert(tree, 30);
  insert(tree, 40);
  insert(tree, 50);
  insert(tree, 60);

  preorder(tree);

  return 0;
}