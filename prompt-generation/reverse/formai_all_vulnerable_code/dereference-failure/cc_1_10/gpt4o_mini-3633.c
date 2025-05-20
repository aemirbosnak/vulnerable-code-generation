//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
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

void printTree(Node* root, int space) {
    if (root == NULL)
        return;

    space += 10; // Increase space between levels

    printTree(root->right, space); // Right subtree

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" "); // Indentation
    printf("%d\n", root->data); // Print the node

    printTree(root->left, space); // Left subtree
}

void freeTree(Node* node) {
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    Node* root = NULL;
    int data;
    char choice;

    printf("=== Binary Tree Visualization ===\n");
    
    do {
        printf("Enter a number to insert into the tree: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\n=== Visual Representation of the Tree ===\n");
    printTree(root, 0);

    freeTree(root);
    return 0;
}