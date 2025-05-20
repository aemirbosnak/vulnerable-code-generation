//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }

    if (data <= root->data) {
        if (root->left == NULL) {
            root->left = createNode(data);
        } else {
            insert(root->left, data);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(data);
        } else {
            insert(root->right, data);
        }
    }
}

void printTree(struct node* root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10;

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);

    printTree(root->left, space);
}

int main() {
    struct node* root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printTree(root, 0);

    return 0;
}