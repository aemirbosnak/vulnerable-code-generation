//FormAI DATASET v1.0 Category: Binary search trees ; Style: shape shifting
#include <stdio.h> 
#include <stdlib.h> 

// Define a structure for BST node
typedef struct node 
{ 
  int key; 
  struct node *left, *right; 
} Node;

// Function to create a new node 
Node* createNode(int key) 
{ 
  Node* newNode = (Node*)malloc(sizeof(Node)); 
  newNode->key = key; 
  newNode->left = newNode->right = NULL; 
  return newNode; 
} 

// Function to insert a new node 
Node* insert(Node* root, int key) 
{ 
  if (root == NULL) return createNode(key); 

  if (key < root->key) 
    root->left = insert(root->left, key); 
  else if (key > root->key) 
    root->right = insert(root->right, key); 

  // return the (unchanged) node pointer 
  return root; 
} 

// Function to search for a node with a given key 
Node* search(Node* root, int key) 
{ 
  if (root == NULL || root->key == key) 
     return root; 
   
  if (root->key < key) 
     return search(root->right, key); 

  return search(root->left, key); 
} 

// Function to delete a node with a given key 
Node* delete(Node* root, int key) 
{ 
  if (root == NULL) return root; 

  if (key < root->key) 
    root->left = delete(root->left, key); 
  else if (key > root->key) 
    root->right = delete(root->right, key); 

  else
  { 
    if (root->left == NULL) 
    { 
      Node *temp = root->right; 
      free(root); 
      return temp; 
    } 
    else if (root->right == NULL) 
    { 
      Node *temp = root->left; 
      free(root); 
      return temp; 
    } 

    Node* temp = root->right; 
    while (temp->left != NULL) 
      temp = temp->left; 

    root->key = temp->key;  
    root->right = delete(root->right, temp->key); 
  } 
  return root; 
} 

// Function to print the inorder traversal of the BST
void inorder(Node* root) 
{ 
  if (root != NULL) 
  { 
    inorder(root->left); 
    printf("%d \n", root->key); 
    inorder(root->right); 
  } 
} 

int main() 
{ 
  Node* root = NULL; 

  // insert nodes
  root = insert(root, 50); 
  insert(root, 30); 
  insert(root, 20); 
  insert(root, 40); 
  insert(root, 70); 
  insert(root, 60); 
  insert(root, 80); 

  // print the inorder traversal
  printf("Inorder traversal of the BST:\n"); 
  inorder(root); 

  // search for a node 
  Node* node1 = search(root, 50);
  printf("Searched key: %d\n", node1->key); 

  // delete a node 
  root = delete(root, 20); 
  printf("\nInorder traversal after deleting 20:\n"); 
  inorder(root); 

  return 0; 
}