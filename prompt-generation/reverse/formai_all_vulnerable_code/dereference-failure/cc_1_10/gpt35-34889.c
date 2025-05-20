//FormAI DATASET v1.0 Category: Binary search trees ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
   struct node *left, *right; 
};

struct node* create_node(int value) {
  struct node* temp_node = (struct node*) malloc(sizeof(struct node));
  temp_node->data = value;
  temp_node->left = temp_node->right = NULL;
  return temp_node;
}

void insert_node(struct node* root, int value) {
  if (root == NULL) {
    printf("Binary search tree does not exist!\n");
    return;
  }
  if (root->data > value) {
    if (root->left != NULL) {
      insert_node(root->left, value);
    } else {
      root->left = create_node(value);
    }
  } else if (root->data < value) {
    if (root->right != NULL) {
      insert_node(root->right, value);
    } else {
      root->right = create_node(value);
    }
  }
}

void inorder_traversal(struct node* root) {
  if (root != NULL) {
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

struct node* find_minimum_value(struct node* node) {
  struct node* current = node;
  while (current && current->left != NULL) {
    current = current->left;
  }
  return current;
}

struct node* remove_node(struct node* root, int value) {
  if (root == NULL) {
    printf("Binary search tree does not exist!\n");
    return root;
  }
  if (root->data > value) {
    root->left = remove_node(root->left, value);
  } else if (root->data < value) {
    root->right = remove_node(root->right, value);
  } else {
    if (root->left == NULL) {
      struct node* temp_node = root->right;
      free(root);
      return temp_node;
    } else if (root->right == NULL) {
      struct node* temp_node = root->left;
      free(root);
      return temp_node;
    }
    struct node* temp_node = find_minimum_value(root->right);
    root->data = temp_node->data;
    root->right = remove_node(root->right, temp_node->data);
  }
  return root;
}

int main() {
  struct node* root_node = create_node(50);
  insert_node(root_node, 30);
  insert_node(root_node, 20);
  insert_node(root_node, 40);
  insert_node(root_node, 70);
  insert_node(root_node, 60);
  insert_node(root_node, 80);
  printf("Inorder traversal of binary search tree: ");
  inorder_traversal(root_node);
  printf("\n");
  printf("Removing 20 from binary search tree\n");
  root_node = remove_node(root_node, 20);
  printf("Inorder traversal of binary search tree: ");
  inorder_traversal(root_node);
  printf("\n");
  printf("Removing 30 from binary search tree\n");
  root_node = remove_node(root_node, 30);
  printf("Inorder traversal of binary search tree: ");
  inorder_traversal(root_node);
  printf("\n");
  return 0;
}