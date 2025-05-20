//FormAI DATASET v1.0 Category: Binary search trees ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the binary search tree node
struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node *newNode(int value){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

// Function to insert a node in the tree
struct node *insert(struct node *root, int key){
    if(root==NULL)
        return newNode(key);
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Function to search for a given key in the tree
struct node *search(struct node *root, int key){
    if(root==NULL || root->data==key)
        return root;
    if(key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Function to find the minimum value node in the tree
struct node *minValueNode(struct node *node){
    struct node *current = node;
    while(current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node with the given key from the tree
struct node *deleteNode(struct node *root, int key){
    if(root==NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the inorder traversal of the tree
void inorderTraversal(struct node *root){
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Main function to demonstrate the binary search tree
int main(){
    struct node *root = NULL;
    root = insert(root, 55);
    insert(root, 35);
    insert(root, 85);
    insert(root, 30);
    insert(root, 50);
    insert(root, 80);
    insert(root, 100);
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\nSearch for key 80: ");
    if(search(root, 80)!=NULL)
        printf("Found\n");
    else
        printf("Not Found\n");
    printf("Delete node with key 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the tree after deletion: ");
    inorderTraversal(root);
    return 0;
}