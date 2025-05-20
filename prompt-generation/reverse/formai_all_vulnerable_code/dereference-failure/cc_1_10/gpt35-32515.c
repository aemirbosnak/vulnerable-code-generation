//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

// structure of a node
struct node {
   int data;
   struct node *left;
   struct node *right;
};

// function to create a new node
struct node* createNode(int data) {
   struct node* newNode = malloc(sizeof(struct node));
   newNode->data = data;
   newNode->left = NULL;
   newNode->right = NULL;
   return newNode;
}

// function to insert a node in the tree
struct node* insert(struct node* root, int data) {
   if(root == NULL) {
      return createNode(data);
   }
   if(data < root->data) {
      root->left = insert(root->left, data);
   } else if(data > root->data) {
      root->right = insert(root->right, data);
   }
   return root;
}

// function to search for a node in the tree
struct node* search(struct node* root, int data) {
   if(root == NULL || root->data == data) {
      return root;
   }
   if(data < root->data) {
      return search(root->left, data);
   }
   return search(root->right, data);
}

// function to find the minimum value node in the tree
struct node* minValueNode(struct node* node) {
   struct node* current = node;
   // loop down to find the leftmost leaf
   while(current && current->left != NULL) {
      current = current->left;
   }
   return current;
}

// function to delete a node from the tree
struct node* deleteNode(struct node* root, int data) {
   if(root == NULL) {
      return root;
   }
   if(data < root->data) {
      root->left = deleteNode(root->left, data);
   } else if(data > root->data) {
      root->right = deleteNode(root->right, data);
   } else {
      // node with only one child or no child
      if(root->left == NULL) {
         struct node* temp = root->right;
         free(root);
         return temp;
      } else if(root->right == NULL) {
         struct node* temp = root->left;
         free(root);
         return temp;
      }
      // node with two children
      struct node* temp = minValueNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
   }
   return root;
}

// function to traverse the tree in inorder
void inorder(struct node* root) {
   if(root != NULL) {
      inorder(root->left);
      printf("%d ", root->data);
      inorder(root->right);
   }
}

// main function
int main() {
   struct node* root = NULL;
   // inserting nodes in the tree
   root = insert(root, 10);
   root = insert(root, 5);
   root = insert(root, 20);
   root = insert(root, 3);
   root = insert(root, 7);
   root = insert(root, 15);
   root = insert(root, 25);
   // displaying the tree
   printf("Inorder traversal of the binary search tree: ");
   inorder(root);
   // searching for a node in the tree
   int key = 5;
   if(search(root, key) != NULL) {
      printf("\n%d is present in the binary search tree", key);
   } else {
      printf("\n%d is not present in the binary search tree", key);
   }
   // deleting a node from the tree
   root = deleteNode(root, 5);
   // displaying the updated tree
   printf("\nInorder traversal of the updated binary search tree: ");
   inorder(root);
   return 0;
}