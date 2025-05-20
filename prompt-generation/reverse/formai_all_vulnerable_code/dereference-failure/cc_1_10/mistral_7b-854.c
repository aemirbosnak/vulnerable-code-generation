//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char key[21];
    struct Node *left, *right;
} Node;

Node* createNode(char *key) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node *root, Node *newNode) {
    if (root == NULL) {
        root = newNode;
    } else {
        int cmpRes = strcmp(root->key, newNode->key);

        if (cmpRes < 0)
            root->right = insertNode(root->right, newNode);
        else if (cmpRes > 0)
            root->left = insertNode(root->left, newNode);
    }
    return root;
}

Node* searchNode(Node *root, char *key) {
    Node *current = root;

    while (current != NULL) {
        int cmpRes = strcmp(current->key, key);

        if (cmpRes < 0)
            current = current->right;
        else if (cmpRes > 0)
            current = current->left;
        else
            return current;
    }

    return NULL;
}

Node* minValueNode(Node *node) {
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node *root, char *key) {
    Node *current = root, *delNode = NULL;

    if (root == NULL)
        return root;

    if (strcmp(root->key, key) < 0)
        root = deleteNode(root->right, key);
    else {
        delNode = root;
        if (root->left == NULL) {
            Node *temp = root->right;
            free(delNode);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(delNode);
            return temp;
        }

        Node *temp = minValueNode(root->left);
        strcpy(root->key, temp->key);
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void printTree(Node *node, int space) {
    if (node == NULL)
        return;

    space += 10;

    printTree(node->right, space);

    printf("\n%*.s%s", space, "", node->key);

    printTree(node->left, space);
}

int main() {
    Node *root = NULL;

    root = insertNode(root, createNode("apple"));
    root = insertNode(root, createNode("banana"));
    root = insertNode(root, createNode("cherry"));
    root = insertNode(root, createNode("date"));
    root = insertNode(root, createNode("elderberry"));
    root = insertNode(root, createNode("fig"));
    root = insertNode(root, createNode("grape"));
    root = insertNode(root, createNode("hackberry"));
    root = insertNode(root, createNode("indian gooseberry"));
    root = insertNode(root, createNode("jackfruit"));

    printf("Binary Search Tree:\n");
    printTree(root, 0);

    Node *search = searchNode(root, "fig");
    if (search != NULL)
        printf("\nFound node with key 'fig'");
    else
        printf("\nNode with key 'fig' not found");

    root = deleteNode(root, "fig");
    printf("\nDeleted node with key 'fig'");
    printf("\nBinary Search Tree after deletion:\n");
    printTree(root, 0);

    return 0;
}