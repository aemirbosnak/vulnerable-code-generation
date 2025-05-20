//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>    
#include <stdlib.h>   

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node *createNode(int n) {
   struct node *newNode;
   newNode = (struct node*)malloc(sizeof(struct node));
   newNode->data = n;
   newNode->left = NULL;
   newNode->right = NULL;
   return(newNode);
}

struct node *insert(struct node *root, int data) {
   if(root == NULL) {
      root = createNode(data);
   }
   else if(data < root->data) {
      root->left = insert(root->left, data);
   }
   else {
      root->right = insert(root->right, data);
   }
   return(root);
}

struct node *findMin(struct node *root) {
   while(root->left != NULL) {
      root = root->left;
   }
   return(root);
}

struct node *delete(struct node *root, int data) {
   struct node *temp;
   if(root == NULL) {
      printf("Element not found\n");
   }
   else if(data < root->data) {
      root->left = delete(root->left, data);
   }
   else if(data > root->data) {
      root->right = delete(root->right, data);
   }
   else {
      if(root->left && root->right) {
         temp = findMin(root->right);
         root->data = temp->data;
         root->right = delete(root->right,temp->data);
      }
      else {
         temp = root;
         if(root->left == NULL) {
            root = root->right;
         }
         else if(root->right == NULL) {
            root = root->left;
         }
         free(temp);
      }
   }
   return(root);
}

void inorder(struct node *root) {
   if(root != NULL) {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
   }
}

int main() {
   struct node *root = NULL;
   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 30);
   root = insert(root, 40);
   root = insert(root, 50);
   root = insert(root, 25);
   printf("Binary search tree created and inserted with 10,20,30,40,50,25\n");
   printf("Inorder traversal is: ");
   inorder(root);
   printf("\n");
   root = delete(root, 10);
   printf("After deleting 10, inorder traversal is: ");
   inorder(root);
   printf("\n");
   root = delete(root, 30);
   printf("After deleting 30, inorder traversal is: ");
   inorder(root);
   printf("\n");
   root = delete(root, 50);
   printf("After deleting 50, inorder traversal is: ");
   inorder(root);
   printf("\n");
   return 0;
}