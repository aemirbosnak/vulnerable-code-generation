//MISTRAL-7B DATASET v1.0 Category: Binary search trees ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODE_NAME_LENGTH 50
#define MAX_TREE_DEPTH 10

typedef struct Node {
    char name[MAX_NODE_NAME_LENGTH + 1];
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(const char* name, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void printNode(Node* node, int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("    ");
    }

    printf("- %s (%.2f)\n", node->name, node->value / 10.0);

    if (node->left != NULL) {
        printNode(node->left, depth + 1);
    }

    if (node->right != NULL) {
        printNode(node->right, depth + 1);
    }
}

Node* insertNode(Node* root, const char* name, int value) {
    if (root == NULL) {
        return createNode(name, value);
    }

    int cmpResult = strcmp(name, root->name);
    if (cmpResult < 0) {
        root->left = insertNode(root->left, name, value);
    } else if (cmpResult > 0) {
        root->right = insertNode(root->right, name, value);
    } else {
        root->value += value;
    }

    return root;
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

    // User input for tree configuration
    char input[100];
    int sumValue = 0;

    printf("Configure your binary search tree by entering nodes as \"Name Value\", e.g. \"Apple 5\"\n");
    printf("Enter an empty line to finish.\n");

    while (fgets(input, sizeof(input), stdin) != NULL && sumValue < 1000) {
        input[strcspn(input, "\n")] = '\0';
        char* name = strtok(input, " ");
        int value = atoi(strtok(NULL, " "));

        if (name != NULL && value > 0) {
            root = insertNode(root, name, value);
            sumValue += value;
        }
    }

    printf("\nYour binary search tree:\n");
    printNode(root, 0);

    freeTree(root);

    return 0;
}