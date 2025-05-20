//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int key, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = key;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(struct node** root, int key, int data) {
    if (*root == NULL) {
        *root = createNode(key, data);
        return;
    }

    if (key < (*root)->key)
        insertNode(&(*root)->left, key, data);
    else if (key > (*root)->key)
        insertNode(&(*root)->right, key, data);
    else 
        printf("Error: Duplicate key\n");
}

void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("(%d,%d) ", root->key, root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, key, data;

    do {
        printf("\n1. Insert node\n");
        printf("2. In-order traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter key: ");
                scanf("%d", &key);
                printf("Enter data: ");
                scanf("%d", &data);
                insertNode(&root, key, data);
                break;
            case 2:
                printf("\nIn-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 3);

    return 0;
}