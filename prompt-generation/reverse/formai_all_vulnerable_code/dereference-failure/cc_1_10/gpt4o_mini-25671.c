//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 10;  // Increase distance between levels
    printTree(root->right, space);
    
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    
    printTree(root->left, space);
}

void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    srand(time(NULL));  // Seed for random number generation

    for (int i = 0; i < 10; i++) {
        int num = rand() % 100;  // Generate numbers between 0 and 99
        printf("Inserting %d into the tree.\n", num);
        root = insert(root, num);
    }

    printf("\nBinary Search Tree Visualization:\n");
    printTree(root, 0);
    
    freeTree(root); // Clean up allocated memory
    return 0;
}