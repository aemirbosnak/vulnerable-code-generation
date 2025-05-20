//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#define HEIGHT 100

typedef struct Node {
 int data;
 int height;
 struct Node *left, *right;
} Node;

Node* createNode(int data) {
 Node* newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->height = 0;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}

int height(Node* node) {
 if (node == NULL)
 return -1;
 return node->height;
}

Node* rightRotate(Node* y) {
 Node* x = y->left;
 Node* T2 = x->right;

 x->right = y;
 y->left = T2;

 y->height = 1 + MAX(height(y->left), height(y->right));
 x->height = 1 + MAX(height(x->left), height(x->right));

 return x;
}

Node* leftRotate(Node* x) {
 Node* y = x->right;
 Node* T2 = y->left;

 y->left = x;
 x->right = T2;

 x->height = 1 + MAX(height(x->left), height(x->right));
 y->height = 1 + MAX(height(y->left), height(y->right));

 return y;
}

Node* insert(Node* node, int data) {
 if (node == NULL)
 return createNode(data);

 if (data < node->data)
 node->left = insert(node->left, data);
 else if (data > node->data)
 node->right = insert(node->right, data);

 node->height = 1 + MAX(height(node->left), height(node->right));

 if (height(node->left) - height(node->right) > 1) {
 if (height(node->left->left) >= height(node->left->right))
 node = rightRotate(node);
 else {
 Node* y = node->left;
 node->left = y->right;
 y->right = node;
 node = y;
 node = rightRotate(node);
 }
 }

 return node;
}

int MAX(int a, int b) {
 return (a > b) ? a : b;
}

void printTree(Node* node, int space) {
 if (node == NULL)
 return;

 printTree(node->right, space + 5);

 for (int i = 0; i < space; i++)
 putchar(' ');

 printf("%d\n", node->data);

 printTree(node->left, space + 5);
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

 printTree(root, 0);

 return 0;
}