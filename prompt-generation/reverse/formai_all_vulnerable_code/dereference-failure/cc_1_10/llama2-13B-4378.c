//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform binary search
struct Node* binarySearch(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        return binarySearch(root->left, key);
    } else if (key > root->data) {
        return binarySearch(root->right, key);
    } else {
        return root;
    }
}

// Function to insert a new node into the tree
void insertNode(struct Node** root_ref, int data) {
    struct Node* root = *root_ref;

    if (root == NULL) {
        root = newNode(data);
        *root_ref = root;
    } else {
        if (data < root->data) {
            insertNode(&root->left, data);
        } else {
            insertNode(&root->right, data);
        }
    }
}

// Function to print the tree
void printTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("Tree: ");

    if (root->left != NULL) {
        printTree(root->left);
        printf(" ");
    }

    printf("%d ", root->data);

    if (root->right != NULL) {
        printTree(root->right);
        printf(" ");
    }

    printf("\n");
}

int main() {
    struct Node* root = NULL;

    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 6);

    struct Node* node = binarySearch(root, 5);

    if (node != NULL) {
        printf("Found %d\n", node->data);
    } else {
        printf("Not found\n");
    }

    printTree(root);

    return 0;
}