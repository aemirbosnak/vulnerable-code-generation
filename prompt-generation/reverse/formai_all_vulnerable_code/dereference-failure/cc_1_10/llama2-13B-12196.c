//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define the struct for our binary search tree
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Function to create a new node
struct node* new_node(int data) {
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Function to insert a value into the tree
void insert(struct node** root, int data) {
  if (*root == NULL) {
    *root = new_node(data);
  } else {
    struct node* current = *root;
    while (current != NULL) {
      if (data < current->data) {
        if (current->left == NULL) {
          current->left = new_node(data);
        } else {
          insert(current->left, data);
        }
        break;
      } else if (data > current->data) {
        if (current->right == NULL) {
          current->right = new_node(data);
        } else {
          insert(current->right, data);
        }
        break;
      }
      current = current->left != NULL ? current->left : current->right;
    }
  }
}

// Function to search for a value in the tree
struct node* search(struct node* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    return search(root->left, data);
  } else if (data > root->data) {
    return search(root->right, data);
  } else {
    return root;
  }
}

// Function to traverse the tree
void traverse(struct node* root) {
  if (root != NULL) {
    traverse(root->left);
    printf("%d ", root->data);
    traverse(root->right);
  }
}

int main() {
  struct node* root = NULL;
  insert(&root, 5);
  insert(&root, 3);
  insert(&root, 7);
  insert(&root, 2);
  insert(&root, 4);
  insert(&root, 1);
  insert(&root, 6);

  struct node* found = search(root, 4);
  if (found != NULL) {
    printf("Found %d\n", found->data);
  } else {
    printf("Not found\n");
  }

  traverse(root);

  return 0;
}