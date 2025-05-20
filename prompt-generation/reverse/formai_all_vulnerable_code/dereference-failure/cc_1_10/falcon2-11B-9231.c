//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: minimalist
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

// Insert a new node with key 'key' into the tree rooted at 'root'
void insert(Node* root, int key) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node));
        root->key = key;
        root->left = root->right = NULL;
        return;
    }

    if (key < root->key)
        insert(root->left, key);
    else
        insert(root->right, key);
}

// Print all keys in the tree rooted at 'root'
void print_tree(Node* root) {
    if (root == NULL)
        return;

    printf("%d\n", root->key);
    print_tree(root->left);
    print_tree(root->right);
}

// The main function
int main() {
    Node* root = NULL;

    // Insert the following nodes into the tree
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print all keys in the tree
    print_tree(root);

    return 0;
}