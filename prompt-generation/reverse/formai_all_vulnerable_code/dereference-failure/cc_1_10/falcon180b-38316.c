//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    char data[MAX];
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (strcmp(root->data, data) < 0) {
        root->right = insert(root->right, data);
    } else if (strcmp(root->data, data) > 0) {
        root->left = insert(root->left, data);
    }

    return root;
}

Node* search(Node* root, char* data) {
    if (root == NULL || strcmp(root->data, data) == 0) {
        return root;
    }

    if (strcmp(root->data, data) < 0) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

void inOrder(Node* root) {
    if (root!= NULL) {
        inOrder(root->left);
        printf("%s ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root!= NULL) {
        printf("%s ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root!= NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%s ", root->data);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "orange");
    root = insert(root, "grape");
    root = insert(root, "pear");

    printf("In-order traversal: ");
    inOrder(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrder(root);
    printf("\n");

    Node* searchNode = search(root, "orange");
    if (searchNode!= NULL) {
        printf("Found %s\n", searchNode->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}