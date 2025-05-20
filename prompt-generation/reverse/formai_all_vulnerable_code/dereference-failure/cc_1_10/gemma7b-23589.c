//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_ Nodes 1000

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* insert(Node* node, int data)
{
  if (node == NULL)
  {
    node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  }
  else if (data < node->data)
  {
    node->left = insert(node->left, data);
  }
  else
  {
    node->right = insert(node->right, data);
  }

  return node;
}

void traverse(Node* node)
{
  if (node)
  {
    traverse(node->left);
    printf("%d ", node->data);
    traverse(node->right);
  }
}

int main()
{
  Node* root = NULL;

  insert(root, 20);
  insert(root, 10);
  insert(root, 30);
  insert(root, 25);
  insert(root, 15);

  traverse(root);

  return 0;
}