//FormAI DATASET v1.0 Category: Binary search trees ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* left;
   struct Node* right;
};

struct Node* createNode(int data) {
   struct Node* node = (struct Node*) malloc(sizeof(struct Node));
   node->data = data;
   node->left = NULL;
   node->right = NULL;
   return(node);
}

struct Node* insert(struct Node* node, int data) {
   if (node == NULL) return(createNode(data));
   if (data < node->data)
      node->left = insert(node->left, data);
   else if (data > node->data)
      node->right = insert(node->right, data);
   return(node);
}

struct Node* search(struct Node* node, int data) {
   if (node == NULL) return(NULL);
   else if (data < node->data)
      return(search(node->left, data));
   else if (data > node->data)
      return(search(node->right, data));
   else return(node);
}

void inorder(struct Node* node) {
   if (node != NULL) {
      inorder(node->left);
      printf("%d ", node->data);
      inorder(node->right);
   }
}

int main() {
   struct Node* root = NULL;
   root = insert(root, 10);
   insert(root, 20);
   insert(root, 30);
   insert(root, 40);
   insert(root, 50);
   printf("Inorder traversal of BST : ");
   inorder(root);
   struct Node* temp = search(root, 30);
   printf("\nSearched node=%d",temp->data);
   return 0;
}