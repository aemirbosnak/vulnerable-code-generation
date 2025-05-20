//GPT-4o-mini DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_LEVEL 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    int level;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(const char* name, int level) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    newNode->level = level;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, const char* name, int level) {
    if (root == NULL) {
        return createNode(name, level);
    }
    if (level < root->level) {
        root->left = insertNode(root->left, name, level);
    } else if (level > root->level) {
        root->right = insertNode(root->right, name, level);
    }
    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int level) {
    if (root == NULL) {
        return root;
    }
    if (level < root->level) {
        root->left = deleteNode(root->left, level);
    } else if (level > root->level) {
        root->right = deleteNode(root->right, level);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = findMin(root->right);
        strncpy(root->name, temp->name, MAX_NAME_LENGTH);
        root->level = temp->level;
        root->right = deleteNode(root->right, temp->level);
    }
    return root;
}

void displayTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }
    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("[%s: %d]\n", root->name, root->level);
    displayTree(root->left, level + 1);
}

void searchNode(Node* root, int level) {
    if (root == NULL) {
        printf("No hacker found at level %d.\n", level);
        return;
    }
    if (level < root->level) {
        searchNode(root->left, level);
    } else if (level > root->level) {
        searchNode(root->right, level);
    } else {
        printf("Hacker found! Name: %s, Level: %d\n", root->name, root->level);
    }
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
    int choice, level;
    char name[MAX_NAME_LENGTH];

    printf("Welcome to the Cyberpunk Hacker Level Control System!\n");

    while (1) {
        printf("\n1. Add Hacker\n");
        printf("2. Remove Hacker\n");
        printf("3. Display Hackers\n");
        printf("4. Search Hacker\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Hacker Name: ");
                scanf("%s", name);
                printf("Enter Hacking Level (0 - %d): ", MAX_LEVEL);
                scanf("%d", &level);
                if (level < 0 || level > MAX_LEVEL) {
                    printf("Invalid level!\n");
                } else {
                    root = insertNode(root, name, level);
                    printf("Hacker %s added at level %d.\n", name, level);
                }
                break;

            case 2:
                printf("Enter Hacking Level to Remove: ");
                scanf("%d", &level);
                root = deleteNode(root, level);
                printf("Hacker at level %d removed if existed.\n", level);
                break;

            case 3:
                printf("Current Hackers in the System:\n");
                displayTree(root, 0);
                break;

            case 4:
                printf("Enter Hacking Level to Search: ");
                scanf("%d", &level);
                searchNode(root, level);
                break;

            case 5:
                freeTree(root);
                printf("Exiting... Stay cyber!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
}