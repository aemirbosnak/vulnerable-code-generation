//FormAI DATASET v1.0 Category: Binary search trees ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * left;
    struct Node * right;
} Node;

Node * newNode(int value) {
    Node * node = malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node * insert(Node * root, int value) {
    if (root == NULL) {
        return newNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderTraversal(Node * root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node * root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node * root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

Node * minValueNode(Node * node) {
    Node * current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node * deleteNode(Node * root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node * temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node * temp = root->left;
            free(root);
            return temp;
        }
        Node * temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    Node * root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("In Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Deleting node 20\n");
    root = deleteNode(root, 20);
    printf("In Order Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Deleting node 30\n");
    root = deleteNode(root, 30);
    printf("In Order Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Deleting node 50\n");
    root = deleteNode(root, 50);
    printf("In Order Traversal after deletion: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}