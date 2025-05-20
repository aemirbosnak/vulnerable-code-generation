//FormAI DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct Node** tree, int value) {
    if (*tree == NULL) {
        *tree = createNode(value);
    } else if (value <= (*tree)->data) {
        insertNode(&(*tree)->left, value);
    } else {
        insertNode(&(*tree)->right, value);
    }
}

void printInOrder(struct Node* tree) {
    if (tree != NULL) {
        printInOrder(tree->left);
        printf("%d ", tree->data);
        printInOrder(tree->right);
    }
}

void printPreOrder(struct Node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void printPostOrder(struct Node* tree) {
    if (tree != NULL) {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        printf("%d ", tree->data);
    }
}

int search(struct Node* tree, int value) {
    if (tree == NULL) {
        return 0;
    } else if (tree->data == value) {
        return 1;
    } else if (value <= tree->data) {
        return search(tree->left, value);
    } else {
        return search(tree->right, value);
    }
}

int main() {
    printf("Welcome to the Binary Search Tree!\n");
    printf("Enter how many elements you want to add: ");
    int n;
    scanf("%d", &n);
    struct Node* tree = NULL;
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertNode(&tree, value);
    }
    printf("\nIn-order traversal: ");
    printInOrder(tree);
    printf("\nPre-order traversal: ");
    printPreOrder(tree);
    printf("\nPost-order traversal: ");
    printPostOrder(tree);
    printf("\nEnter a value to search for: ");
    int searchValue;
    scanf("%d", &searchValue);
    if (search(tree, searchValue)) {
        printf("%d is in the tree!\n", searchValue);
    } else {
        printf("%d is not in the tree.\n", searchValue);
    }
    return 0;
}