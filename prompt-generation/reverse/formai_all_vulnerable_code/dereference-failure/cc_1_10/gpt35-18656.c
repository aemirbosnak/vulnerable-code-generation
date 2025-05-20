//FormAI DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void insert(struct node **root, int data) {
  if (*root == NULL) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    *root = new_node;
    return;
  }

  if (data < (*root)->data) {
    insert(&((*root)->left), data);
  } else {
    insert(&((*root)->right), data);
  }
}

struct node* search(struct node* root, int data) {
  if (root == NULL) {
    return NULL;
  }

  if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

void inorder(struct node* root) {
  if (root == NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void delete(struct node **root, int data) {
  if (*root == NULL) {
    return;
  }

  if (data < (*root)->data) {
    delete(&((*root)->left), data);
  } else if (data > (*root)->data) {
    delete(&((*root)->right), data);
  } else {
    if ((*root)->left == NULL) {
      struct node *temp = *root;
      *root = (*root)->right;
      free(temp);
    } else if ((*root)->right == NULL) {
      struct node *temp = *root;
      *root = (*root)->left;
      free(temp);
    } else {
      struct node *temp = (*root)->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      (*root)->data = temp->data;
      delete(&((*root)->right), temp->data);
    }
  }
}

int main() {
  struct node *root = NULL;

  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 20);
  insert(&root, 40);
  insert(&root, 70);
  insert(&root, 60);
  insert(&root, 80);

  printf("Inorder traversal of the binary search tree:\n");
  inorder(root);

  printf("\nSearching for 40 in the binary search tree:\n");
  struct node *node1 = search(root, 40);
  if (node1 != NULL) {
    printf("%d is present in the binary search tree.\n", node1->data);
  } else {
    printf("40 is not present in the binary search tree.\n");
  }

  printf("\nDeleting 30 from the binary search tree:\n");
  delete(&root, 30);
  printf("Inorder traversal of the binary search tree after deletion:\n");
  inorder(root);

  return 0;
}