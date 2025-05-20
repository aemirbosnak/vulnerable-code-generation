//FormAI DATASET v1.0 Category: Binary search trees ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct Node {
   int key;
   struct Node *left, *right;
};

struct Node* createNode(int item) {
   struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->key = item;
   newNode->left = newNode->right = NULL;
   return newNode;
}

void inorderTraversal(struct Node* root) {
   if(root != NULL) {
      inorderTraversal(root->left);
      printf("%d ", root->key);
      inorderTraversal(root->right);
   }
}

struct Node* insert(struct Node* node, int key) {
   if(node == NULL) return createNode(key);
   if(key < node->key) 
      node->left = insert(node->left, key);
   else if(key > node->key)
      node->right = insert(node->right, key);
   return node;
}

struct Node* minValueNode(struct Node* node) {
   struct Node* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

struct Node* deleteNode(struct Node* root, int key) {
   if (root == NULL) return root;
   if (key < root->key) root->left = deleteNode(root->left, key);
   else if (key > root->key) root->right = deleteNode(root->right, key);
   else {
      if (root->left == NULL) {
         struct Node* temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL) {
         struct Node* temp = root->left;
         free(root);
         return temp;
      }

      struct Node* temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
   }
   return root;
}

int main() {
   struct Node* root = NULL;

   root = insert(root, 40);
   root = insert(root, 20);
   root = insert(root, 60);
   root = insert(root, 10);
   root = insert(root, 30);

   printf("Inorder traversal: ");
   inorderTraversal(root);

   printf("\nDeleting 20\n");
   root = deleteNode(root, 20);
   printf("Inorder traversal: ");
   inorderTraversal(root);

   printf("\nDeleting 40\n");
   root = deleteNode(root, 40);
   printf("Inorder traversal: ");
   inorderTraversal(root);

   printf("\nDeleting 10\n");
   root = deleteNode(root, 10);
   printf("Inorder traversal: ");
   inorderTraversal(root);

   return 0;
}