//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return createNode(value);
    }
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    }
    return node;
}

void printTree(Node* node, int space) {
    if (node == NULL) return;

    space += 10; // Increase distance between levels

    printTree(node->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", node->value);
    printTree(node->left, space);
}

void freeTree(Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert\n");
        printf("2. Visualize BST\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("\nBinary Search Tree Visualization:\n");
                printTree(root, 0);
                printf("\n");
                break;
            case 3:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}