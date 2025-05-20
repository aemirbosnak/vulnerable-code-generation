//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int count;
    struct node *left;
    struct node *right;
} node;

node *create_node(char *data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node *insert_node(node *root, char *data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (strcmp(root->data, data) == 0) {
        root->count++;
        return root;
    }
    if (strcmp(data, root->data) < 0) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

void inorder_traversal(node *root) {
    if (root!= NULL) {
        inorder_traversal(root->left);
        printf("%s (%d)\n", root->data, root->count);
        inorder_traversal(root->right);
    }
}

void delete_node(node *root, char *data) {
    if (root == NULL) {
        return;
    }
    if (strcmp(root->data, data) == 0) {
        if (root->count == 1) {
            free(root->data);
            free(root);
            root = NULL;
        } else {
            root->count--;
        }
        return;
    }
    if (strcmp(data, root->data) < 0) {
        delete_node(root->left, data);
    } else {
        delete_node(root->right, data);
    }
}

int main() {
    node *root = NULL;
    char input[MAX_SIZE];
    int choice;

    while (1) {
        printf("1. Insert\n2. Delete\n3. Inorder Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the data: ");
            scanf("%s", input);
            root = insert_node(root, input);
            break;
        case 2:
            printf("Enter the data to delete: ");
            scanf("%s", input);
            delete_node(root, input);
            break;
        case 3:
            printf("Inorder Traversal:\n");
            inorder_traversal(root);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}