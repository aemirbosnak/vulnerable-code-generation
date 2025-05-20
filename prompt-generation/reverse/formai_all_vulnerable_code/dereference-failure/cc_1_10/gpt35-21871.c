//FormAI DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct node {
  int data;
  struct node *left, *right;
} Node;

Node* newNode(int data) {
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(Node* root) {
  if (root == NULL) return;

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void insert(Node* *root, int data) {
  if (*root == NULL) {
    *root = newNode(data);
    return;
  }

  if (data < (*root)->data)
    insert(&((*root)->left), data);
  else if (data > (*root)->data)
    insert(&((*root)->right), data);
}

Node* minValueNode(Node* node) {
  Node* current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

Node* delete(Node* root, int data) {
  if (root == NULL) return root;

  if (data < root->data)
    root->left = delete(root->left, data);
  else if (data > root->data)
    root->right = delete(root->right, data);
  else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node* temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = delete(root->right, temp->data);
  }

  return root;
}

void print2DUtil(Node *root, int space) {
  if (root == NULL) return;

  space += COUNT;

  print2DUtil(root->right, space);

  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->data);

  print2DUtil(root->left, space);
}

void print2D(Node *root) {
  print2DUtil(root, 0);
}

int main() {
  Node *root = NULL;
  int values[] = {12, 5, 18, 2, 9, 15, 19, 13, 17};

  for (int i = 0; i < 9; i++)
    insert(&root, values[i]);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\n\nBinary search tree:\n");
  print2D(root);

  root = delete(root, 12);
  printf("\n\nAfter deleting 12:\n");
  print2D(root);

  return 0;
}