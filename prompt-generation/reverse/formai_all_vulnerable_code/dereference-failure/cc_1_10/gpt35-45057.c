//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

/* Insert function */
Node* insert(Node* root, int value) {
  if (root == NULL) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
  }
  if (value < root->data) {
    root->left = insert(root->left, value);
  } 
  else {
    root->right = insert(root->right, value);
  }
  return root;
}

/* Search function */
Node* search(Node* root, int value){
  while(root != NULL) {
    if(value == root->data){
      return root;
    }
    else if (value < root->data) {
      root = root->left;
    }
    else{
      root = root->right;
    }
  }
  return NULL;
}

/* Traversal functions - Inorder, Preorder and Postorder */
void inorder(Node* root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}
void preorder(Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}
void postorder(Node* root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

/* Main function */
int main() {
  Node *root = NULL;
  int choice, value;

  /* Menu */
  do {
    printf("\nBinary Search Tree Operations\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Inorder Traversal\n");
    printf("4. Preorder Traversal\n");
    printf("5. Postorder Traversal\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
        break;
      case 2:
        printf("Enter the value to search: ");
        scanf("%d", &value);
        if (search(root, value) != NULL) {
          printf("Value found!\n");
        } else {
          printf("Value not found!\n");
        }
        break;
      case 3:
        printf("Inorder Traversal: ");
        inorder(root);
        printf("\n");
        break;
      case 4:
        printf("Preorder Traversal: ");
        preorder(root);
        printf("\n");
        break;
      case 5:
        printf("Postorder Traversal: ");
        postorder(root);
        printf("\n");
        break;
      case 6:
        printf("Exiting...Goodbye!\n");
        break;
      default:
        printf("Invalid choice!\n");
    }
  } while (choice != 6);

  return 0;
}