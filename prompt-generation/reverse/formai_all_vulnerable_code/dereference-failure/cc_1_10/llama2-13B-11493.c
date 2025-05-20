//LLAMA2-13B DATASET v1.0 Category: Binary search trees ; Style: brave
// Brave Binary Search Tree Example

#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function Prototypes
Node* createNode(int data);
void insertNode(Node** root, int data);
Node* searchNode(Node* root, int data);
void printTree(Node* root);

// Brave Binary Search Tree
int main() {
    Node* root = NULL;

    // Insert some nodes
    insertNode(&root, 5);
    insertNode(&root, 2);
    insertNode(&root, 8);
    insertNode(&root, 3);
    insertNode(&root, 1);
    insertNode(&root, 6);
    insertNode(&root, 4);

    // Search for some nodes
    printf("Searching for 5... ");
    if (searchNode(root, 5)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 2... ");
    if (searchNode(root, 2)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 8... ");
    if (searchNode(root, 8)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 3... ");
    if (searchNode(root, 3)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 1... ");
    if (searchNode(root, 1)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 6... ");
    if (searchNode(root, 6)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    printf("Searching for 4... ");
    if (searchNode(root, 4)) {
        printf("Found!\n");
    } else {
        printf("Not found.\n");
    }

    return 0;
}

// Function Definitions
Node* createNode(int data) {
    Node* node = malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
    } else {
        if (data < (*root)->data) {
            insertNode(&(*root)->left, data);
        } else {
            insertNode(&(*root)->right, data);
        }
    }
}

Node* searchNode(Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        return searchNode(root->left, data);
    } else if (data > root->data) {
        return searchNode(root->right, data);
    } else {
        return root;
    }
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}