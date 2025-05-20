//FormAI DATASET v1.0 Category: Binary search trees ; Style: genious
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *left;
   struct node *right;
};

typedef struct node *NodePtr;

NodePtr createNode(int value) {
   NodePtr node = (NodePtr)malloc(sizeof(struct node));
   node->data = value;
   node->left = NULL;
   node->right = NULL;
   return node;
}

NodePtr insert(NodePtr root, int value) {
   if(root == NULL) {
      root = createNode(value);
   } else if(value < root->data) {
      root->left = insert(root->left, value);
   } else {
      root->right = insert(root->right, value);
   }
   return root;
}

void inorder(NodePtr root) {
   if(root != NULL) {
      inorder(root->left);
      printf("%d -> ", root->data);
      inorder(root->right);
   }
}

int main() {
   NodePtr root = NULL;
   int choice = 1, value;
   printf("Enter the values to be inserted (Enter -1 to stop):\n");
   while(choice != -1) {
      scanf("%d", &value);
      if(value == -1) {
         choice = -1;
      } else {
         root = insert(root, value);
      }
   }
   printf("\nThe inorder traversal of the binary search tree is:\n");
   inorder(root);
   return 0;
}