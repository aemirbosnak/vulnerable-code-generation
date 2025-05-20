//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
   int value;
   struct TreeNode *left;
   struct TreeNode *right;
} TreeNode;

void insert(TreeNode **root, int value) {
   if (*root == NULL) {
      *root = (TreeNode *) malloc(sizeof(TreeNode));
      (*root)->value = value;
      (*root)->left = NULL;
      (*root)->right = NULL;
      return;
   }
   if (value < (*root)->value) {
      insert(&((*root)->left), value);
   }
   else {
      insert(&((*root)->right), value);
   }
}

void inorder_traversal(TreeNode *root) {
   if (root == NULL) {
      return;
   }
   inorder_traversal(root->left);
   printf("%d ", root->value);
   inorder_traversal(root->right);
}

TreeNode *search(TreeNode *root, int value) {
   if (root == NULL || root->value == value) {
      return root;
   }
   if (value < root->value) {
      return search(root->left, value);
   }
   else {
      return search(root->right, value);
   }
}

int main() {
   TreeNode *root = NULL;
   insert(&root, 8);
   insert(&root, 3);
   insert(&root, 10);
   insert(&root, 1);
   insert(&root, 6);
   insert(&root, 14);
   insert(&root, 4);
   insert(&root, 7);
   insert(&root, 13);
   printf("Inorder traversal: ");
   inorder_traversal(root);
   printf("\n");
   TreeNode *found_node = search(root, 4);
   if (found_node != NULL) {
      printf("Found node: %d\n", found_node->value);
   }
   else {
      printf("Node not found.\n");
   }
   return 0;
}