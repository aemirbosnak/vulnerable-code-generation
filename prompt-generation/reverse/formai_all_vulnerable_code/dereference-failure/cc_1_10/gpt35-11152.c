//FormAI DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
   int data;
   struct BSTNode* left;
   struct BSTNode* right;
} BSTNode;

BSTNode* createNode(int data) {
   BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

BSTNode* insert(BSTNode* root, int data) {
   if(root == NULL) {
      root = createNode(data);
      return root;
   }

   if(data < root->data)
      root->left = insert(root->left, data);
   else if(data > root->data)
      root->right = insert(root->right, data);

   return root;
}

void printTree(BSTNode* root) {
   if(root != NULL) {
      printf("%d ", root->data);
      printTree(root->left);
      printTree(root->right);
   }
}

void paranoidDelete(BSTNode** rootRef) {
   if(*rootRef == NULL)
      return;

   BSTNode* left = (*rootRef)->left;
   BSTNode* right = (*rootRef)->right;
   
   paranoidDelete(&left);
   paranoidDelete(&right);

   free(*rootRef);
   *rootRef = NULL;
}

int main() {
   BSTNode* root = NULL;

   root = insert(root, 6);
   root = insert(root, 2);
   root = insert(root, 8);
   root = insert(root, 1);
   root = insert(root, 3);
   root = insert(root, 7);
   root = insert(root, 9);

   printf("Original Tree: ");
   printTree(root);

   printf("\nRemoving all nodes from memory in a paranoid style...\n");
   paranoidDelete(&root);

   printf("After Paranoid Deletion: ");
   printTree(root);

   return 0;
}