//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

struct node* insert(struct node* node, int data) {
    if (node == NULL)
        return (newNode(data));
    else if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    return (node);
}

void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

struct node* search(struct node* node, int data) {
    if (node == NULL || node->data == data)
        return node;
    else if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}

void deleteTree(struct node* node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        free(node);
    }
}

int main() {
    struct node* root = NULL;
    int option;
    int input;

    printf("Welcome to the Binary Search Tree program\n");

    while (1) {
        printf("\nEnter 1 - Insert 2 - Inorder Traversal 3 - Search 4 - Exit : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &input);
                root = insert(root, input);
                printf("%d has been inserted successfully\n", input);
                break;
            case 2:
                printf("Inorder Traversal:\n");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Enter a number to search: ");
                scanf("%d", &input);
                if (search(root, input) == NULL)
                    printf("%d was not found\n", input);
                else
                    printf("%d was found\n", input);
                break;
            case 4:
                deleteTree(root);
                printf("Thank you for using the Binary Search Tree program\n");
                exit(0);
            default:
                printf("Please select a valid option\n");
        }
    }

    return 0;
}