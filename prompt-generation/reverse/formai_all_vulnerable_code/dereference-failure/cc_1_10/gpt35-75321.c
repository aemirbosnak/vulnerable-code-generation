//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Define the Node structure
struct node {
    int data;	//To store the data
    struct node *left;	//To point to left subtree
    struct node *right;	//To point to right subtree
};

//Function prototypes
struct node* createNode(int);	//Create a new node
struct node* insert(struct node*, int);	//Insert the node into BST
void printTree(struct node*, int); //Print the BST visually

int main() {
    int i, num;
    struct node *root = NULL;

    srand(time(0));	//Seed for random numbers
    printf("Visual representation of Binary Search Tree:\n");

    //Insert 10 random numbers into BST
    for(i = 0; i < 10; i++) {
        num = rand() % 100;
        root = insert(root, num);
        printf("%d ", num);
    }
    printf("\n");

    printTree(root, 0); //Print the BST
    return 0;
}

//Function to create a new node
struct node* createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//Function to insert the node into BST
struct node* insert(struct node *root, int data) {
    if(root == NULL) {	//If the BST is empty
        root = createNode(data);
    }
    else if(data <= root->data) {	//If data is less than or equal to the root value
        root->left = insert(root->left, data);
    }
    else {	//If data is greater than the root value
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to print the BST visually
void printTree(struct node *root, int space) {
    if(root == NULL) {
        return;
    }
    space += 10;	//Increase distance between levels

    printTree(root->right, space);	//Print the right subtree

    printf("\n");
    for(int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);	//Print the current node

    printTree(root->left, space);	//Print the left subtree
}