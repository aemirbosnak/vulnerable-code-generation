//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a node in the binary search tree*/
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

/* Function to create a new node*/
Node* NewNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Function to insert a new node into the binary search tree*/
void Insert(Node** root, int data){
    if (*root == NULL){
        *root = NewNode(data);
    }
    else if (data <= (*root)->data){
        Insert(&((*root)->left), data);
    }
    else{
        Insert(&((*root)->right), data);
    }
}

/* Function to search for a node in the binary search tree*/
Node* Search(Node* root, int data){
    if (root == NULL){
        return NULL;
    }
    else if (root->data == data){
        return root;
    }
    else if (data < root->data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

/* Function to print the data elements of a binary search tree in order*/
void PrintInOrder(Node* root){
    if (root != NULL){
        PrintInOrder(root->left);
        printf("%d ", root->data);
        PrintInOrder(root->right);
    }
}

/* Test the binary search tree*/
int main(){
    Node* root = NULL;
    Insert(&root, 10);
    Insert(&root, 20);
    Insert(&root, 5);
    Insert(&root, 8);
    Insert(&root, 30);
    Insert(&root, 3);
    Node* found_node = Search(root, 5);
    printf("Node with data %d was found.\n", found_node->data);
    printf("In Order traversal result: ");
    PrintInOrder(root);
    return 0;
}