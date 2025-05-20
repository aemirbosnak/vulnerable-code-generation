//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: Cryptic
//cryptic binary search tree implementation

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct node{
  int data;
  struct node *left;
  struct node *right;
}node;

//insert a node into a binary search tree
void insert(node **root, int data){
  if(*root==NULL){ // if the tree is empty, create a new node
    *root=(node*)malloc(sizeof(node));
    (*root)->data=data;
    (*root)->left=NULL;
    (*root)->right=NULL;
  }
  else if(data<(*root)->data){ // if the data is less than the root, insert it into the left subtree
    insert(&(*root)->left,data);
  }
  else{ // if the data is greater than the root, insert it into the right subtree
    insert(&(*root)->right,data);
  }
}

//search for a node in a binary search tree
node* search(node *root, int data){
  if(root==NULL){ // if the tree is empty, the node is not found
    return NULL;
  }
  else if(root->data==data){ // if the root is the node we are looking for, return it
    return root;
  }
  else if(data<root->data){ // if the data is less than the root, search for it in the left subtree
    return search(root->left,data);
  }
  else{ // if the data is greater than the root, search for it in the right subtree
    return search(root->right,data);
  }
}

//delete a node from a binary search tree
void delete(node **root, int data){
  if(*root==NULL){ // if the tree is empty, the node is not found
    return;
  }
  else if(data<(*root)->data){ // if the data is less than the root, delete it from the left subtree
    delete(&(*root)->left,data);
  }
  else if(data>(*root)->data){ // if the data is greater than the root, delete it from the right subtree
    delete(&(*root)->right,data);
  }
  else{ // if the data is equal to the root, delete it
    if((*root)->left==NULL){ // if the root has no left child, replace it with its right child
      node *temp=*root;
      *root=(*root)->right;
      free(temp);
    }
    else if((*root)->right==NULL){ // if the root has no right child, replace it with its left child
      node *temp=*root;
      *root=(*root)->left;
      free(temp);
    }
    else{ // if the root has both a left and a right child, replace it with its inorder successor
      node *temp=(*root)->right;
      while(temp->left!=NULL){
        temp=temp->left;
      }
      (*root)->data=temp->data;
      delete(&(*root)->right,temp->data);
    }
  }
}

//print a binary search tree in order
void print_inorder(node *root){
  if(root==NULL){ // if the tree is empty, return
    return;
  }
  print_inorder(root->left); // print the left subtree
  printf("%d ",root->data); // print the root
  print_inorder(root->right); // print the right subtree
}

//print a binary search tree in preorder
void print_preorder(node *root){
  if(root==NULL){ // if the tree is empty, return
    return;
  }
  printf("%d ",root->data); // print the root
  print_preorder(root->left); // print the left subtree
  print_preorder(root->right); // print the right subtree
}

//print a binary search tree in postorder
void print_postorder(node *root){
  if(root==NULL){ // if the tree is empty, return
    return;
  }
  print_postorder(root->left); // print the left subtree
  print_postorder(root->right); // print the right subtree
  printf("%d ",root->data); // print the root
}

//main function
int main(){
  node *root=NULL; // create an empty binary search tree

  //insert some data into the tree
  insert(&root,10);
  insert(&root,5);
  insert(&root,15);
  insert(&root,2);
  insert(&root,7);
  insert(&root,12);
  insert(&root,20);

  //print the tree in order
  printf("In order: ");
  print_inorder(root);
  printf("\n");

  //print the tree in preorder
  printf("Pre order: ");
  print_preorder(root);
  printf("\n");

  //print the tree in postorder
  printf("Post order: ");
  print_postorder(root);
  printf("\n");

  //search for a node in the tree
  node *found=search(root,12);
  if(found!=NULL){ // if the node was found, print its data
    printf("Found: %d\n",found->data);
  }
  else{ // if the node was not found, print an error message
    printf("Not found\n");
  }

  //delete a node from the tree
  delete(&root,10);

  //print the tree in order
  printf("In order: ");
  print_inorder(root);
  printf("\n");

  return 0;
}