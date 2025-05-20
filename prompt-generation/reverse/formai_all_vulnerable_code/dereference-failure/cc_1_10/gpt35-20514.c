//FormAI DATASET v1.0 Category: Binary search trees ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

void printTree(Node* root, int indent) {
    if (root == NULL) {
        return;
    }
    printTree(root->right, indent + 4);
    printf("%*s%d\n", indent, "", root->key);
    printTree(root->left, indent + 4);
}

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main() {
    srand(time(NULL));
    Node* root = NULL;
    int numNodes = 10;
    for (int i = 0; i < numNodes; i++) {
        root = insert(root, rand() % 100);
    }
    printf("Initial Binary Search Tree:\n");
    printTree(root, 0);
    int searchKey = root->key;
    Node* searchResult = search(root, searchKey);
    if (searchResult == NULL) {
        printf("Error: Couldn't find a node with key %d\n", searchKey);
    }
    else {
        printf("Found node with key %d\n", searchKey);
    }
    printf("Deleting node with key %d\n", searchKey);
    root = deleteNode(root, searchKey);
    printf("New Binary Search Tree:\n");
    printTree(root, 0);
    return 0;
}