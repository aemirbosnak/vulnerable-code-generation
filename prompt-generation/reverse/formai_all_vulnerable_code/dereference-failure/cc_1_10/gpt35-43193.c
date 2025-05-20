//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>

//Node structure
struct node{
    int data;
    struct node* left;
    struct node* right;
};

//Function to create a new node
struct node* createNode(int data){
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

//Function to insert a node in the tree
struct node* insertNode(struct node* root,int data){
    if(root==NULL){
        root=createNode(data);
    }
    else if(data<=root->data){
        root->left=insertNode(root->left,data);
    }
    else{
        root->right=insertNode(root->right,data);
    }
    return root;
}

//Function to print each node and its sub-trees
void printTree(struct node* root,int space){
    if(root==NULL){
        return;
    }
    space+=5;
    printTree(root->right,space);
    printf("\n");
    for(int i=5;i<space;i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    printTree(root->left,space);
}

//Main function
int main(){
    //Creating a sample binary search tree
    struct node* root=NULL;
    root=insertNode(root,50);
    insertNode(root,30);
    insertNode(root,20);
    insertNode(root,40);
    insertNode(root,70);
    insertNode(root,60);
    insertNode(root,80);

    //Printing the binary search tree
    printTree(root,0);

    return 0;
}