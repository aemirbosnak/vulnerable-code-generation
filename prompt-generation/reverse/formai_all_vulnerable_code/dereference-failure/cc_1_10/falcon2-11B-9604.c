//Falcon2-11B DATASET v1.0 Category: Binary search trees ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = (struct node *)malloc(sizeof(struct node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (data < (*root)->data) {
            if ((*root)->left == NULL) {
                (*root)->left = (struct node *)malloc(sizeof(struct node));
                (*root)->left->data = data;
                (*root)->left->left = NULL;
                (*root)->left->right = NULL;
            } else {
                insert(&((*root)->left), data);
            }
        } else {
            if ((*root)->right == NULL) {
                (*root)->right = (struct node *)malloc(sizeof(struct node));
                (*root)->right->data = data;
                (*root)->right->left = NULL;
                (*root)->right->right = NULL;
            } else {
                insert(&((*root)->right), data);
            }
        }
    }
}

void inorder(struct node *root) {
    if (root!= NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int choice, data;

    do {
        printf("\n1. Insert a node\n2. Inorder traversal\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the data: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                if (root == NULL) {
                    printf("The tree is empty\n");
                } else {
                    inorder(root);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}