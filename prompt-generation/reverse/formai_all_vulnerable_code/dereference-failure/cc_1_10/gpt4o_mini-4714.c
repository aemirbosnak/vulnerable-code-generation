//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printTree(Node *root, int space) {
    if (root == NULL) {
        return;
    }

    space += 10; // Increase distance between levels

    printTree(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

void paranoidMode() {
    printf("==== PARANOID MODE ACTIVATED ====\n");
    printf("Every insertion is being watched...\n");
    printf("Be diligent! Be meticulous!\n");
    printf("You never know who might be on the lookout...\n");
    printf("=================================\n");
}

void pressAnyKeyToContinue() {
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
}

int main() {
    Node *root = NULL;
    int choice, value;

    paranoidMode();

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert value into the BST\n");
        printf("2. Print the BST\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d has been inserted... watching closely...\n", value);
                pressAnyKeyToContinue();
                break;

            case 2:
                printf("Visualizing the BST...\n");
                printTree(root, 0);
                pressAnyKeyToContinue();
                break;

            case 3:
                printf("Exiting paranoid mode...\n");
                exit(0);
                break;

            default:
                printf("Invalid option! Stay sharp...\n");
                pressAnyKeyToContinue();
                break;
        }
    }

    return 0;
}