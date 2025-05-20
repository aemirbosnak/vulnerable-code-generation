//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Struct to define a Node in the Binary Search Tree
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

// Function to create a new Node
Node *createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a Node into the Binary Search Tree
void insertNode(Node **root, Node *newNode) {
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    if (newNode->value < (*root)->value) {
        insertNode(&((*root)->left), newNode);
    }
    else if (newNode->value > (*root)->value) {
        insertNode(&((*root)->right), newNode);
    }
}

// Function to search for a Node in the Binary Search Tree
Node *searchNode(Node *root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value) {
        return searchNode(root->left, value);
    }
    else {
        return searchNode(root->right, value);
    }
}

// Function to print out the Binary Search Tree using In-order Traversal
void inOrderTraversal(Node *root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

int main() {
    srand(time(NULL));
    Node *root = NULL;
    int numNodes = 10;
    
    // Generate some random numbers to insert into the Binary Search Tree
    printf("Inserting the following numbers into the Binary Search Tree:\n");
    for (int i = 0; i < numNodes; i++) {
        int value = rand() % 100;
        printf("%d ", value);
        insertNode(&root, createNode(value));
    }
    printf("\n\nIn-order Traversal of the Binary Search Tree:\n");
    inOrderTraversal(root);
    
    printf("\n\nSearching for the value 42 in the Binary Search Tree...\n");
    Node *searchResult = searchNode(root, 42);
    if (searchResult == NULL) {
        printf("Value 42 not found in the Binary Search Tree.\n");
    }
    else {
        printf("Value 42 found in the Binary Search Tree!\n");
    }
    
    return 0;
}