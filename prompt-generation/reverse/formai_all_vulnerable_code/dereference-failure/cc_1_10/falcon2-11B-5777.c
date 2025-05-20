//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        root = createNode(key);
        return root;
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* node) {
    if (node!= NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

void freeTree(Node* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    int key;
    while (1) {
        printf("Enter a key to insert or -1 to quit: ");
        scanf("%d", &key);
        if (key == -1) {
            break;
        }
        root = insert(root, key);
    }
    inorder(root);
    printf("\n");
    freeTree(root);
    return 0;
}