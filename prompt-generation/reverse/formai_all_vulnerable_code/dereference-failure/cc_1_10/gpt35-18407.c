//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *createNode(int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = value;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    } else if (value < root -> data) {
        root -> left = insertNode(root -> left, value);
    } else if (value > root -> data) {
        root -> right = insertNode(root -> right, value);
    }
    return root;
}

void inOrderTraversal(Node *root) {
    if (root != NULL) {
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
}

Node *searchNode(Node *root, int value) {
    if (root == NULL || root -> data == value) {
        return root;
    } else if (value < root -> data) {
        return searchNode(root -> left, value);
    } else {
        return searchNode(root -> right, value);
    }
}

Node *findMinValue(Node *root) {
    Node *current = root;
    while (current -> left != NULL) {
        current = current -> left;
    }
    return current;
}

Node *deleteNode(Node *root, int value) {
    if (root == NULL) {
        return root;
    } else if (value < root -> data) {
        root -> left = deleteNode(root -> left, value);
    } else if (value > root -> data) {
        root -> right = deleteNode(root -> right, value);
    } else {
        if (root -> left == NULL) {
            Node *temp = root -> right;
            free(root);
            return temp;
        } else if (root -> right == NULL) {
            Node *temp = root -> left;
            free(root);
            return temp;
        }
        Node *temp = findMinValue(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

int main() {
    Node *root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);

    printf("In-order traversal of the BST: ");
    inOrderTraversal(root);
    printf("\n");

    int value = 40;
    if (searchNode(root, value) != NULL) {
        printf("%d Found in the BST\n", value);
    } else {
        printf("%d Not Found in the BST\n", value);
    }

    value = 70;
    printf("Deleting %d Node from the BST\n", value);
    root = deleteNode(root, value);

    printf("In-order traversal after deleting %d Node: ", value);
    inOrderTraversal(root);
    printf("\n");

    return 0;
}