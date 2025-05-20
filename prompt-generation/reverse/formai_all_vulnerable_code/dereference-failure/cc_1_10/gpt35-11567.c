//FormAI DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the struct for Binary search tree
typedef struct Node {
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

// Function to insert a new node
void insertNode(Node **root, int value) {
    if (*root == NULL) {  // Base case
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->data = value;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        *root = newNode;
    } else if (value < (*root)->data) {
        insertNode(&((*root)->leftChild), value);
    } else {
        insertNode(&((*root)->rightChild), value);
    }
}

// Function to perform Inorder traversal of the BST
void inorderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->leftChild);
    printf("%d ", root->data);
    inorderTraversal(root->rightChild);
}

// Input array for nodes
int inputValues[] = {50, 30, 20, 40, 70, 60, 80};

// Function to thread the program
void *threadFunction(void *root) {
    // Inserting nodes in BST
    int inputSize = sizeof(inputValues) / sizeof(inputValues[0]);
    for (int i = 0; i < inputSize; i++) {
        insertNode((Node **)root, inputValues[i]);
    }
    printf("inorder traversal in worker: ");
    inorderTraversal(*((Node **)root));
    printf("\n");
    pthread_exit(NULL);
}

// a. A unique C Binary search trees example program in a multi-threaded style.
int main() {
    Node *root = NULL;
    pthread_t thread;
    pthread_create(&thread, NULL, threadFunction, (void *)&root);
    printf("inorder traversal in main: ");
    inorderTraversal(root);
    printf("\n");
    pthread_join(thread, NULL);
    return 0;
}