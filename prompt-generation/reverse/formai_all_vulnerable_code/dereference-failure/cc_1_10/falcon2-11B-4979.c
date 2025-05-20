//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Inserts a new key into the BST.
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return (struct Node*) malloc(sizeof(struct Node));
    }
    if (key < node->data) {
        node->left = insert(node->left, key);
    } else if (key > node->data) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Performs an in-order traversal of the BST and returns the smallest key.
int inorder(struct Node* node) {
    if (node == NULL) {
        return -1;
    }
    int left = inorder(node->left);
    if (left!= -1) {
        printf("%d ", left);
    }
    printf("%d ", node->data);
    int right = inorder(node->right);
    if (right!= -1) {
        printf("%d\n", right);
    }
    return node->data;
}

// Searches for a given key in the BST and returns its value.
int search(struct Node* node, int key) {
    if (node == NULL) {
        return -1;
    }
    if (key < node->data) {
        return search(node->left, key);
    } else if (key > node->data) {
        return search(node->right, key);
    } else {
        return node->data;
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 8);
    insert(root, 4);
    insert(root, 2);

    printf("Inorder traversal: ");
    inorder(root);

    int smallest = search(root, 2);
    if (smallest!= -1) {
        printf("Smallest key: %d\n", smallest);
    } else {
        printf("Smallest key not found.\n");
    }

    return 0;
}