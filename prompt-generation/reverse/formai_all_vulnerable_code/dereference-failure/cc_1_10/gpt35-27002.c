//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Struct definition for node
struct node {
  int key;
  struct node *left;
  struct node *right;
};

// Function to create a new node
struct node* newNode(int key) {
  struct node* temp =  (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;
  printf("\nNode with key %d created with a snap of my fingers!\n", key);
  return temp;
}

// Function to insert a node
struct node* insert(struct node* node, int key) {
  if (node == NULL) {
    printf("\nInserting node with key %d... Watch me go!\n", key);
    return newNode(key);
  }
  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  } else {
    printf("\nSorry kiddo, node with key %d already exists.\n", key);
  }
  return node;
}

// Function to print the nodes in tree
void inorderTraversal(struct node* node) {
  if (node != NULL) {
    inorderTraversal(node->left);
    printf("%d ", node->key);
    inorderTraversal(node->right);
  }
}

// Main function
int main() {
  struct node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  printf("\n\nBinary Search Tree constructed successfully!\n\n");

  printf("\nInorder traversal in progress... Please wait...\n\n");
  inorderTraversal(root);

  printf("\n\nThat's all folks!\n");

  return 0;
}