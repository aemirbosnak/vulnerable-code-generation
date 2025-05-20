//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>

// Node definition
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Binary search tree functions
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct node* root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else if (data < root->data) {
        insert(root->left, data);
    } else {
        insert(root->right, data);
    }
}

int search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return 1;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void printTree(struct node* root) {
    if (root!= NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main() {
    struct node* root = NULL;

    // Create the BST
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the BST
    printf("BST: \n");
    printTree(root);

    // Search for a node in the BST
    printf("Is 50 in the BST? %d\n", search(root, 50));
    printf("Is 90 in the BST? %d\n", search(root, 90));

    return 0;
}