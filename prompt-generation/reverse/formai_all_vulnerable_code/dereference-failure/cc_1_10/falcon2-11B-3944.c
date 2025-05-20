//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>

#define MAX_SIZE 10

struct node {
    int data;
    struct node *left, *right;
};

void insert(struct node **root, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    struct node *current = *root;
    while (1) {
        if (data < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
    }
}

void printInorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct node *root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal of binary search tree:\n");
    printInorder(root);

    return 0;
}