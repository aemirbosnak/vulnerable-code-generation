//FormAI DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// node structure
struct treeNode {
    int data;
    struct treeNode* left;
    struct treeNode* right;
};

// function to create new node
struct treeNode* createNode(int value) {
    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert node
struct treeNode* insertNode(struct treeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// function to search node
struct treeNode* searchNode(struct treeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (root->data < key) {
        return searchNode(root->right, key);
    }

    return searchNode(root->left, key);
}

// function to find minimum value node
struct treeNode* minValueNode(struct treeNode* node) {
    struct treeNode* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

// function to delete node
struct treeNode* deleteNode(struct treeNode* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct treeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct treeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct treeNode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// function to traverse in-order tree
void printInorder(struct treeNode* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->data);
        printInorder(root->right);
    }
}

// main function
int main() {
    struct treeNode* root = NULL;

    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // print in-order traversal
    printf("In-order traversal: ");
    printInorder(root);
    printf("\n");

    // delete node with value 20
    root = deleteNode(root, 20);

    // print in-order traversal
    printf("In-order traversal after deleting node with value 20: ");
    printInorder(root);
    printf("\n");

    return 0;
}