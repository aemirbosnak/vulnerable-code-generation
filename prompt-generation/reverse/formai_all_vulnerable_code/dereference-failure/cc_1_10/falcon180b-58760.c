//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *root;

node* createNode(int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node* insertNode(node *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }

    return root;
}

node* searchNode(node *root, int data){
    if(root == NULL || root->data == data){
        return root;
    }

    if(data < root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}

void inorderTraversal(node *root){
    if(root!= NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the given tree\n");
    inorderTraversal(root);

    node *search = searchNode(root, 60);
    if(search!= NULL){
        printf("\nNode with data = %d is present in the tree\n", search->data);
    }
    else{
        printf("\nNode with data = %d is not present in the tree\n", 60);
    }

    return 0;
}