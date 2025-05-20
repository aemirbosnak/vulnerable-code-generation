//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Node {
    int key;
    char name[50];
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;
typedef Node* NodePtr;

NodePtr newNode(int key, char *name) {
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->key = key;
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

NodePtr insert(NodePtr root, int key, char *name) {
    if (root == NULL) {
        root = newNode(key, name);
        return root;
    }

    if (key < root->key) {
        root->left = insert(root->left, key, name);
    } else if (key > root->key) {
        root->right = insert(root->right, key, name);
    } else {
        printf("Duplicate key: %d\n", key);
    }

    return root;
}

void inOrderTraversal(NodePtr root) {
    if (root == NULL) {
        return;
    }

    inOrderTraversal(root->left);
    printf("%s %d\n", root->name, root->key);
    inOrderTraversal(root->right);
}

int main() {
    NodePtr root = NULL;

    // Inserting nodes
    root = insert(root, 15, "Mango");
    root = insert(root, 10, "Apple");
    root = insert(root, 20, "Banana");
    root = insert(root, 5, "Grapes");
    root = insert(root, 25, "Orange");

    // Inorder traversal to print keys and names
    inOrderTraversal(root);

    return 0;
}