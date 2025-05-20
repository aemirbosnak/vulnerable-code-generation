//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: safe
#include <stdio.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* newNode(int key) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    
    return root;
}

void preorder(Node* node) {
    if (node!= NULL) {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    preorder(root);
    return 0;
}