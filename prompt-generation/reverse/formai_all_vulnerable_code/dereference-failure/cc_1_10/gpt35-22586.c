//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        printf("Node value %d added to the tree.\n", value);
    } else if (value < (*root)->value) {
        insertNode(&(*root)->left, value);
    } else {
        insertNode(&(*root)->right, value);
    }
}

void searchNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Node value %d not found in the tree.\n", value);
    } else if (root->value == value) {
        printf("Node value %d found in the tree.\n", value);
    } else if (value < root->value) {
        searchNode(root->left, value);
    } else {
        searchNode(root->right, value);
    }
}

void printInorder(struct Node* root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("%d ", root->value);
        printInorder(root->right);
    }
}

int main() {
    struct Node* tree = NULL;
    int choice, value;
    do {
        printf("\nCYBERTREE:\n");
        printf("1) Add node\n");
        printf("2) Search node\n");
        printf("3) Print inorder\n");
        printf("0) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter node value: ");
                scanf("%d", &value);
                insertNode(&tree, value);
                break;
            case 2:
                printf("Enter node value: ");
                scanf("%d", &value);
                searchNode(tree, value);
                break;
            case 3:
                printf("Inorder traversal: ");
                printInorder(tree);
                printf("\n");
                break;
            case 0:
                printf("Exiting cybertree...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}