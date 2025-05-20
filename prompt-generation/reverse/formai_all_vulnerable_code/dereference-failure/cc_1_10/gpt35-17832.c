//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

struct node* search(struct node *root, int key) {
   if(root == NULL || root->data == key) {
      return root;
   }
   if(key < root->data) {
      return search(root->leftChild, key);
   }
   return search(root->rightChild, key);
}

struct node* newNode(int item) {
   struct node *temp = (struct node*)malloc(sizeof(struct node));
   temp->data = item;
   temp->leftChild = temp->rightChild = NULL;
   return temp;
}

void inorderTraversal(struct node *root) {
   if(root != NULL) {
      inorderTraversal(root->leftChild);
      printf("%d ", root->data);
      inorderTraversal(root->rightChild);
   }
}

struct node* insert(struct node* node, int data) {
   if(node == NULL) {
      return newNode(data);
   }
   if(data < node->data) {
      node->leftChild = insert(node->leftChild, data);
   } else if(data > node->data) {
      node->rightChild = insert(node->rightChild, data);
   }
   return node;
}

struct node *minValueNode(struct node *node) {
   struct node* current = node;
   while(current && current->leftChild != NULL) {
      current = current->leftChild;
   }
   return current;
}

struct node* delete(struct node* root, int data) {
   if(root == NULL) {
      return root;
   }
   if(data < root->data) {
      root->leftChild = delete(root->leftChild, data);
   } else if(data > root->data) {
      root->rightChild = delete(root->rightChild, data);
   } else {
      if(root->leftChild == NULL) {
         struct node *temp = root->rightChild;
         free(root);
         return temp;
      } else if(root->rightChild == NULL) {
         struct node *temp = root->leftChild;
         free(root);
         return temp;
      }
      struct node* temp = minValueNode(root->rightChild);
      root->data = temp->data;
      root->rightChild = delete(root->rightChild, temp->data);
   }
   return root;
}

int main() {
   struct node *root = NULL;
   root = insert(root, 30);
   root = insert(root, 15);
   root = insert(root, 50);
   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 40);
   root = insert(root, 60);
   printf("Inorder traversal is: ");
   inorderTraversal(root);
   root = delete(root, 20);
   printf("\nInorder traversal after deleting 20: ");
   inorderTraversal(root);
   return 0;
}