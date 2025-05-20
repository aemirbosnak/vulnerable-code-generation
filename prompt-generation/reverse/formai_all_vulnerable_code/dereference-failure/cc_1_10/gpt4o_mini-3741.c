//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
    } else {
        if (value < (*root)->value) {
            insert(&((*root)->left), value);
        } else {
            insert(&((*root)->right), value);
        }
    }
}

void printTree(Node* root, int space) {
    const int COUNT = 10;
    if (root == NULL) return;

    space += COUNT;

    printTree(root->right, space);
    
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->value);
    
    printTree(root->left, space);
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("Binary Tree Visualization:\n");
        printf("1. Insert a node\n");
        printf("2. Display tree\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&root, value);
                break;
            case 2:
                printf("Tree structure:\n");
                printTree(root, 0);
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    freeTree(root);
    
    return 0;
}