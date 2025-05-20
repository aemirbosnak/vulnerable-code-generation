//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }

    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void printTree(Node* root, int space) {
    if (root == NULL) return;

    space += 10; // Increase distance between levels

    printTree(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++) printf(" ");
    printf("%d\n", root->value);

    printTree(root->left, space);
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int value;
    char choice;

    while (1) {
        printf("Enter a number to insert into the BST (or 'q' to quit): ");
        if (scanf("%d", &value) == 1) {
            root = insert(root, value);
            printf("Current in-order traversal: ");
            inOrder(root);
            printf("\nCurrent BST visualization:\n");
            printTree(root, 0);
        } else {
            scanf("%c", &choice);
            if (choice == 'q' || choice == 'Q') {
                break;
            } else {
                printf("Invalid input. Please enter a number or 'q' to quit.\n");
                // Clear invalid input
                while (getchar() != '\n');
            }
        }
    }

    freeTree(root);
    return 0;
}