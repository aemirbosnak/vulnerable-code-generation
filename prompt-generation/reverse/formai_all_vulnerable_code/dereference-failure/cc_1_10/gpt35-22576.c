//FormAI DATASET v1.0 Category: Binary search trees ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

struct node *createNode(int val) {
   struct node *newNode = malloc(sizeof(struct node));
   newNode->data = val;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

void insert(struct node **root, int val) {
   if (*root == NULL) {
      *root = createNode(val);
      return;
   }
   if (*root != NULL && val <= (*root)->data) {
      insert(&(*root)->left, val);
   }
   else if (*root != NULL && val > (*root)->data) {
      insert(&(*root)->right, val);
   }
}

void inorder(struct node *root) {
   if (root == NULL) {
      return;
   }
   inorder(root->left);
   printf("%d ", root->data);
   inorder(root->right);
}

int search(struct node *root, int val) {
   if (root == NULL) {
      return 0;
   }
   else if (root->data == val) {
      return 1;
   }
   else if (val <= root->data) {
      return search(root->left, val);
   }
   else {
      return search(root->right, val);
   }
}

int main() {
   struct node *root = NULL;
   insert(&root, 10);
   insert(&root, 6);
   insert(&root, 14);
   insert(&root, 5);
   insert(&root, 8);
   insert(&root, 11);
   insert(&root, 18);
   printf("Inorder Traversal: ");
   inorder(root);
   int searchValue = 11;
   int isPresent = search(root, searchValue);
   if (isPresent) {
      printf("\n%d is present in the Binary Search Tree", searchValue);
   }
   else {
      printf("\n%d is not present in the Binary Search Tree", searchValue);
   }
   return 0;
}