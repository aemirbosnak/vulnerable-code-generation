//Gemma-7B DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* insert(struct node* node, int data)
{
  if (node == NULL)
  {
    node = (struct node*)malloc(sizeof(struct node));
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

void preorder(struct node* node)
{
  if (node)
  {
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
  }
}

int main()
{
  struct node* root = NULL;
  insert(root, 20);
  insert(root, 10);
  insert(root, 30);
  insert(root, 25);
  insert(root, 40);

  preorder(root);

  return 0;
}