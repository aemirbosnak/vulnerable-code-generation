//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* delete(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = delete(root->left, key);
    else if (key > root->key)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = delete(root->right, temp->key);
    }
    return root;
}

void printTree(Node* node, int space) {
    if (node == NULL)
        return;

    space += 10;

    printTree(node->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", node->key);

    printTree(node->left, space);
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Binary Search Tree:\n");
    printTree(root, 0);

    root = delete(root, 20);
    printf("\nDelete 20: Binary Search Tree after deleting 20\n");
    printTree(root, 0);

    root = delete(root, 30);
    printf("\nDelete 30: Binary Search Tree after deleting 30\n");
    printTree(root, 0);

    root = delete(root, 50);
    printf("\nDelete 50: Binary Search Tree after deleting 50\n");
    printTree(root, 0);

    return 0;
}