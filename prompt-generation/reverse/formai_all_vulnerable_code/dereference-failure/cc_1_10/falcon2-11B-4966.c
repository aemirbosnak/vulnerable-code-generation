//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Sherlock's Binary Search Tree
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* createBSTNode(int key) {
    BSTNode* newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int compare(const void* a, const void* b) {
    int* val1 = (int*) a;
    int* val2 = (int*) b;
    return (*val1 < *val2)? -1 : 1;
}

void insert(BSTNode* root, int key) {
    if (root == NULL) {
        root = createBSTNode(key);
    } else {
        if (compare(&key, &root->key) < 0) {
            insert(root->left, key);
        } else if (compare(&key, &root->key) > 0) {
            insert(root->right, key);
        } else {
            printf("Key already exists in the tree.\n");
        }
    }
}

void printInOrder(BSTNode* root) {
    if (root!= NULL) {
        printInOrder(root->left);
        printf("%d ", root->key);
        printInOrder(root->right);
    }
}

int main() {
    BSTNode* root = NULL;

    // Insert elements into the BST
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);
    insert(root, 90);

    // Print the elements in the BST in InOrder traversal
    printf("In Order Traversal of the BST:\n");
    printInOrder(root);

    return 0;
}