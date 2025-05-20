//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {  // structure that defines the node
   int data;           // data of the node
   struct node* left;  // left pointer of the node
   struct node* right; // right pointer of the node
} node;

node* get_new_node(int data) {     // function to create a new node
   node* newnode = malloc(sizeof(node));  // allocate memory for the new node
   newnode->data = data;           // set the data of the new node
   newnode->left = NULL;           // initialize the left pointer to null
   newnode->right = NULL;          // initialize the right pointer to null
   return newnode;                 // return the address of the new node
}

node* insert(node* root, int data) {  // function to insert a node in the Binary Search Tree
   if(!root) return get_new_node(data); // if there is no root node create the new node and make it root.
   if(data <= root->data)        // if data of the node is less than or equal to the root
      root->left = insert(root->left, data);   // insert the node in the left subtree
   else                          // if data of the node is greater than the root
      root->right = insert(root->right, data); // insert the node in the right subtree
   return root;                  // return the root node
}

node* search(node* root, int data) {   // function to search if an element is present in the BST
   if(!root) return NULL;         // if root is null return null, element not found.
   if(root->data == data) return root; // if data of the root is equal to the data we want to search return the root
   else if(data <= root->data) return search(root->left, data); // if data is less than or equal to the root, search in the left subtree.
   else return search(root->right, data);  // else search in the right subtree
}

node* find_min(node* root) {   // find the minimum element in a BST 
   while(root->left) {
      root = root->left;
   }
   return root;
}

node* delete(node* root, int data) { // function to delete a node from BST
   if(!root) return NULL;       // return null if root is null.
   else if(data < root->data)   // if data is less than the root.data, set the left subtree to the new root after deleting the element
      root->left = delete(root->left, data);
   else if(data > root->data)   // if data is greater than the root.data, set the right subtree to the new root after deleting the element.
      root->right = delete(root->right, data);

   else {  // if root->data == data, element found
      // case 1: No child
      if(root->left == NULL && root->right == NULL) {
         free(root);            
         root = NULL;
      }
      // case 2: one child
      else if(root->left == NULL) {
         node* temp = root;
         root = root->right;
         free(temp);
      }
      else if(root->right == NULL) {
         node* temp = root;
         root = root->left;
         free(temp);
      }
      // case 3: two children
      else { 
         node* temp = find_min(root->right);  // find the min element in the right subtree and replace its data with root's data
         root->data = temp->data;
         root->right = delete(root->right,temp->data); // delete the min node from the right subtree
      }
   }
   return root;  // return the address of the new root
}

void inorder(node* root) {  // function to traverse the BST in inorder traversal
   if(!root) return;
   inorder(root->left);     // traverse the left subtree
   printf("%d ", root->data); // print the node data
   inorder(root->right);   // traverse the right subtree
}

int main() {
   node* root = NULL;                   // initialize the root pointer to null
   root = insert(root, 15);             // insert elements in the BST
   root = insert(root, 10);
   root = insert(root, 20);
   root = insert(root, 25);
   root = insert(root, 8);
   root = insert(root, 12);
   printf("Inorder Traversal: ");
   inorder(root);                       // traverse the BST in inorder
   printf("\n");
   node* temp = search(root, 25);       // searching an element in the BST
   if(temp) printf("Element Found\n");
   else printf("Element Not Found\n");  
   root = delete(root, 15);             // delete a node from the BST
   printf("Inorder Traversal After Deleting Element: ");
   inorder(root);                       // traverse the BST in inorder after deleting the element
   printf("\n");

   return 0;
}