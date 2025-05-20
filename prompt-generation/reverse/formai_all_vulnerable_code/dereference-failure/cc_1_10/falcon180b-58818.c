//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    char data[MAX_SIZE];
    struct node* left;
    struct node* right;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, char* data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (strcmp(root->data, data) < 0) {
        root->right = insert(root->right, data);
    } else {
        root->left = insert(root->left, data);
    }

    return root;
}

Node* search(Node* root, char* data) {
    if (root == NULL || strcmp(root->data, data) == 0) {
        return root;
    } else if (strcmp(root->data, data) < 0) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%s ", root->data);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    printf("%s ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%s ", root->data);
}

int main() {
    Node* root = NULL;

    root = insert(root, "apple");
    root = insert(root, "banana");
    root = insert(root, "orange");
    root = insert(root, "pear");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    Node* searchResult = search(root, "orange");
    if (searchResult!= NULL) {
        printf("Found '%s'\n", searchResult->data);
    } else {
        printf("Not found\n");
    }

    return 0;
}