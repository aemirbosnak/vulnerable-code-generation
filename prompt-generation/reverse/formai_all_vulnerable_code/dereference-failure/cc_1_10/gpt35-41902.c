//FormAI DATASET v1.0 Category: Binary search trees ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node** root, int value) {
    if (*root == NULL) {
        *root = newNode(value);
    } else {
        if ((*root)->value > value) {
            insert(&(*root)->left, value);
        } else if ((*root)->value < value) {
            insert(&(*root)->right, value);
        } else {
            printf("Duplicate value ignored.\n");
        }
    }
}

void printInorder(struct Node* node) {
    if (node != NULL) {
        printInorder(node->left);
        printf("%d ", node->value);
        printInorder(node->right);
    }
}

int main() {
    struct Node* root = NULL;
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    printf("Inorder traversal of the binary search tree: ");
    printInorder(root);
    printf("\n");
    return 0;
}