//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

typedef struct Node Node;

Node* createNode(int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insert(Node* root, int data) {
  if (root == NULL) {
    root = createNode(data);
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

Node* search(Node* root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (root->data == data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

Node* findMinimum(Node* root) {
  if (root == NULL) {
    return NULL;
  } else if (root->left == NULL) {
    return root;
  } else {
    return findMinimum(root->left);
  }
}

Node* delete(Node* root, int data) {
  if (root == NULL) {
    return root;
  } else if (data < root->data) {
    root->left = delete(root->left, data);
  } else if (data > root->data) {
    root->right = delete(root->right, data);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    } else if (root->left == NULL) {
      Node* temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      Node* temp = root;
      root = root->left;
      free(temp);
    } else {
      Node* temp = findMinimum(root->right);
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

void printInorder(Node* root) {
  if (root == NULL) {
    return;
  }
  printInorder(root->left);
  printf("%d ", root->data);
  printInorder(root->right);
}

int main() {
  Node* root = NULL;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder traversal: ");
  printInorder(root);
  printf("\n");

  printf("Deleting 20\n");
  root = delete(root, 20);
  printf("Inorder traversal after deletion: ");
  printInorder(root);
  printf("\n");

  printf("Searching for 60: ");
  Node* temp = search(root, 60);
  if (temp == NULL) {
    printf("60 not found\n");
  } else {
    printf("60 found\n");
  }

  return 0;
}