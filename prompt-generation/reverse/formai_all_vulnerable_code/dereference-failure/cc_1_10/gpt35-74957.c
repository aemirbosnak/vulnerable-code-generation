//FormAI DATASET v1.0 Category: Binary search trees ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }
    if (value < (*root)->data) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int input;
    char choice;
    
    do {
        printf("Enter a number: ");
        scanf("%d", &input);
        insert(&root, input);
        printf("Do you want to enter another number? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Inorder traversal of the binary search tree:\n");
    inorderTraversal(root);

    return 0;
}