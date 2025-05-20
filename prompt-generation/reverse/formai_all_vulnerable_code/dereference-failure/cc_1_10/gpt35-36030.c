//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

void printSubtree(Node* node, int depth, char linkChar, int isLeft) {
    if (node == NULL) {
        return;
    }
    
    for (int i = 0; i < depth-1; i++) {
        printf(" ");
    }
    if (depth > 0) {
       printf("%c", linkChar);
       printf(isLeft ? "|-- " : "\\-- ");
    }
    printf("%d\n", node->data);
    
    if (node->left != NULL || node->right != NULL) {
        printSubtree(node->left, depth+1, '/', 1);
        printSubtree(node->right, depth+1, '\\', 0);
    }
}

void printTree(Node* root) {
    printSubtree(root, 0, ' ', 1);
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 8);
    insert(root, 6);
    insert(root, 3);
    insert(root, 9);
    
    printTree(root);
    
    return 0;
}