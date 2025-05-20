//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Defined the structure for Binary Search Tree
struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};

//Function to create a new node for the Binary Search Tree
struct BST *newNode(int value){
    struct BST *temp = (struct BST*)malloc(sizeof(struct BST));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//Function to insert the nodes in Binary Search Tree
struct BST *insert(struct BST *node, int value){
    if(node == NULL){
        return newNode(value);
    }
    if(value < node->data){
        node->left = insert(node->left, value);
    }
    else if(value > node->data){
        node->right = insert(node->right, value);
    }
    return node;
}

//Function to print the values in Inorder Traversal
void InorderTraversal(struct BST *node){
    if(node == NULL){
        return;
    }
    InorderTraversal(node->left);
    printf("%d ", node->data);
    InorderTraversal(node->right);
}

//Main Function
int main()
{
    struct BST *root = NULL;
    
    //Adding 10 random nodes in the Binary Search Tree
    srand(time(0));
    printf("Adding 10 random nodes in Binary Search Tree:\n");
    for(int i = 0; i < 10; i++){
        int value = rand() % 100 + 1;
        root = insert(root, value);
    }
    
    //Printing the Binary Search Tree values in Inorder Traversal
    printf("\nInorder Traversal of Binary Search Tree:\n");
    InorderTraversal(root);
    printf("\n\nDone!\n");
    
    return 0;
}