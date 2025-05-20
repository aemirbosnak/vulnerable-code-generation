//FormAI DATASET v1.0 Category: Binary search trees ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

// structure for node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

// function to create new node
struct node* new_node(int data){
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// recursive function to insert nodes in the tree
struct node* insert(struct node* node, int data){
    if(node == NULL){
      return new_node(data);
    }
    if(data < node->data){
      node->left = insert(node->left, data);
    }
    else if(data > node->data){
      node->right = insert(node->right, data);
    }
    return node;
}

// recursive function to perform inorder traversal
void inorder_traversal(struct node *root){
  if(root!=NULL){
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
  }
}

// recursive function to perform preorder traversal
void preorder_traversal(struct node *root){
  if(root!=NULL){
    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
  }
}

// recursive function to perform postorder traversal
void postorder_traversal(struct node *root){
  if(root!=NULL){
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
  }
}

// recursive function to search for a node in the tree
struct node* search(struct node* root, int key){
  if(root==NULL || root->data==key){
    return root;
  }
  if(root->data < key){
    return search(root->right, key);
  }
  return search(root->left, key);
}

// main function
int main(){

  struct node *root = NULL;
  struct node *search_node = NULL;

  // Inserting nodes in the tree
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);

  // Traversing the tree
  printf("Inorder Traversal: ");
  inorder_traversal(root);

  printf("\nPreorder Traversal: ");
  preorder_traversal(root);

  printf("\nPostorder Traversal: ");
  postorder_traversal(root);

  // Searching for a node in the tree
  search_node = search(root, 30);
  if(search_node!=NULL){
    printf("\n\n%d is present in the tree.", search_node->data);
  }
  else{
    printf("\n\n%d is not present in the tree.", 30);
  }

  return 0;
}