//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: innovative
// **C BINARY SEARCH TREE EXAMPLE**

#include <stdio.h>
#include <stdlib.h>

// **Node Structure**
typedef struct node {
  int data;
  struct node *left;
  struct node *right;
} Node;

// **Insert Node**
Node *insert(Node *root, int data) {
  if (root == NULL) {
    root = (Node *)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  } else if (data <= root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

// **Search Node**
Node *search(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  } else if (data == root->data) {
    return root;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}

// **Delete Node**
Node *delete(Node *root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = delete(root->left, data);
  } else if (data > root->data) {
    root->right = delete(root->right, data);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    } else {
      Node *temp = root->right;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      root->data = temp->data;
      root->right = delete(root->right, temp->data);
    }
  }
  return root;
}

// **Print Tree**
void print(Node *root) {
  if (root == NULL) {
    return;
  }
  print(root->left);
  printf("%d ", root->data);
  print(root->right);
}

// **Main Function**
int main() {
  Node *root = NULL;
  int choice, data;

  // Menu-driven Interface
  while (1) {
    printf("\n1. Insert\n2. Search\n3. Delete\n4. Print\n5. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
        break;
      case 2:
        printf("Enter data to be searched: ");
        scanf("%d", &data);
        Node *node = search(root, data);
        if (node != NULL) {
          printf("Data found!\n");
        } else {
          printf("Data not found!\n");
        }
        break;
      case 3:
        printf("Enter data to be deleted: ");
        scanf("%d", &data);
        root = delete(root, data);
        break;
      case 4:
        print(root);
        printf("\n");
        break;
      case 5:
        exit(0);
      default:
        printf("Invalid choice!\n");
        break;
    }
  }

  return 0;
}