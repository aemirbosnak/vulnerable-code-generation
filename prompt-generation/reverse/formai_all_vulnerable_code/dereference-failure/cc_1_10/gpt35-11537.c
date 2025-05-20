//FormAI DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

Node* newNode(int data)
{
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

Node* insert(Node* node, int data)
{
  if(node == NULL)
    return(newNode(data));
  else {
    if (data <= node->data)
      node->left = insert(node->left, data);
    else
      node->right = insert(node->right, data);

    return(node);
  }
}

void inorder(Node* node)
{
  if(node == NULL)
    return;

  inorder(node->left);
  printf("%d ", node->data);
  inorder(node->right);
}

Node* search(Node* node, int data)
{
  if(node == NULL || node->data == data)
    return node;

  if(data < node->data)
    return search(node->left, data);

  return search(node->right, data);
}

int main()
{
  Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("Inorder traversal of BST: ");
  inorder(root);

  int searchKey = 40;
  Node* result = search(root, searchKey);

  if(result == NULL)
    printf("\n%d not found in the tree\n", searchKey);
  else
    printf("\n%d found in the tree\n", searchKey);

  searchKey = 65;
  result = search(root, searchKey);

  if(result == NULL)
    printf("%d not found in the tree\n", searchKey);
  else
    printf("%d found in the tree\n", searchKey);

  return 0;
}