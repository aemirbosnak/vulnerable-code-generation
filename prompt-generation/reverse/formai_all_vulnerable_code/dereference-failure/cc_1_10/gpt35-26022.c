//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// define the structure for a binary tree node
typedef struct node {
  int value;
  struct node* left;
  struct node* right;
} node;

// create a new node with the given value
node* new_node(int value) {
  node* n = (node*) malloc(sizeof(node));
  n->value = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

// insert a new node with the given value into the tree starting at the given node
void insert_node(node* root, int value) {
  // if the tree is empty, create the root node
  if (root == NULL) {
    root = new_node(value);
  } else if (value < root->value) { // if the value is less than the current node's value, insert into the left subtree
    if (root->left == NULL) {
      root->left = new_node(value);
    } else {
      insert_node(root->left, value);
    }
  } else { // if the value is greater than or equal to the current node's value, insert into the right subtree
    if (root->right == NULL) {
      root->right = new_node(value);
    } else {
      insert_node(root->right, value);
    }
  }
}

// recursive function to print out the nodes of the tree in order
void print_in_order(node* root) {
  if (root == NULL) {
    return;
  }
  
  print_in_order(root->left);
  printf("%d ", root->value);
  print_in_order(root->right);
}

// recursive function to print out the nodes of the tree in pre-order
void print_pre_order(node* root) {
  if (root == NULL) {
    return;
  }
  
  printf("%d ", root->value);
  print_pre_order(root->left);
  print_pre_order(root->right);
}

// recursive function to print out the nodes of the tree in post-order
void print_post_order(node* root) {
  if (root == NULL) {
    return;
  }
  
  print_post_order(root->left);
  print_post_order(root->right);
  printf("%d ", root->value);
}

// recursive function to print out the ASCII visualization of the binary tree
void print_tree(node* root, int level) {
  if (root == NULL) {
    return;
  }
  
  print_tree(root->right, level + 1);
  
  // print the node with proper spacing
  for (int i = 0; i < level; i++) {
    printf("   ");
  }
  printf("%d\n", root->value);
  
  print_tree(root->left, level + 1);
}

int main() {
  // create a new binary tree with the root node containing the value 5
  node* root = new_node(5);
  
  // insert some values into the tree
  insert_node(root, 2);
  insert_node(root, 7);
  insert_node(root, 6);
  insert_node(root, 3);
  
  // print out the nodes of the tree in order
  printf("In-Order: ");
  print_in_order(root);
  
  // print out the nodes of the tree in pre-order
  printf("\nPre-Order: ");
  print_pre_order(root);
  
  // print out the nodes of the tree in post-order
  printf("\nPost-Order: ");
  print_post_order(root);
  
  // print out the ASCII visualization of the binary tree
  printf("\nTree Visualization:\n");
  print_tree(root, 0);
  
  return 0;
}