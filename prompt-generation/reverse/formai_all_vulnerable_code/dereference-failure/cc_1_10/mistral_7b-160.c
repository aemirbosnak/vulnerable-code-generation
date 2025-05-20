//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INITIAL_SIZE 10
typedef struct Node {
 int data;
 struct Node* left;
 struct Node* right;
} Node;
Node* createNode(int data) {
 Node* newNode = (Node*) malloc(sizeof(Node));
 newNode->data = data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
Node* insertNode(Node* root, int data) {
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
void inorderTraversal(Node* root) {
 if (root == NULL) {
 return;
 }
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
}
int main(void) {
 srand(time(NULL));
 Node* root = NULL;
 int i, size = INITIAL_SIZE;
 for (i = 0; i < size; i++) {
 root = insertNode(root, rand() % 50 + 1);
 }
 inorderTraversal(root);
 printf("\nSearch for number 35:\n");
 Node* searchNode = root;
 while (searchNode != NULL) {
 if (searchNode->data == 35) {
 printf("Found!\n");
 break;
 } else if (searchNode->data < 35) {
 searchNode = searchNode->right;
 } else {
 searchNode = searchNode->left;
 }
 }
 if (searchNode == NULL) {
 printf("Not found.\n");
 }
 return 0;
}