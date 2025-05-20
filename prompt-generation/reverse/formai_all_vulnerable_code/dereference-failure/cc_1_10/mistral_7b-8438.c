//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEIGHT 100

typedef struct Node {
 int data;
 struct Node *left;
 struct Node *right;
} Node;

Node *createNode(int data) {
 Node *newNode = (Node *)malloc(sizeof(Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}

Node *insertNode(Node *root, int data) {
 if (root == NULL) {
 return createNode(data);
 }
 if (data < root->data) {
 root->left = insertNode(root->left, data);
 } else if (data > root->data) {
 root->right = insertNode(root->right, data);
 }
 return root;
}

Node *searchNode(Node *root, int data) {
 if (root == NULL) {
 return NULL;
 }
 if (data < root->data) {
 return searchNode(root->left, data);
 } else if (data > root->data) {
 return searchNode(root->right, data);
 } else {
 return root;
 }
}

void printInOrder(Node *root) {
 if (root == NULL) {
 return;
 }
 printInOrder(root->left);
 printf("%d ", root->data);
 printInOrder(root->right);
}

void printTree(Node *root, int level) {
 if (root == NULL) {
 printf("\n");
 return;
 }
 printTree(root->right, level + 1);
 if (level >= HEIGHT) {
 printf("%d ", root->data);
 }
 printTree(root->left, level + 1);
}

int main() {
 srand(time(NULL));
 Node *root = NULL;
 int data, i;
 printf("Creating a binary search tree with %d random numbers:\n", HEIGHT);
 for (i = 0; i < HEIGHT; i++) {
 data = rand() % 100 + 1;
 root = insertNode(root, data);
 }
 printf("\nIn-order traversal of the binary search tree:\n");
 printInOrder(root);
 printf("\nPrinting the tree upside-down:\n");
 printTree(root, 0);
 printf("\nSearching for a random number (23): %s\n", searchNode(root, 23) ? "Found!" : "Not found!");
 return 0;
}