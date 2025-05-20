//GEMINI-pro DATASET v1.0 Category: Binary search trees ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert_node(Node *root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

Node* search_node(Node *root, int data) {
    if (root == NULL) {
        return NULL;
    } else if (data == root->data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

void inorder_traversal(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main() {
    Node *root = NULL;
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 70);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    Node *found_node = search_node(root, 40);
    if (found_node != NULL) {
        printf("Found node with data: %d\n", found_node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}