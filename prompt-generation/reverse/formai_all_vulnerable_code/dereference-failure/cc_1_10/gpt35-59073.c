//FormAI DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a node structure for the binary tree
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new Node
struct Node* getNewNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert data into the binary tree
struct Node* insert(struct Node* rootptr, int data){
    if(rootptr == NULL){
        rootptr = getNewNode(data);
    }
    else if(data <= rootptr->data){
        rootptr->left = insert(rootptr->left,data);
    }
    else{
        rootptr->right = insert(rootptr->right,data);
    }
    return rootptr;
}

// function to generate random values and insert them into the binary tree
void generateValues(struct Node* rootptr, int numOfValues){
    for(int i=0; i<numOfValues; i++){
        int value = rand() % (numOfValues*2);
        rootptr = insert(rootptr, value);
    }
}

// function to print the binary tree in a in-order traversal manner
void printTree(struct Node* rootptr){
    if(rootptr != NULL){
        printTree(rootptr->left);
        printf("%d ", rootptr->data);
        fflush(stdout); //flush the standard output stream
        printTree(rootptr->right);
    }
}

// main function to run the program
int main(){
    srand(time(NULL)); // seed the random number generator
    struct Node* rootptr = NULL; // initialize the root node to NULL
    int numOfValues = 10; // number of values to insert into the tree
    generateValues(rootptr, numOfValues); // generate random values and insert into the binary tree
    printf("\nHere is a visualization of your binary tree (in-order traversal):\n");
    printTree(rootptr); // print the binary tree in a in-order traversal manner
    printf("\n");
    free(rootptr); // free allocated memory
    return 0;
}