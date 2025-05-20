//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

// Structure to represent a node in the tree
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// Function to insert a new node in the tree
struct node* insertNode(struct node* root, int value){
    if(root == NULL){
        return createNode(value);
    }

    if(root->data > value){
        root->left = insertNode(root->left, value);
    }
    else{
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to search for a value in the tree
void search(struct node* root, int value){
    if(root == NULL){
        printf("Value not found in the tree!\n");
        return;
    }

    if(root->data == value){
        printf("Value found in the tree!\n");
        return;
    }

    if(root->data > value){
        search(root->left, value);
    }
    else{
        search(root->right, value);
    }
}

// Function to print the tree inorder
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;

    // Insert nodes in the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the tree inorder
    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");

    // Search for a value in the tree
    int value = 60;
    printf("Searching for value %d in the tree...\n", value);
    search(root, value);

    value = 100;
    printf("Searching for value %d in the tree...\n", value);
    search(root, value);

    return 0;
}