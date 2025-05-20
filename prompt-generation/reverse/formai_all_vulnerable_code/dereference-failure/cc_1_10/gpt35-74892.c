//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

/* Define node structure */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Create a new node */
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insert a node into the tree */
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

/* Search for a node in the tree */
struct Node* search(struct Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    } else if (data < node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

/* Find the minimum node in the tree */
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

/* Delete a node from the tree */
struct Node* delete(struct Node* node, int data) {
    if (node == NULL) {
        return node;
    } else if (data < node->data) {
        node->left = delete(node->left, data);
    } else if (data > node->data) {
        node->right = delete(node->right, data);
    } else {
        /* Node found, let's delete it */
        if (node->left == NULL && node->right == NULL) {
            /* Case 1: Node has no children */
            free(node);
            node = NULL;
        } else if (node->left == NULL) {
            /* Case 2: Node has one child */
            struct Node* temp = node;
            node = node->right;
            free(temp);
        } else if (node->right == NULL) {
            struct Node* temp = node;
            node = node->left;
            free(temp);
        } else {
            /* Case 3: Node has two children */
            struct Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = delete(node->right, temp->data);
        }
    }
    return node;
}

/* Tree traversal */
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

/* Main function */
int main() {
    struct Node* root = NULL;
    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 5);
    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    printf("\n");
    printf("Deleting node with value 3...\n");
    root = delete(root, 3);
    printf("Inorder traversal of the binary search tree after deletion: ");
    inorder(root);
    printf("\n");
    struct Node* result = search(root, 5);
    if (result == NULL) {
        printf("Value not found in binary search tree.\n");
    } else {
        printf("Value %d found in binary search tree.\n", result->data);
    }
    return 0;
}