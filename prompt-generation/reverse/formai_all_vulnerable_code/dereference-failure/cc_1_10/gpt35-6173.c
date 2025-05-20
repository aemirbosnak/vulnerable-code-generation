//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void printSpace(int n) {
    for(int i=0; i<n; i++) {
        printf(" ");
    }
}

void printTree(int space, struct node* node) {
    if(node == NULL) {
        return;
    }

    space += 5;

    printTree(space, node->right);

    printf("\n");
    printSpace(space);
    printf("%d\n", node->data);

    printTree(space, node->left);
}

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if(root == NULL) {
        root = createNode(data);
        return root;
    }

    if(data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

int main() {
    struct node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 15);
    root = insert(root, 5);
    root = insert(root, 9);

    printf("Binary Search Tree Visualization:\n");
    printTree(0, root);

    return 0;
}