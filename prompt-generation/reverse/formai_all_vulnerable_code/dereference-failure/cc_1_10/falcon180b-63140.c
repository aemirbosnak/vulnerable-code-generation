//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node
struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Function to insert a node in the binary search tree
struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        root = newNode(data);
        return root;
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to search for a node in the binary search tree
struct Node* search(struct Node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

//Function to print the binary search tree in inorder traversal
void inorder(struct Node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 9);
    printf("Inorder traversal of the binary search tree:\n");
    inorder(root);
    printf("\n");
    struct Node* searchNode = search(root, 5);
    if(searchNode!= NULL){
        printf("Node found with value %d\n", searchNode->data);
    }
    else{
        printf("Node not found\n");
    }
    return 0;
}