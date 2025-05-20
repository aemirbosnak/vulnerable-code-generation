//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Binary Search Tree Node
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

//Insertion method to add nodes into the tree
struct BSTNode* insertion(struct BSTNode *root, int value){
    //If root is null then create a new node
    if(root==NULL){
        struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    //If value is smaller than root node, go to left subtree to insert
    if(value < root->data){
        root->left = insertion(root->left, value);
    }
    //If value is greater than root node, go to right subtree to insert
    else if(value > root->data){
        root->right = insertion(root->right, value);
    }
    return root;
}

//Print method to print the nodes in Inorder traversal
void printInorder(struct BSTNode *root){
    if(root==NULL) return;
    printInorder(root->left);
    printf("%d ",root->data);
    printInorder(root->right);
}

int main(){
    //Random number generator
    srand(time(0));
    
    struct BSTNode *root = NULL;    
    printf("Random elements are generated and stored in Binary Search Tree");
    
    //Inserting 10 random numbers between 1 to 100 into the tree
    for(int i=0;i<10;i++){
        int num = rand()%100+1; //random number between 1 to 100
        root = insertion(root, num);
    }
    printf("\n\nInorder traversal of Binary Search Tree: ");
    printInorder(root);
    
    return 0;
}