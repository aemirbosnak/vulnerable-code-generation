//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: cheerful
#include <stdio.h>

// Node structure for binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to print binary search tree
void printBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    printBST(root->left);
    printBST(root->right);
}

int main() {
    // Create a binary search tree with some values
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = 50;
    root->left = NULL;
    root->right = NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = 30;
    node->left = NULL;
    node->right = NULL;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 20;
    node2->left = NULL;
    node2->right = NULL;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 40;
    node3->left = NULL;
    node3->right = NULL;

    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node4->data = 70;
    node4->left = NULL;
    node4->right = NULL;

    root->left = node;
    root->right = node2;
    node->left = node3;
    node->right = node4;

    printBST(root);

    free(root);
    free(node);
    free(node2);
    free(node3);
    free(node4);

    return 0;
}